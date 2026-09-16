#include "tg2_static_apu.h"
#include <cstdio>
#include <cstdint>
#include <cstdlib>
#include <vector>
#include <string>
#include <fstream>
#include <iterator>
#include <cstring>

struct Capture { std::vector<int16_t> pcm; uint8_t nonzero_volume_write_mask=0; uint8_t kon_touch_mask=0; uint8_t koff_touch_mask=0; };
struct Transfer { uint16_t dest; std::vector<uint8_t> data; };
static void sink(void *ctx,int16_t l,int16_t r){auto*c=(Capture*)ctx;c->pcm.push_back(l);c->pcm.push_back(r);}
static void dsp_trace(void *ctx,uint16_t,uint8_t address,uint8_t value){
 auto*c=(Capture*)ctx;
 if((address&0x0f)<=1 && (address>>4)<8 && value)c->nonzero_volume_write_mask|=(uint8_t)(1u<<(address>>4));
 if(address==0x4c)c->kon_touch_mask|=value;
 if(address==0x5c)c->koff_touch_mask|=value;
}
static bool load_file(const char*path,std::vector<uint8_t>&v){std::ifstream f(path,std::ios::binary);if(!f)return false;v.assign(std::istreambuf_iterator<char>(f),{});return true;}
static bool load_transfers(const char*path,std::vector<Transfer>&out){
 std::vector<uint8_t>b;if(!load_file(path,b)||b.size()<12||std::memcmp(b.data(),"TG2XFER1",8)!=0)return false;size_t p=8;uint32_t n=b[p]|(b[p+1]<<8)|(b[p+2]<<16)|(b[p+3]<<24);p+=4;
 for(uint32_t i=0;i<n;i++){if(p+6>b.size())return false;uint16_t d=b[p]|(b[p+1]<<8);uint32_t z=b[p+2]|(b[p+3]<<8)|(b[p+4]<<16)|(b[p+5]<<24);p+=6;if(p+z>b.size())return false;Transfer t{d,{}};t.data.assign(b.begin()+p,b.begin()+p+z);p+=z;out.push_back(std::move(t));}return p==b.size();
}
static bool sync_to(uint64_t &master,uint64_t delta){char e[256];master+=delta;if(!tg2_static_apu_sync_to_master(master,e,sizeof(e))){std::fprintf(stderr,"sync fail: %s\n",e);return false;}return true;}
static uint8_t readp(uint64_t master,unsigned p,bool *good=nullptr){char e[256];int ok=0;uint8_t v=tg2_static_apu_cpu_read_port(master,p,&ok,e,sizeof(e));if(good)*good=ok!=0;if(!ok)std::fprintf(stderr,"port read fail p%u: %s\n",p,e);return v;}
static bool writep(uint64_t master,unsigned p,uint8_t v){char e[256];if(!tg2_static_apu_cpu_write_port(master,p,v,e,sizeof(e))){std::fprintf(stderr,"port write fail p%u: %s\n",p,e);return false;}return true;}
static bool wait_port_eq(uint64_t &master,unsigned p,uint8_t want,uint64_t max_delta){uint64_t end=master+max_delta;while(master<end){bool ok=false;uint8_t v=readp(master,p,&ok);if(ok&&v==want)return true;if(!sync_to(master,128))return false;}std::fprintf(stderr,"timeout waiting p%u=%02X got=%02X at %llu\n",p,want,readp(master,p),(unsigned long long)master);return false;}
static bool wait_port_sign(uint64_t &master,bool high,uint64_t max_delta){uint64_t end=master+max_delta;while(master<end){bool ok=false;uint8_t v=readp(master,0,&ok);if(ok&&(((v&0x80)!=0)==high))return true;if(!sync_to(master,128))return false;}return false;}
static bool wait_ready77(uint64_t &master,uint64_t max_delta){uint64_t end=master+max_delta;while(master<end){bool ok=false;uint8_t v=readp(master,1,&ok);if(ok&&v==0x77)return true;if(!sync_to(master,512))return false;}return false;}
static bool send_group(uint64_t &master,uint8_t p1,uint8_t p2,uint8_t p3,uint8_t strobe){
 if(!writep(master,1,p1)||!writep(master,2,p2)||!writep(master,3,p3)||!writep(master,0,strobe))return false;
 if(!sync_to(master,128))return false;return wait_port_sign(master,(strobe&0x80)!=0,3000000);
}
static bool send_command(uint64_t &master,uint8_t p1,uint8_t p2,uint8_t selector){
 if(!wait_ready77(master,12000000)){SCStaticApuStatus st{};tg2_static_apu_status(&st);std::fprintf(stderr,"driver never ready77 pc=%04X aot=%llu fail=%u reason=%u master=%llu\n",st.smp_pc,(unsigned long long)st.aot_validated_instructions,st.aot_failed,st.aot_fail_reason,(unsigned long long)master);return false;}
 if(!send_group(master,p1,p2,selector,0x81))return false;
 if(!send_group(master,0,0,0,0x00))return false;
 if(!send_group(master,0,0,0,0x80))return false;
 if(!send_group(master,0,0,0,0x00))return false;
 return true;
}
static bool runtime_service(uint64_t &master){
 if(!wait_ready77(master,12000000))return false;
 if(!send_group(master,0xff,0xff,0xff,0x80))return false;
 if(!send_group(master,0,0,0,0x00))return false;
 if(!send_group(master,0,0,0,0x80))return false;
 if(!send_group(master,0,0,0,0x00))return false;
 return true;
}
static bool send_u16_ports01(uint64_t m,uint16_t v){return writep(m,0,(uint8_t)v)&&writep(m,1,(uint8_t)(v>>8));}
static bool upload_one(uint64_t &master,const Transfer&t){
 // Exact Top Gear 2 $9F:F28F/$9F:F423 transport: AB request, CD ready,
 // toggled port-3 acknowledgements, length, destination, 3-byte payload groups, BC completion.
 if(!writep(master,3,0xAB))return false;
 if(!sync_to(master,128))return false;
 if(!wait_port_eq(master,3,0xCD,6000000))return false;
 uint8_t ack=0x00;
 if(t.data.empty()||t.data.size()>0xffffu){std::fprintf(stderr,"invalid transfer size %zu\n",t.data.size());return false;}
 if(!send_u16_ports01(master,(uint16_t)t.data.size()))return false;
 ack^=0xff;if(!writep(master,3,ack))return false;if(!sync_to(master,128)||!wait_port_eq(master,3,ack,3000000))return false;
 if(!send_u16_ports01(master,t.dest))return false;
 ack^=0xff;if(!writep(master,3,ack))return false;if(!sync_to(master,128)||!wait_port_eq(master,3,ack,3000000))return false;
 size_t i=0;
 while(i<t.data.size()){
   if(!writep(master,0,t.data[i++]))return false;
   if(i<t.data.size()&&!writep(master,1,t.data[i++]))return false;
   if(i<t.data.size()&&!writep(master,2,t.data[i++]))return false;
   ack^=0xff;if(!writep(master,3,ack))return false;
   if(!sync_to(master,64)||!wait_port_eq(master,3,ack,3000000))return false;
 }
 // zero-length terminator + BC close, matching the original routine.
 if(!send_u16_ports01(master,0))return false;
 ack^=0xff;if(!writep(master,3,ack))return false;
 if(!sync_to(master,128)||!wait_port_eq(master,3,0xBC,3000000))return false;
 if(!writep(master,3,0xBC))return false;
 if(!sync_to(master,128)||!wait_port_eq(master,3,0x00,3000000))return false;
 if(!send_u16_ports01(master,0))return false;
 if(!writep(master,2,0)||!writep(master,3,0))return false;
 if(!sync_to(master,128))return false;
 return true;
}
static bool load_package(uint64_t &master,uint8_t p1,uint8_t p2,uint8_t selector,const std::vector<Transfer>&xfers){
 if(xfers.empty())return false;
 if(!send_command(master,p1,p2,selector))return false;
 for(size_t i=0;i<xfers.size();++i){
   if(!upload_one(master,xfers[i])){std::fprintf(stderr,"upload failed at transfer %zu dest=%04X bytes=%zu\n",i,xfers[i].dest,xfers[i].data.size());return false;}
   if(i+1<xfers.size()&&!send_command(master,p1,p2,0xff)){std::fprintf(stderr,"continuation command failed after transfer %zu\n",i);return false;}
 }
 return true;
}

