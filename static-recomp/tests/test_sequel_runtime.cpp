#include "../static-audio/sequel/music_runtime.h"
#include <cstdio>
#include <cstdlib>
#include <vector>
static int self_test(){
 for(unsigned game=2;game<=3;game++)for(unsigned track=0;track<(game==2?6u:7u);track++){
  auto select=game==2?tg2_music_select:tg3_music_select;auto sample=game==2?tg2_music_sample:tg3_music_sample;
  auto gain=game==2?tg2_music_gain:tg3_music_gain;auto size=game==2?tg2_music_snapshot_size:tg3_music_snapshot_size;
  auto save=game==2?tg2_music_snapshot_save:tg3_music_snapshot_save;auto load=game==2?tg2_music_snapshot_load:tg3_music_snapshot_load;
  if(!select(track))return 10;int16_t l,r;for(int j=0;j<32040;j++)if(!sample(&l,&r))return 11;
  std::vector<unsigned char> snap(size());if(!save(snap.data(),snap.size()))return 12;
  std::vector<int16_t> first;for(int j=0;j<1000;j++){if(!sample(&l,&r))return 13;first.push_back(l);first.push_back(r);}
  char error[256];if(!load(snap.data(),snap.size(),error,sizeof(error)))return 14;
  for(int j=0;j<1000;j++){if(!sample(&l,&r)||l!=first[j*2]||r!=first[j*2+1])return 15;}
  gain(0);for(int j=0;j<1000;j++){if(!sample(&l,&r)||(j>100&&(l||r)))return 16;}
  gain(50);unsigned nz=0;for(int j=0;j<1000;j++){if(!sample(&l,&r))return 17;if(l||r)nz++;}if(!nz)return 18;
  if(!select(track))return 19;
 }
 tg2_music_release();tg3_music_release();puts("PASS all 13 imported tracks: runtime snapshots, mute, half volume, cached restart");return 0;
}
int main(int argc,char **argv){if(argc==1)return self_test();if(argc!=5)return 2;unsigned game=(unsigned)atoi(argv[1]),track=(unsigned)atoi(argv[2]);if(!(game==2?tg2_music_select(track):tg3_music_select(track)))return 3;FILE *f=fopen(argv[3],"wb");if(!f)return 4;int count=atoi(argv[4]);for(int j=0;j<count;j++){int16_t l,r;if(!(game==2?tg2_music_sample(&l,&r):tg3_music_sample(&l,&r)))return 5;fwrite(&l,2,1,f);fwrite(&r,2,1,f);}fclose(f);tg2_music_release();tg3_music_release();return 0;}
