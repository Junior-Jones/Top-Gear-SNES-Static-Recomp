#include "tg2_static_apu.h"
#include <cstdio>
#include <cstdint>
#include <cstdlib>
#include <vector>
#include <string>
#include <fstream>
#include <iterator>
#include <cstring>

struct Capture { bool collecting=false; std::vector<int16_t> pcm; uint8_t nonzero_volume_write_mask=0; uint8_t kon_touch_mask=0; uint8_t koff_touch_mask=0; };
struct Transfer { uint16_t dest; std::vector<uint8_t> data; };
static void sink(void *ctx,int16_t l,int16_t r){auto*c=(Capture*)ctx;if(!c->collecting)return;c->pcm.push_back(l);c->pcm.push_back(r);}
static void dsp_trace(void *ctx,uint16_t,uint8_t address,uint8_t value){
 auto*c=(Capture*)ctx;
 if((address&0x0f)<=1 && (address>>4)<8 && value)c->nonzero_volume_write_mask|=(uint8_t)(1u<<(address>>4));
 if(address==0x4c)c->kon_touch_mask|=value;
 if(address==0x5c)c->koff_touch_mask|=value;
}
#include "music_payloads.inc"
static bool load_transfers(const uint8_t *b,size_t size,std::vector<Transfer>&out){
 if(size<12||std::memcmp(b,"TG2XFER1",8))return false;
 size_t p=12;uint32_t count=(uint32_t)b[8]|((uint32_t)b[9]<<8)|((uint32_t)b[10]<<16)|((uint32_t)b[11]<<24);
 for(uint32_t j=0;j<count;j++){if(p+6>size)return false;uint16_t dest=(uint16_t)(b[p]|b[p+1]<<8);uint32_t len=(uint32_t)b[p+2]|((uint32_t)b[p+3]<<8)|((uint32_t)b[p+4]<<16)|((uint32_t)b[p+5]<<24);p+=6;if(len>size-p)return false;out.push_back(Transfer{dest,std::vector<uint8_t>(b+p,b+p+len)});p+=len;}return p==size;
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
namespace {
Capture capture;
uint64_t clockMaster=0, serviceNext=0;
size_t readIndex=0;
bool acquired=false;
struct Cache { std::vector<uint8_t> bytes; uint64_t master=0,next=0; };
Cache cache[6];
 }
extern "C" int tg2_music_select(unsigned track){
 if(track>=6u)return 0;
 char error[256];
 if(!acquired){if(!tg2_static_apu_acquire(error,sizeof(error)))return 0;acquired=true;}
 tg2_static_apu_set_sink(sink,&capture);tg2_static_apu_set_trace_callbacks(nullptr);
 capture.collecting=false;capture.pcm.clear();readIndex=0;
 if(cache[track].bytes.empty()){
  if(!tg2_static_apu_lab_seed_tg2(tg2_driver_base,sizeof(tg2_driver_base),25))return 0;
  clockMaster=0;std::vector<Transfer> xfers;
unsigned package=track<4?track:0;uint8_t selector=track==4?4:track==5?2:1;
std::vector<Transfer> boot; if(!load_transfers(tg2_package_0_transfer,sizeof(tg2_package_0_transfer),boot)||!load_package_timed(clockMaster,0,0,0,boot,kBootStarts,18))return 0;
switch(package){
case 0:if(!load_transfers(tg2_package_0_transfer,sizeof(tg2_package_0_transfer),xfers))return 0;break;
case 1:if(!load_transfers(tg2_package_1_transfer,sizeof(tg2_package_1_transfer),xfers))return 0;break;
case 2:if(!load_transfers(tg2_package_2_transfer,sizeof(tg2_package_2_transfer),xfers))return 0;break;
case 3:if(!load_transfers(tg2_package_3_transfer,sizeof(tg2_package_3_transfer),xfers))return 0;break;
default:return 0;}
if(package==0){if(!load_package_timed(clockMaster,255,255,selector,xfers,kTitleStarts,18))return 0;}else{if(!sync_until(clockMaster,kTitleStarts[0])||!load_package(clockMaster,255,255,selector,xfers))return 0;}
serviceNext=clockMaster+357366;cache[track].bytes.resize(tg2_static_apu_snapshot_size());
 if(!tg2_static_apu_snapshot_save(cache[track].bytes.data(),cache[track].bytes.size()))return 0;
 cache[track].master=clockMaster;cache[track].next=serviceNext;
 }else{if(!tg2_static_apu_snapshot_load(cache[track].bytes.data(),cache[track].bytes.size(),error,sizeof(error)))return 0;clockMaster=cache[track].master;serviceNext=cache[track].next;}
 capture.collecting=true;return 1;
}
extern "C" int tg2_music_sample(int16_t *left,int16_t *right){
 if(!acquired||!capture.collecting)return 0;
 if(readIndex==capture.pcm.size()){capture.pcm.clear();readIndex=0;if(!run_service_window(clockMaster,21477,serviceNext))return 0;}
 if(readIndex+2>capture.pcm.size())return 0;
 *left=capture.pcm[readIndex++];*right=capture.pcm[readIndex++];return 1;
}
extern "C" void tg2_music_gain(unsigned percent){tg2_static_apu_mod_set_menu_music_gain((uint8_t)percent);}
extern "C" int tg2_music_prepare(void){for(unsigned t=0;t<6;t++)if(!tg2_music_select(t))return 0;return 1;}
extern "C" void tg2_music_release(void){if(acquired)tg2_static_apu_release();acquired=false;capture.collecting=false;capture.pcm.clear();readIndex=0;}

struct RuntimeSnapshot {uint64_t master,next;uint32_t count,index,active,reserved;int16_t pending[1024];};
extern "C" size_t tg2_music_snapshot_size(void){return sizeof(RuntimeSnapshot)+tg2_static_apu_snapshot_size();}
extern "C" int tg2_music_snapshot_save(void *data,size_t size){
 if(size!=tg2_music_snapshot_size()||capture.pcm.size()>1024)return 0;RuntimeSnapshot h{};h.master=clockMaster;h.next=serviceNext;h.count=(uint32_t)capture.pcm.size();h.index=(uint32_t)readIndex;h.active=capture.collecting?1:0;std::memcpy(h.pending,capture.pcm.data(),h.count*2);std::memcpy(data,&h,sizeof(h));return tg2_static_apu_snapshot_save((uint8_t*)data+sizeof(h),size-sizeof(h));}
extern "C" int tg2_music_snapshot_load(const void *data,size_t size,char *error,size_t capacity){
 if(size!=tg2_music_snapshot_size())return 0;RuntimeSnapshot h;std::memcpy(&h,data,sizeof(h));if(h.count>1024||h.index>h.count||(h.count&1)||(h.index&1)||h.active>1||h.next<h.master)return 0;
 if(!tg2_static_apu_snapshot_load((const uint8_t*)data+sizeof(h),size-sizeof(h),error,capacity))return 0;clockMaster=h.master;serviceNext=h.next;capture.pcm.assign(h.pending,h.pending+h.count);readIndex=h.index;capture.collecting=h.active!=0;tg2_static_apu_set_sink(sink,&capture);return 1;}