static bool sync_until(uint64_t &master,uint64_t target){
 if(master>target){std::fprintf(stderr,"timing overrun: master=%llu target=%llu delta=%lld\n",(unsigned long long)master,(unsigned long long)target,(long long)(master-target));return false;}
 while(master<target){uint64_t d=target-master;if(d>200000)d=200000;if(!sync_to(master,d))return false;}return true;
}
static bool load_package_timed(uint64_t &master,uint8_t p1,uint8_t p2,uint8_t selector,const std::vector<Transfer>&xfers,const uint64_t*starts,size_t nstarts){
 if(xfers.empty()||nstarts<xfers.size())return false;
 for(size_t i=0;i<xfers.size();++i){
   if(!sync_until(master,starts[i]))return false;
   if(!send_command(master,p1,p2,i==0?selector:0xff)){std::fprintf(stderr,"timed command failed at transfer %zu\n",i);return false;}
   uint64_t before=master;
   if(!upload_one(master,xfers[i])){std::fprintf(stderr,"timed upload failed at transfer %zu dest=%04X bytes=%zu\n",i,xfers[i].dest,xfers[i].data.size());return false;}
   std::fprintf(stderr,"XFER i=%zu cmd_target=%llu upload_start=%llu upload_end=%llu bytes=%zu\n",i,(unsigned long long)starts[i],(unsigned long long)before,(unsigned long long)master,xfers[i].data.size());
 }
 return true;
}
static bool run_service_window(uint64_t &master,uint64_t clocks,uint64_t &nextService){
 const uint64_t frameClocks=357366;
 uint64_t target=master+clocks;
 while(master<target){
   uint64_t next=(nextService<target)?nextService:target;
   if(!sync_until(master,next))return false;
   if(master==nextService){if(!runtime_service(master))return false;nextService+=frameClocks;}
 }
 return true;
}

