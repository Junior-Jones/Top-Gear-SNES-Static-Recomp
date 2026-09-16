#include "sc_static_apu.h"
#include <vector>
#include <cstring>
#include <cstdio>
struct PortEvent {uint64_t clock;unsigned char port,value;};
#include "music_ports.inc"
namespace {
struct Cache {std::vector<uint8_t> bytes;uint64_t clock=0;};
Cache cache[7];std::vector<int16_t> pcm;size_t readIndex=0;uint64_t clockMaster=0;bool acquired=false,collecting=false;
void sink(void*,int16_t l,int16_t r){if(collecting){pcm.push_back(l);pcm.push_back(r);}}
const PortEvent *const songs[7]={song1,song2,song3,song4,song5,song6,song7};
const size_t counts[7]={sizeof(song1)/sizeof(PortEvent),sizeof(song2)/sizeof(PortEvent),sizeof(song3)/sizeof(PortEvent),sizeof(song4)/sizeof(PortEvent),sizeof(song5)/sizeof(PortEvent),sizeof(song6)/sizeof(PortEvent),sizeof(song7)/sizeof(PortEvent)};
}
extern "C" int tg0_music_select(unsigned track){
 char error[256];if(track>=7)return 0;
 if(!acquired){if(!sc_static_apu_acquire(error,sizeof(error)))return 0;acquired=true;}
 collecting=false;pcm.clear();readIndex=0;sc_static_apu_set_sink(sink,nullptr);
 if(cache[track].bytes.empty()){
  sc_static_apu_reset();
  for(size_t n=0;n<counts[track];n++){const auto &e=songs[track][n];if(!sc_static_apu_cpu_write_port(e.clock,e.port,e.value,error,sizeof(error))){fprintf(stderr,"TG player: %s\n",error);return 0;}}
  clockMaster=songs[track][counts[track]-1].clock;
  cache[track].bytes.resize(sc_static_apu_snapshot_size());cache[track].clock=clockMaster;
  if(!sc_static_apu_snapshot_save(cache[track].bytes.data(),cache[track].bytes.size()))return 0;
 }else{
  if(!sc_static_apu_snapshot_load(cache[track].bytes.data(),cache[track].bytes.size(),error,sizeof(error)))return 0;
  clockMaster=cache[track].clock;
 }
 collecting=true;return 1;
}
extern "C" int tg0_music_prepare(void){for(unsigned t=0;t<7;t++)if(!tg0_music_select(t))return 0;return 1;}
extern "C" int tg0_music_sample(int16_t *l,int16_t *r){
 if(!acquired||!collecting)return 0;
 if(readIndex==pcm.size()){char error[256];pcm.clear();readIndex=0;clockMaster+=21477u;if(!sc_static_apu_sync_to_master(clockMaster,error,sizeof(error)))return 0;}
 if(readIndex+2>pcm.size())return 0;*l=pcm[readIndex++];*r=pcm[readIndex++];return 1;
}
extern "C" void tg0_music_gain(unsigned percent){sc_static_apu_music_volume(percent);}
extern "C" void tg0_music_release(void){if(acquired)sc_static_apu_release();acquired=false;collecting=false;pcm.clear();readIndex=0;}
struct RuntimeSnapshot {uint64_t master;uint32_t count,index,active,reserved;int16_t pending[1024];};
extern "C" size_t tg0_music_snapshot_size(void){return sizeof(RuntimeSnapshot)+sc_static_apu_snapshot_size();}
extern "C" int tg0_music_snapshot_save(void *data,size_t size){
 if(size!=tg0_music_snapshot_size()||pcm.size()>1024)return 0;RuntimeSnapshot h{};h.master=clockMaster;h.count=(uint32_t)pcm.size();h.index=(uint32_t)readIndex;h.active=collecting?1:0;std::memcpy(h.pending,pcm.data(),h.count*2);std::memcpy(data,&h,sizeof(h));return sc_static_apu_snapshot_save((uint8_t*)data+sizeof(h),size-sizeof(h));}
extern "C" int tg0_music_snapshot_load(const void *data,size_t size,char *error,size_t capacity){
 if(size!=tg0_music_snapshot_size())return 0;RuntimeSnapshot h;std::memcpy(&h,data,sizeof(h));if(h.count>1024||h.index>h.count||(h.count&1)||(h.index&1)||h.active>1)return 0;
 if(!sc_static_apu_snapshot_load((const uint8_t*)data+sizeof(h),size-sizeof(h),error,capacity))return 0;clockMaster=h.master;pcm.assign(h.pending,h.pending+h.count);readIndex=h.index;collecting=h.active!=0;sc_static_apu_set_sink(sink,nullptr);return 1;}
