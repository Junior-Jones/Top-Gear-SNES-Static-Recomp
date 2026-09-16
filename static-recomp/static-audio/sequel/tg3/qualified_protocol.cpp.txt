#include "tg3_static_apu.h"
#include <cstdio>
#include <cstdint>
#include <cstdlib>
#include <vector>
#include <string>
#include <fstream>
#include <iterator>
#include <cstring>

struct Capture { std::vector<int16_t> pcm; uint8_t nonzero_volume_write_mask=0; uint8_t kon_touch_mask=0; uint8_t koff_touch_mask=0; uint8_t eon_mask=0; uint8_t pmon_mask=0; uint8_t non_mask=0; };
struct Transfer { uint16_t dest; std::vector<uint8_t> data; };
static void sink(void *ctx,int16_t l,int16_t r){auto*c=(Capture*)ctx;c->pcm.push_back(l);c->pcm.push_back(r);}
static void dsp_trace(void *ctx,uint16_t,uint8_t address,uint8_t value){
 auto*c=(Capture*)ctx;
 if((address&0x0f)<=1 && (address>>4)<8 && value)c->nonzero_volume_write_mask|=(uint8_t)(1u<<(address>>4));
 if(address==0x4c)c->kon_touch_mask|=value;
 if(address==0x5c)c->koff_touch_mask|=value;
 if(address==0x4d)c->eon_mask|=value;
 if(address==0x2d)c->pmon_mask|=value;
 if(address==0x3d)c->non_mask|=value;
}
static bool load_file(const char*path,std::vector<uint8_t>&v){std::ifstream f(path,std::ios::binary);if(!f)return false;v.assign(std::istreambuf_iterator<char>(f),{});return true;}
static bool load_transfers(const char*path,std::vector<Transfer>&out){
 std::vector<uint8_t>b;if(!load_file(path,b)||b.size()<12||std::memcmp(b.data(),"TG3XFER1",8)!=0)return false;size_t p=8;uint32_t n=b[p]|(b[p+1]<<8)|(b[p+2]<<16)|(b[p+3]<<24);p+=4;
 for(uint32_t i=0;i<n;i++){if(p+6>b.size())return false;uint16_t d=b[p]|(b[p+1]<<8);uint32_t z=b[p+2]|(b[p+3]<<8)|(b[p+4]<<16)|(b[p+5]<<24);p+=6;if(p+z>b.size())return false;Transfer t{d,{}};t.data.assign(b.begin()+p,b.begin()+p+z);p+=z;out.push_back(std::move(t));}return p==b.size();
}
static bool sync_to(uint64_t &master,uint64_t delta){char e[256];master+=delta;if(!tg3_static_apu_sync_to_master(master,e,sizeof(e))){std::fprintf(stderr,"sync fail: %s\n",e);return false;}return true;}
static uint8_t readp(uint64_t master,unsigned p,bool *good=nullptr){char e[256];int ok=0;uint8_t v=tg3_static_apu_cpu_read_port(master,p,&ok,e,sizeof(e));if(good)*good=ok!=0;if(!ok)std::fprintf(stderr,"port read fail p%u: %s\n",p,e);return v;}
static bool writep(uint64_t master,unsigned p,uint8_t v){char e[256];if(!tg3_static_apu_cpu_write_port(master,p,v,e,sizeof(e))){std::fprintf(stderr,"port write fail p%u: %s\n",p,e);return false;}return true;}
static bool wait_port_eq(uint64_t &master,unsigned p,uint8_t want,uint64_t max_delta){uint64_t end=master+max_delta;while(master<end){bool ok=false;uint8_t v=readp(master,p,&ok);if(ok&&v==want)return true;if(!sync_to(master,128))return false;}SCStaticApuStatus st{};tg3_static_apu_status(&st);std::fprintf(stderr,"timeout p%u=%02X got=%02X pc=%04X fail=%u reason=%u at %llu\n",p,want,readp(master,p),st.smp_pc,st.aot_failed,st.aot_fail_reason,(unsigned long long)master);return false;}
static bool wait_port_sign(uint64_t &master,bool high,uint64_t max_delta){uint64_t end=master+max_delta;while(master<end){bool ok=false;uint8_t v=readp(master,0,&ok);if(ok&&(((v&0x80)!=0)==high))return true;if(!sync_to(master,128))return false;}return false;}
static bool wait_ready77(uint64_t &master,uint64_t max_delta){uint64_t end=master+max_delta;while(master<end){bool ok=false;uint8_t v=readp(master,1,&ok);if(ok&&v==0x77)return true;if(!sync_to(master,512))return false;}SCStaticApuStatus st{};tg3_static_apu_status(&st);std::fprintf(stderr,"driver never ready77 pc=%04X fail=%u reason=%u expected=%02X actual=%02X master=%llu\n",st.smp_pc,st.aot_failed,st.aot_fail_reason,st.expected_opcode,st.actual_opcode,(unsigned long long)master);return false;}
static bool send_group(uint64_t &master,uint8_t p1,uint8_t p2,uint8_t p3,uint8_t strobe){
 if(!writep(master,1,p1)||!writep(master,2,p2)||!writep(master,3,p3)||!writep(master,0,strobe))return false;
 if(!sync_to(master,128))return false;return wait_port_sign(master,(strobe&0x80)!=0,3000000);
}
/* Exact Top Gear 3000 bank-$86 pre-transfer command sequence. */
static bool send_transfer_command(uint64_t &master,uint8_t directoryPage){
 if(!wait_ready77(master,12000000))return false;
 if(!send_group(master,0,0,0xff,0x81))return false;
 /* The second command group's port-0 byte is the S-DSP source-directory page.
    Oracle proof: $40 for packages 0-2 and $20 for packages 3-6.  The resident
    driver stores this in DP $65 and writes it to DIR ($5D) at $09C7-$09CB. */
 if(!send_group(master,0,0,0x00,directoryPage))return false;
 if(!send_group(master,0,0,0x00,0x80))return false;
 if(!send_group(master,0,0,0x00,0x00))return false;
 return true;
}
static bool prepackage_service(uint64_t &master){
 if(!wait_ready77(master,12000000))return false;
 if(!send_group(master,0x00,0x00,0xff,0x80))return false;
 if(!send_group(master,0x00,0x00,0x00,0x00))return false;
 if(!send_group(master,0x00,0x00,0x00,0x80))return false;
 if(!send_group(master,0x00,0x00,0x00,0x00))return false;
 return true;
}
static bool start_loaded_song(uint64_t &master){
 if(!wait_ready77(master,12000000))return false;
 /* First natural service after the final title-package transfer (frame 368):
    p3=$01 is the one-shot song start. */
 if(!send_group(master,0x7f,0x7f,0x01,0x80))return false;
 if(!send_group(master,0x00,0x7f,0x00,0x40))return false;
 if(!send_group(master,0x00,0x00,0x00,0x80))return false;
 if(!send_group(master,0x00,0x00,0x00,0x00))return false;
 return true;
}
/* Exact periodic bank-$86 audio service observed after resident initialization. */
static bool runtime_service(uint64_t &master){
 if(!wait_ready77(master,12000000))return false;
 /* Natural post-package bank-$86 service: $7F/$7F carries the settled music
    level while $FF marks the active song service command. */
 if(!send_group(master,0x7f,0x7f,0xff,0x80))return false;
 if(!send_group(master,0x00,0x7f,0x00,0x40))return false;
 if(!send_group(master,0x00,0x00,0x00,0x80))return false;
 if(!send_group(master,0x00,0x00,0x00,0x00))return false;
 return true;
}
static bool send_u16_ports01(uint64_t m,uint16_t v){return writep(m,0,(uint8_t)v)&&writep(m,1,(uint8_t)(v>>8));}
static bool upload_one(uint64_t &master,const Transfer&t){
 if(!writep(master,3,0xAB))return false;
 if(!sync_to(master,128)||!wait_port_eq(master,3,0xCD,6000000))return false;
 uint8_t ack=0x00;
 if(t.data.empty()||t.data.size()>0xffffu){std::fprintf(stderr,"invalid transfer size %zu\n",t.data.size());return false;}
 if(!send_u16_ports01(master,(uint16_t)t.data.size()))return false;
 ack^=0xff;if(!writep(master,3,ack)||!sync_to(master,128)||!wait_port_eq(master,3,ack,3000000))return false;
 if(!send_u16_ports01(master,t.dest))return false;
 ack^=0xff;if(!writep(master,3,ack)||!sync_to(master,128)||!wait_port_eq(master,3,ack,3000000))return false;
 size_t i=0;
 while(i<t.data.size()){
   if(!writep(master,0,t.data[i++]))return false;
   if(i<t.data.size()&&!writep(master,1,t.data[i++]))return false;
   if(i<t.data.size()&&!writep(master,2,t.data[i++]))return false;
   ack^=0xff;if(!writep(master,3,ack))return false;
   if(!sync_to(master,64)||!wait_port_eq(master,3,ack,3000000))return false;
 }
 if(!send_u16_ports01(master,0))return false;
 ack^=0xff;if(!writep(master,3,ack))return false;
 if(!sync_to(master,128)||!wait_port_eq(master,3,0xBC,3000000))return false;
 if(!writep(master,3,0xBC))return false;
 if(!sync_to(master,128)||!wait_port_eq(master,3,0x00,3000000))return false;
 if(!send_u16_ports01(master,0)||!writep(master,2,0)||!writep(master,3,0)||!sync_to(master,128))return false;
 return true;
}
static bool load_package(uint64_t &master,const std::vector<Transfer>&xfers){
 if(xfers.empty())return false;
 uint8_t directoryPage=0;
 /* The payload builder deliberately writes the package source-directory transfer last. */
 if(xfers.back().dest==0x4000)directoryPage=0x40;
 else if(xfers.back().dest==0x2000)directoryPage=0x20;
 else {std::fprintf(stderr,"unrecognized package directory transfer dest=%04X\n",xfers.back().dest);return false;}
 for(size_t i=0;i<xfers.size();++i){
   if(!send_transfer_command(master,directoryPage)){std::fprintf(stderr,"transfer command failed at %zu\n",i);return false;}
   if(!upload_one(master,xfers[i])){std::fprintf(stderr,"upload failed at transfer %zu dest=%04X bytes=%zu\n",i,xfers[i].dest,xfers[i].data.size());return false;}
 }
 return true;
}
static bool sync_until(uint64_t &master,uint64_t target){if(master>target)return false;while(master<target){uint64_t d=target-master;if(d>200000)d=200000;if(!sync_to(master,d))return false;}return true;}
static bool run_service_window(uint64_t &master,uint64_t clocks,uint64_t &nextService){
 const uint64_t frameClocks=357366;uint64_t target=master+clocks;
 while(master<target){uint64_t next=(nextService<target)?nextService:target;if(!sync_until(master,next))return false;if(master==nextService){if(!runtime_service(master))return false;nextService+=frameClocks;}}
 return true;
}
static bool run_prepackage_until(uint64_t &master,uint64_t target,uint64_t &nextService){
 const uint64_t frameClocks=357366;
 while(master<target){uint64_t next=(nextService<target)?nextService:target;if(!sync_until(master,next))return false;if(master==nextService){if(!prepackage_service(master))return false;nextService+=frameClocks;}}
 return true;
}
int main(int argc,char**argv){
 if(argc<6){std::fprintf(stderr,"usage: tg3-audio-lab seed.bin track-transfer.bin package seconds output.raw [--snapshot-check]\n");return 2;}
 std::vector<uint8_t> image;std::vector<Transfer>xfers;if(!load_file(argv[1],image)||image.size()!=65536||!load_transfers(argv[2],xfers)){std::fprintf(stderr,"bad seed/transfer input\n");return 2;}
 int package=std::strtol(argv[3],nullptr,0);double seconds=std::atof(argv[4]);
 char e[256];if(!tg3_static_apu_acquire(e,sizeof(e))){std::fprintf(stderr,"acquire: %s\n",e);return 3;}
 Capture cap;tg3_static_apu_set_sink(sink,&cap);SCStaticTraceCallbacks traces{};traces.dsp_write=dsp_trace;traces.context=&cap;tg3_static_apu_set_trace_callbacks(&traces);
 if(!tg3_static_apu_lab_seed_tg3(image.data(),image.size(),20)){std::fprintf(stderr,"seed failed\n");return 3;}
 uint64_t master=0;
 /* The source game enters $0840 at master 10,999,270 and begins the title package
    transaction at 107,887,528. Preserve that 96,888,258-master-clock resident
    pre-package epoch with the exact zero-level periodic service. */
 if(!wait_ready77(master,12000000))return 4;
 const uint64_t frameClocks=357366;uint64_t nextPreService=master+frameClocks;
 if(!run_prepackage_until(master,96888258ull,nextPreService))return 4;
 if(!load_package(master,xfers))return 4;
 if(!start_loaded_song(master))return 4;
 std::fprintf(stderr,"POSTLOAD+START master=%llu OUT=%02X/%02X/%02X/%02X\n",(unsigned long long)master,readp(master,0),readp(master,1),readp(master,2),readp(master,3));
 cap.pcm.clear();cap.nonzero_volume_write_mask=cap.kon_touch_mask=cap.koff_touch_mask=cap.eon_mask=cap.pmon_mask=cap.non_mask=0;
 uint64_t nextService=master+frameClocks;
 if(argc>=7 && std::string(argv[6])=="--snapshot-check"){
   if(!run_service_window(master,(uint64_t)(21477270.0*2.0),nextService))return 5;
   size_t snapSize=tg3_static_apu_snapshot_size();std::vector<uint8_t> snap(snapSize),snap2(snapSize);
   if(!snapSize||!tg3_static_apu_snapshot_save(snap.data(),snap.size()))return 7;
   uint64_t savedMaster=master,savedNextService=nextService;cap.pcm.clear();
   if(!run_service_window(master,(uint64_t)(21477270.0*1.0),nextService))return 5;
   std::vector<int16_t> first=cap.pcm;SCStaticApuStatus firstStatus{};tg3_static_apu_status(&firstStatus);
   if(!tg3_static_apu_snapshot_load(snap.data(),snap.size(),e,sizeof(e)))return 7;
   if(!tg3_static_apu_snapshot_save(snap2.data(),snap2.size())||snap!=snap2)return 7;
   master=savedMaster;nextService=savedNextService;cap.pcm.clear();
   if(!run_service_window(master,(uint64_t)(21477270.0*1.0),nextService))return 5;
   SCStaticApuStatus secondStatus{};tg3_static_apu_status(&secondStatus);
   bool statusSame=firstStatus.synchronized_master_clock==secondStatus.synchronized_master_clock&&firstStatus.smp_cycles==secondStatus.smp_cycles&&firstStatus.smp_instructions==secondStatus.smp_instructions&&firstStatus.aot_validated_instructions==secondStatus.aot_validated_instructions&&firstStatus.pcm_frames==secondStatus.pcm_frames&&firstStatus.pcm_known_frames==secondStatus.pcm_known_frames&&firstStatus.pcm_unknown_frames==secondStatus.pcm_unknown_frames&&firstStatus.pcm_hash==secondStatus.pcm_hash&&firstStatus.pcm_overflows==secondStatus.pcm_overflows&&firstStatus.smp_pc==secondStatus.smp_pc&&firstStatus.smp_a==secondStatus.smp_a&&firstStatus.smp_x==secondStatus.smp_x&&firstStatus.smp_y==secondStatus.smp_y&&firstStatus.smp_sp==secondStatus.smp_sp&&firstStatus.smp_psw==secondStatus.smp_psw&&firstStatus.aot_failed==secondStatus.aot_failed&&firstStatus.sdsp_static_failed==secondStatus.sdsp_static_failed&&firstStatus.rendezvous_hash==secondStatus.rendezvous_hash&&firstStatus.cpu_port_event_hash==secondStatus.cpu_port_event_hash;
   size_t nz=0;for(auto v:first)if(v)++nz;
   if(first!=cap.pcm||!statusSame||!nz){std::fprintf(stderr,"playing snapshot mismatch pcm=%d status=%d nz=%zu\n",first==cap.pcm,statusSame,nz);return 7;}
   std::printf("TG3_PLAYING_SNAPSHOT PASS package=%d snapshot_bytes=%zu replay_frames=%zu replay_nonzero=%zu pcm_identical=1 status_identical=1\n",package,snapSize,first.size()/2,nz);tg3_static_apu_release();return 0;
 }
 if(!run_service_window(master,(uint64_t)(21477270.0*seconds),nextService))return 5;
 std::fprintf(stderr,"POSTRUN master=%llu OUT=%02X/%02X/%02X/%02X\n",(unsigned long long)master,readp(master,0),readp(master,1),readp(master,2),readp(master,3));
 SCStaticApuStatus st{};tg3_static_apu_status(&st);
 uint8_t dir=0,mvl=0,mvr=0;tg3_static_apu_read_dsp_register(0x5d,&dir);tg3_static_apu_read_dsp_register(0x0c,&mvl);tg3_static_apu_read_dsp_register(0x1c,&mvr);
 std::ofstream out(argv[5],std::ios::binary);out.write((const char*)cap.pcm.data(),(std::streamsize)(cap.pcm.size()*sizeof(int16_t)));
 std::vector<uint8_t> aram(65536);tg3_static_apu_read_aram(0,aram.data(),aram.size());std::ofstream ao(std::string(argv[5])+".aram",std::ios::binary);ao.write((const char*)aram.data(),aram.size());
 size_t nonzero=0;for(auto v:cap.pcm)if(v)++nonzero;
 std::printf("TG3_LAB package=%d seconds=%.3f transfers=%zu frames=%zu nonzero=%zu pc=%04X aot=%llu aot_fail=%u reason=%u failpc=%04X expected=%02X actual=%02X dsp_fail=%u unknown_pcm=%llu overflow=%llu port_events=%llu pcm_hash=%016llX volume_write_mask=%02X kon=%02X koff=%02X eon=%02X pmon=%02X non=%02X DIR=%02X MV=%02X/%02X code_barriers=%u\n",package,seconds,xfers.size(),cap.pcm.size()/2,nonzero,st.smp_pc,(unsigned long long)st.aot_validated_instructions,st.aot_failed,st.aot_fail_reason,st.aot_fail_pc,st.expected_opcode,st.actual_opcode,st.sdsp_static_failed,(unsigned long long)st.pcm_unknown_frames,(unsigned long long)st.pcm_overflows,(unsigned long long)st.cpu_port_event_count,(unsigned long long)st.pcm_hash,cap.nonzero_volume_write_mask,cap.kon_touch_mask,cap.koff_touch_mask,cap.eon_mask,cap.pmon_mask,cap.non_mask,dir,mvl,mvr,st.code_write_barriers);
 tg3_static_apu_release();return (st.aot_failed||st.sdsp_static_failed||st.pcm_unknown_frames||st.pcm_overflows||st.code_write_barriers||nonzero==0)?6:0;
}