// Natural Top Gear 2 CPU $9F:F180 entry times, normalized so master 0 is the
// first execution of the uploaded SPC driver at $0810 (Mesen: 4,702,276).
static const uint64_t kBootStarts[18]={
 11823166,13561416,17866658,18115726,19145956,20430376,22078510,23299930,24393308,26672742,28086236,33654196,34685342,36854556,38430802,39581284,40717144,42437170};
static const uint64_t kTitleStarts[18]={
 122248318,123986142,128293504,128542364,129571826,130856450,132504582,133726086,134819134,137098874,138512218,144080544,145111204,147280430,148857024,150007248,151143180,152862954};
int main(int argc,char**argv){
 if(argc<7){std::fprintf(stderr,"usage: tg2-audio-lab seed.bin boot0-transfer.bin track-transfer.bin selector seconds output.raw [--snapshot-check]\n");return 2;}
 std::vector<uint8_t> image;std::vector<Transfer>bootxfers,xfers;if(!load_file(argv[1],image)||image.size()!=65536||!load_transfers(argv[2],bootxfers)||!load_transfers(argv[3],xfers)){std::fprintf(stderr,"bad seed/transfer input\n");return 2;}
 int selector=std::strtol(argv[4],nullptr,0);double seconds=std::atof(argv[5]);
 char e[256];if(!tg2_static_apu_acquire(e,sizeof(e))){std::fprintf(stderr,"acquire: %s\n",e);return 3;}
 Capture cap;tg2_static_apu_set_sink(sink,&cap); SCStaticTraceCallbacks traces{}; traces.dsp_write=dsp_trace; traces.context=&cap; tg2_static_apu_set_trace_callbacks(&traces);
 if(!tg2_static_apu_lab_seed_tg2(image.data(),image.size(),25)){std::fprintf(stderr,"seed failed\n");return 3;}
 uint64_t master=0;
 if(bootxfers.size()!=18){std::fprintf(stderr,"expected 18 boot transfers, got %zu\n",bootxfers.size());return 4;}
 if(!load_package_timed(master,0x00,0x00,0x00,bootxfers,kBootStarts,18))return 4;
 /* Natural title reload begins much later, after the game-side intro delay. */
 if(std::string(argv[3]).find("tg2-package-0-transfer.bin")!=std::string::npos){
   if(!load_package_timed(master,0xff,0xff,(uint8_t)selector,xfers,kTitleStarts,18))return 4;
 } else {
   /* Non-title packages are first aligned to the natural title-load epoch. Their
      package-specific CPU decompression timing will be separately certified. */
   if(!sync_until(master,kTitleStarts[0]))return 4;
   if(!load_package(master,0xff,0xff,(uint8_t)selector,xfers))return 4;
 }
 cap.pcm.clear(); /* listening/comparison window starts after the real package transaction */
 const uint64_t frameClocks=357366;
 uint64_t nextService=master+frameClocks;
 if(argc>=8 && std::string(argv[7])=="--snapshot-check"){
   /* Warm into genuinely playing state, then require restore/replay to produce the exact
      same subsequent PCM and status. Host-side master/service schedule is rewound too. */
   if(!run_service_window(master,(uint64_t)(21477270.0*2.0),nextService))return 5;
   size_t snapSize=tg2_static_apu_snapshot_size(); std::vector<uint8_t> snap(snapSize),snap2(snapSize);
   if(!snapSize||!tg2_static_apu_snapshot_save(snap.data(),snap.size())){std::fprintf(stderr,"playing snapshot save failed\n");return 7;}
   uint64_t savedMaster=master,savedNextService=nextService;
   cap.pcm.clear();
   if(!run_service_window(master,(uint64_t)(21477270.0*1.0),nextService))return 5;
   std::vector<int16_t> first=cap.pcm; SCStaticApuStatus firstStatus{}; tg2_static_apu_status(&firstStatus);
   if(!tg2_static_apu_snapshot_load(snap.data(),snap.size(),e,sizeof(e))){std::fprintf(stderr,"playing snapshot load failed: %s\n",e);return 7;}
   if(!tg2_static_apu_snapshot_save(snap2.data(),snap2.size())||snap!=snap2){std::fprintf(stderr,"playing snapshot bytes not stable after reload\n");return 7;}
   master=savedMaster; nextService=savedNextService; cap.pcm.clear();
   if(!run_service_window(master,(uint64_t)(21477270.0*1.0),nextService))return 5;
   SCStaticApuStatus secondStatus{}; tg2_static_apu_status(&secondStatus);
   bool statusSame=firstStatus.synchronized_master_clock==secondStatus.synchronized_master_clock &&
      firstStatus.smp_cycles==secondStatus.smp_cycles && firstStatus.smp_instructions==secondStatus.smp_instructions &&
      firstStatus.aot_validated_instructions==secondStatus.aot_validated_instructions && firstStatus.pcm_frames==secondStatus.pcm_frames &&
      firstStatus.pcm_known_frames==secondStatus.pcm_known_frames && firstStatus.pcm_unknown_frames==secondStatus.pcm_unknown_frames &&
      firstStatus.pcm_hash==secondStatus.pcm_hash && firstStatus.pcm_overflows==secondStatus.pcm_overflows &&
      firstStatus.smp_pc==secondStatus.smp_pc && firstStatus.smp_a==secondStatus.smp_a && firstStatus.smp_x==secondStatus.smp_x &&
      firstStatus.smp_y==secondStatus.smp_y && firstStatus.smp_sp==secondStatus.smp_sp && firstStatus.smp_psw==secondStatus.smp_psw &&
      firstStatus.aot_failed==secondStatus.aot_failed && firstStatus.sdsp_static_failed==secondStatus.sdsp_static_failed &&
      firstStatus.rendezvous_hash==secondStatus.rendezvous_hash && firstStatus.cpu_port_event_hash==secondStatus.cpu_port_event_hash;
   if(first!=cap.pcm || !statusSame){std::fprintf(stderr,"playing snapshot replay mismatch pcm=%d status=%d\n",first==cap.pcm,statusSame);return 7;}
   size_t nz=0;for(auto v:first)if(v)++nz;
   std::printf("TG2_PLAYING_SNAPSHOT PASS selector=%d snapshot_bytes=%zu replay_frames=%zu replay_nonzero=%zu pcm_identical=1 status_identical=1\n",selector,snapSize,first.size()/2,nz);
   tg2_static_apu_release(); return nz?0:7;
 }
 if(!run_service_window(master,(uint64_t)(21477270.0*seconds),nextService))return 5;
 SCStaticApuStatus st{};tg2_static_apu_status(&st);
 uint8_t regs[22]={0};const uint8_t addrs[22]={0x4c,0x5c,0x6c,0x0c,0x1c,0x00,0x01,0x10,0x11,0x20,0x21,0x30,0x31,0x40,0x41,0x50,0x51,0x60,0x61,0x70,0x71,0x5d};for(int i=0;i<22;++i)tg2_static_apu_read_dsp_register(addrs[i],&regs[i]);
 std::fprintf(stderr,"DSPDBG KON=%02X KOFF=%02X FLG=%02X MV=%02X/%02X V0=%02X/%02X V1=%02X/%02X V2=%02X/%02X V3=%02X/%02X V4=%02X/%02X V5=%02X/%02X V6=%02X/%02X V7=%02X/%02X DIR=%02X\n",regs[0],regs[1],regs[2],regs[3],regs[4],regs[5],regs[6],regs[7],regs[8],regs[9],regs[10],regs[11],regs[12],regs[13],regs[14],regs[15],regs[16],regs[17],regs[18],regs[19],regs[20],regs[21]);
 std::ofstream out(argv[6],std::ios::binary);out.write((const char*)cap.pcm.data(),(std::streamsize)(cap.pcm.size()*sizeof(int16_t))); std::vector<uint8_t> aram(65536); tg2_static_apu_read_aram(0,aram.data(),aram.size()); std::ofstream ao(std::string(argv[6])+".aram",std::ios::binary); ao.write((const char*)aram.data(),aram.size());
 size_t nonzero=0;for(auto v:cap.pcm)if(v)++nonzero;
 std::printf("TG2_LAB selector=%d seconds=%.3f transfers=%zu samples=%zu frames=%zu nonzero=%zu pc=%04X aot=%llu aot_fail=%u dsp_fail=%u unknown_pcm=%llu overflow=%llu port_events=%llu pcm_hash=%016llX volume_write_mask=%02X kon_touch_mask=%02X koff_touch_mask=%02X\n",selector,seconds,xfers.size(),cap.pcm.size(),cap.pcm.size()/2,nonzero,st.smp_pc,(unsigned long long)st.aot_validated_instructions,st.aot_failed,st.sdsp_static_failed,(unsigned long long)st.pcm_unknown_frames,(unsigned long long)st.pcm_overflows,(unsigned long long)st.cpu_port_event_count,(unsigned long long)st.pcm_hash,cap.nonzero_volume_write_mask,cap.kon_touch_mask,cap.koff_touch_mask);
 tg2_static_apu_release();return (st.aot_failed||st.sdsp_static_failed||st.pcm_unknown_frames||st.pcm_overflows||nonzero==0)?6:0;
}
