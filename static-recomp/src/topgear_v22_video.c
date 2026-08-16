#include "topgear_internal.h"
#include <string.h>

/* TOP GEAR GRAPHICS / GAMEPLAY DISPLAY OWNERSHIP NOTES (Version 27)
   Top Gear naturally proves Mode 1 for menus/HUD/tiled artwork: BG1/BG2 are
   4-bpp and BG3 is 2-bpp.  Race road perspective uses Mode 7 affine rendering.
   OBJ/OAM supplies cars plus display objects for the race HUD.  ROM-owned
   setup/upload code is mainly around 00:C745-CC85 and 0F:A468-A627.

   ROM UI/control data near 0F:A6ED/0F:A70B/0F:A874 contains SPEED labels,
   0F:A8BB contains FUEL, and the 0F:B0CB area contains GEARS/ACCEL control
   text.  Those addresses identify UI/control-data ownership, NOT a certified
   live WRAM car-speed/fuel/gear variable.  The renderer consumes the final PPU
   tile/OAM/register state produced by game logic; it must not invent gameplay
   values or use screen text as an execution oracle.

   The 32 course-name records are ROM-owned and packed in bank 0F.  Exact
   CPU/file locations (LoROM file offset in parentheses) are:
     01 Las Vegas   0F:AC93 (07AC93)   02 Los Angeles 0F:ACAD (07ACAD)
     03 New York    0F:ACC9 (07ACC9)   04 San Francisco 0F:ACE2 (07ACE2)
     05 Rio         0F:AD00 (07AD00)   06 Machu Picchu 0F:AD15 (07AD15)
     07 Chichen Itza 0F:AD31 (07AD31)  08 Rain Forest 0F:AD4F (07AD4F)
     09 Tokyo       0F:AD6C (07AD6C)   10 Hiroshima   0F:AD82 (07AD82)
     11 Yokohama    0F:AD9C (07AD9C)   12 Kyoto       0F:ADB5 (07ADB5)
     13 Munich      0F:ADCB (07ADCB)   14 Cologne     0F:ADE4 (07ADE4)
     15 Black Forest 0F:ADFE (07ADFE)  16 Frankfurt   0F:AE1D (07AE1D)
     17 Stockholm   0F:AE39 (07AE39)   18 Copenhagen  0F:AE54 (07AE54)
     19 Helsinki    0F:AE71 (07AE71)   20 Oslo        0F:AE8C (07AE8C)
     21 Paris       0F:AEA2 (07AEA2)   22 Nice        0F:AEB9 (07AEB9)
     23 Bordeaux    0F:AECF (07AECF)   24 Monaco      0F:AEE9 (07AEE9)
     25 Pisa        0F:AF01 (07AF01)   26 Rome        0F:AF16 (07AF16)
     27 Sicily      0F:AF2B (07AF2B)   28 Florence    0F:AF42 (07AF42)
     29 London      0F:AF5B (07AF5B)   30 Sheffield   0F:AF74 (07AF74)
     31 Loch Ness   0F:AF90 (07AF90)   32 Stonehenge  0F:AFAD (07AFAD).
   These are name-record locations, not the separate road-geometry records.
   The fixed-width
   player/opponent name table is at 0D:C47B-0D:C512.  These are data landmarks,
   not proof of the AI steering/catch-up algorithm.  See
   static-recomp/STATIC-CORE-NOTES.md for evidence levels and headless tests. */

typedef struct TgPixel { uint16_t color; uint8_t palette_index,priority,layer,obj_palette,transparent; } TgPixel;
typedef struct TgObject { uint16_t x; uint8_t y,character,name_select,palette,priority,hflip,vflip,width,height,index; } TgObject;
typedef struct TgObjectLine { TgObject object; uint8_t line; } TgObjectLine;
typedef struct TgObjectTile { uint16_t x; uint8_t priority,palette,hflip; uint32_t data; } TgObjectTile;

static TopGearRecomp *g_i;
static uint8_t regv(uint16_t a){return g_i->ppu_registers[a-0x2100u];}
static uint16_t vr16(uint32_t a){return (uint16_t)(g_i->vram[a&0xffffu]|((uint16_t)g_i->vram[(a+1u)&0xffffu]<<8));}
static uint16_t cg(unsigned n){uint32_t a=(n&255u)*2u;return (uint16_t)(g_i->cgram[a]|((uint16_t)g_i->cgram[a+1u]<<8))&0x7fffu;}
static uint16_t bright(uint16_t c,unsigned b){unsigned r=c&31u,g=(c>>5)&31u,bl=(c>>10)&31u;r=r*b/15u;g=g*b/15u;bl=bl*b/15u;return(uint16_t)(r|(g<<5)|(bl<<10));}
static uint16_t cadd(uint16_t a,uint16_t b,int half){unsigned ar=a&31u,ag=(a>>5)&31u,ab=(a>>10)&31u,br=b&31u,bg=(b>>5)&31u,bb=(b>>10)&31u;unsigned r=ar+br,g=ag+bg,bl=ab+bb;if(half){r>>=1;g>>=1;bl>>=1;}else{if(r>31)r=31;if(g>31)g=31;if(bl>31)bl=31;}return(uint16_t)(r|(g<<5)|(bl<<10));}
static uint16_t csub(uint16_t a,uint16_t b,int half){int r=(int)(a&31u)-(int)(b&31u),g=(int)((a>>5)&31u)-(int)((b>>5)&31u),bl=(int)((a>>10)&31u)-(int)((b>>10)&31u);if(r<0)r=0;if(g<0)g=0;if(bl<0)bl=0;if(half){r>>=1;g>>=1;bl>>=1;}return(uint16_t)(r|(g<<5)|(bl<<10));}
static unsigned bpp(unsigned mode,unsigned l){static const uint8_t t[7][4]={{2,2,2,2},{4,4,2,0},{4,4,0,0},{8,4,0,0},{8,2,0,0},{4,2,0,0},{4,0,0,0}};return mode<7&&l<4?t[mode][l]:0;}
static uint8_t bgpri(unsigned mode,unsigned l,unsigned hi,int bg3hi){static const uint8_t m0[4][2]={{8,11},{7,10},{2,5},{1,4}},m1[4][2]={{6,9},{5,8},{1,3},{0,0}},mx[4][2]={{3,9},{1,7},{0,0},{0,0}},m6[4][2]={{3,9},{0,0},{0,0},{0,0}};if(mode==0)return m0[l][hi!=0];if(mode==1){if(l==2&&hi&&bg3hi)return 11;return m1[l][hi!=0];}if(mode>=2&&mode<=5)return mx[l][hi!=0];if(mode==6)return m6[l][hi!=0];return 0;}
static uint8_t objpri(unsigned mode,unsigned p){static const uint8_t m0[4]={3,6,9,12},m1[4]={2,4,7,10},mx[4]={2,4,6,8},m7a[4]={1,3,4,5},m7b[4]={2,4,6,7};p&=3;if(mode==0)return m0[p];if(mode==1)return m1[p];if(mode==7)return (regv(0x2133u)&0x40u)?m7b[p]:m7a[p];return mx[p];}
static uint16_t direct_color(uint8_t pal,uint8_t px){unsigned r=((px&7u)<<2)|((pal&1u)<<1),g=((px&0x38u)>>1)|((pal&2u)<<3),b=((px&0xc0u)>>3)|((pal&4u)<<2);return(uint16_t)((r&31u)|((g&31u)<<5)|((b&31u)<<10));}

static uint16_t bg_map_entry(unsigned l,unsigned wx,unsigned wy,unsigned ts){
    uint8_t sc=regv((uint16_t)(0x2107u+l));
    unsigned mw=(sc&1u)?64u:32u,mh=(sc&2u)?64u:32u;
    unsigned tx=(wx%(mw*ts))/ts,ty=(wy%(mh*ts))/ts;
    unsigned screen=(ty>>5)*(mw==64u?2u:1u)+(tx>>5);
    uint32_t mapbase=(uint32_t)(sc&0xfcu)<<9;
    uint32_t mapaddr=mapbase+screen*0x800u+(((ty&31u)*32u+(tx&31u))*2u);
    return vr16(mapaddr);
}

/*
 * SNES offset-per-tile source lookup.  In modes 2/4/6 BG3 is not drawn as a
 * normal layer; its tilemap supplies per-column offsets for BG1/BG2.  This is
 * the functional/current-state equivalent of the accurate PPU's BG3
 * fetchOffset(0) and fetchOffset(8) operations.  Exact fetch-pipeline timing
 * remains a later scanline-history certification concern.
 */
static uint16_t bg3_opt_word(unsigned sample_x,unsigned row_y){
    uint8_t sc=regv(0x2109u);
    unsigned mw=(sc&1u)?64u:32u,mh=(sc&2u)?64u:32u;
    unsigned ts=(regv(0x2105u)&0x40u)?16u:8u;
    unsigned ww=mw*ts,wh=mh*ts;
    unsigned wx=((sample_x&~7u)+(g_i->bg_scroll[4]&~7u))%ww;
    unsigned wy=(row_y+g_i->bg_scroll[5])%wh;
    return bg_map_entry(2u,wx,wy,ts);
}

static void apply_offset_per_tile(unsigned mode,unsigned l,unsigned sample_x,unsigned sample_y,unsigned *wx,unsigned *wy){
    uint16_t hlookup,vlookup;
    unsigned valid;
    if(l>=2u||(mode!=2u&&mode!=4u&&mode!=6u))return;
    hlookup=bg3_opt_word(sample_x,0u);
    vlookup=bg3_opt_word(sample_x,8u);
    valid=1u<<(13u+l);
    if(mode==4u){
        if(hlookup&valid){
            if((hlookup&0x8000u)==0u)*wx=sample_x+(hlookup&~7u)+(g_i->bg_scroll[l*2u]&7u);
            else *wy=sample_y+vlookup;
        }
    }else{
        if(hlookup&valid)*wx=sample_x+(hlookup&~7u)+(g_i->bg_scroll[l*2u]&7u);
        if(vlookup&valid)*wy=sample_y+vlookup;
    }
}

/* Top Gear Mode 1 path: BG1/BG2 4-bpp, BG3 2-bpp; generic tiled modes share this fetch. */
static int tiled_pixel(unsigned l,unsigned x,unsigned y,TgPixel *p){
    unsigned mode=regv(0x2105u)&7u,bb=bpp(mode,l),sample_x=x,sample_y=y,mosaic=((unsigned)regv(0x2106u)>>4)+1u;
    uint8_t sc,nba,pg,color=0;
    unsigned ts,mw,mh,ww,wh,wx,wy,tx,ty,px,py,screen;
    uint32_t mapbase,charbase,mapaddr,row;
    uint16_t e,tile;
    unsigned bit,plane;
    memset(p,0,sizeof(*p));p->transparent=1;
    if(l>=4||!bb)return 1;
    if((regv(0x2106u)&(1u<<l))&&mosaic>1){sample_x-=sample_x%mosaic;sample_y-=sample_y%mosaic;}
    sc=regv((uint16_t)(0x2107u+l));mw=(sc&1)?64:32;mh=(sc&2)?64:32;mapbase=(uint32_t)(sc&0xfcu)<<9;
    nba=regv(l<2?0x210bu:0x210cu);charbase=(uint32_t)((l&1)?(nba>>4):(nba&15u))<<13;
    ts=(regv(0x2105u)&(uint8_t)(0x10u<<l))?16:8;if(mode==5||mode==6)ts=16;
    ww=mw*ts;wh=mh*ts;
    wx=sample_x+g_i->bg_scroll[l*2u];wy=sample_y+g_i->bg_scroll[l*2u+1u];
    apply_offset_per_tile(mode,l,sample_x,sample_y,&wx,&wy);
    wx%=ww;wy%=wh;
    tx=wx/ts;ty=wy/ts;px=wx%ts;py=wy%ts;screen=(ty>>5)*(mw==64?2u:1u)+(tx>>5);
    mapaddr=mapbase+screen*0x800u+(((ty&31u)*32u+(tx&31u))*2u);e=vr16(mapaddr);tile=(uint16_t)(e&0x3ffu);pg=(uint8_t)((e>>10)&7u);
    if(e&0x4000u) px=ts-1u-px;
    if(e&0x8000u) py=ts-1u-py;
    if(ts==16){tile=(uint16_t)((tile+(px>>3)+((py>>3)<<4))&0x3ffu);px&=7;py&=7;}
    row=charbase+(uint32_t)tile*(bb*8u)+py*2u;bit=7u-px;
    for(plane=0;plane<bb;plane++){uint32_t a=row+(plane>>1)*16u+(plane&1u);color|=(uint8_t)(((g_i->vram[a&0xffffu]>>bit)&1u)<<plane);}
    if(!color)return 1;
    p->transparent=0;p->priority=bgpri(mode,l,(e>>13)&1u,(regv(0x2105u)&8u)!=0);p->layer=(uint8_t)l;p->palette_index=color;
    if(bb==2){unsigned base=mode==0?l*32u:0u;p->palette_index=(uint8_t)(base+pg*4u+color);p->color=cg(p->palette_index);}
    else if(bb==4){p->palette_index=(uint8_t)(pg*16u+color);p->color=cg(p->palette_index);}
    else{p->palette_index=color;p->color=(regv(0x2130u)&1u)?direct_color(pg,color):cg(color);}
    return 1;
}

/* Top Gear Mode 7 race-road path: affine matrix, centre/scroll, flip and repeat. */
static int32_t clip13(int32_t n){return (n&0x2000)?(n|~1023):(n&1023);}
static int mode7_pixel(unsigned l,unsigned x,unsigned y,TgPixel *p){int32_t a=(int16_t)g_i->v14_m7a,b=(int16_t)g_i->v14_m7b,c=(int16_t)g_i->mode7_c,d=(int16_t)g_i->mode7_d,hc=(int16_t)(g_i->mode7_x<<3)>>3,vc=(int16_t)(g_i->mode7_y<<3)>>3,ho=(int16_t)(g_i->mode7_hofs<<3)>>3,vo=(int16_t)(g_i->mode7_vofs<<3)>>3;int32_t xx=(int32_t)x,yy=(int32_t)y,ox,oy,px,py;uint16_t ta,pa;uint8_t tile,pal;unsigned repeat=(regv(0x211au)>>6)&3u;int oob;memset(p,0,sizeof(*p));p->transparent=1;if(l>1)return 1;if(l==1&&(regv(0x2133u)&0x40u)==0)return 1;if(regv(0x211au)&1u)xx=255-xx;if(regv(0x211au)&2u)yy=255-yy;ox=(a*clip13(ho-hc)&~63)+(b*clip13(vo-vc)&~63)+(b*yy&~63)+(hc<<8);oy=(c*clip13(ho-hc)&~63)+(d*clip13(vo-vc)&~63)+(d*yy&~63)+(vc<<8);px=(ox+a*xx)>>8;py=(oy+c*xx)>>8;oob=((px|py)&~1023)!=0;ta=(uint16_t)((((uint32_t)py>>3)&0x7fu)<<7|(((uint32_t)px>>3)&0x7fu));pa=(uint16_t)(((uint32_t)py&7u)<<3|((uint32_t)px&7u));tile=(repeat==3&&oob)?0:g_i->vram[((uint32_t)ta*2u)&0xffffu];pal=(repeat==2&&oob)?0:g_i->vram[(((uint32_t)((uint16_t)tile<<6|pa)*2u)+1u)&0xffffu];if(!pal)return 1;p->transparent=0;p->layer=(uint8_t)l;if(l==0){p->priority=(regv(0x2133u)&0x40u)?3u:2u;}else{p->priority=(pal&0x80u)?5u:1u;pal&=0x7fu;}p->palette_index=pal;p->color=cg(pal);return 1;}

static uint8_t sw(unsigned m){static const uint8_t v[8]={8,8,8,16,16,32,16,16};return v[m&7];}static uint8_t sh(unsigned m){static const uint8_t v[8]={8,8,8,16,16,32,32,32};return v[m&7];}static uint8_t lw(unsigned m){static const uint8_t v[8]={16,32,64,32,64,64,32,32};return v[m&7];}static uint8_t lh(unsigned m){static const uint8_t v[8]={16,32,64,32,64,64,64,32};return v[m&7];}
/* OBJ/OAM path: cars and race-HUD sprites over tiled/Mode-7 backgrounds.
   Visible HUD concepts include tachometer, speedometer, fuel, rank, gear,
   nitro and course-map objects.  Their numeric/gameplay state remains owned by
   the generated ROM/WRAM logic; this renderer only draws the resulting OAM.

   A saved one-player Las Vegas race-start frame identifies P1's own visible
   car in OAM entries 3-14.  A pre-release traffic experiment used other
   objects in the upper road's near screen-space band only as a conservative
   visible-traffic signal.  That route-specific observation is not a general
   OAM slot contract and does not identify an AI steering, collision, or speed
   field.  Headless USA Test 06 made the scope concrete: enabling this band
   helped Las Vegas reach 1st and Los Angeles 4th, but roadside objects made it
   over-conservative on New York and San Francisco.  Those tracks qualified
   from framebuffer road-centre steering with this OAM heuristic disabled. */
static TgObject decobj(unsigned n){TgObject o;uint8_t hi=g_i->oam[512u+n/4u],pair=(uint8_t)((hi>>((n&3u)*2u))&3u),at=g_i->oam[n*4u+3u],sel=regv(0x2101u),large=(pair>>1)&1u,sm=sel>>5;o.x=(uint16_t)(g_i->oam[n*4u]|((pair&1u)<<8));o.y=(uint8_t)(g_i->oam[n*4u+1u]+1u);o.character=g_i->oam[n*4u+2u];o.name_select=at&1u;o.palette=(at>>1)&7u;o.priority=(at>>4)&3u;o.hflip=(at>>6)&1u;o.vflip=(at>>7)&1u;o.width=large?lw(sm):sw(sm);o.height=large?lh(sm):sh(sm);o.index=(uint8_t)n;return o;}
static void objline(unsigned y,uint8_t pals[256],uint8_t pris[256]){TgObjectLine items[32];TgObjectTile tiles[34];unsigned ic=0,tc=0,scan,i,t,p;uint8_t sel=regv(0x2101u);unsigned first=g_i->oam_priority_rotation?((unsigned)g_i->oam_byte_address>>1)&127u:0u;memset(pals,0,256);memset(pris,0,256);for(scan=0;scan<128;scan++){unsigned n=(first+scan)&127u;TgObject o=decobj(n);uint8_t line=(uint8_t)((y+1u-o.y)&0xffu);if((o.x<=256u||(uint32_t)o.x+o.width-1u>=512u)&&line<o.height){if(ic>=32)break;items[ic].object=o;items[ic].line=line;ic++;}}for(i=ic;i>0;i--){TgObject o=items[i-1].object;unsigned yy=items[i-1].line,xx=o.x&511u,base=(sel&7u)<<13,cx=o.character&15u,cy,tw,tx;if(o.vflip){if(o.width==o.height)yy=o.height-1u-yy;else if(yy<o.width)yy=o.width-1u-yy;else yy=o.width+(o.width-1u)-(yy-o.width);}if(o.name_select)base+=(1u+((sel>>3)&3u))<<12;cy=(((o.character>>4)+(yy>>3))&15u)<<4;tw=o.width>>3;for(tx=0;tx<tw;tx++){unsigned ox=(xx+(tx<<3))&511u,mx,ad,a0,a1;uint16_t w0,w1;if(xx!=256u&&ox>=256u&&ox+7u<512u)continue;mx=o.hflip?tw-1u-tx:tx;ad=base+((cy+((cx+mx)&15u))<<4);ad=(ad&0xfff0u)+(yy&7u);a0=(ad*2u)&0xffffu;a1=((ad+8u)*2u)&0xffffu;w0=vr16(a0);w1=vr16(a1);if(tc>=34)break;tiles[tc].x=(uint16_t)ox;tiles[tc].priority=o.priority;tiles[tc].palette=(uint8_t)(128u+(o.palette<<4));tiles[tc].hflip=o.hflip;tiles[tc].data=(uint32_t)w0|((uint32_t)w1<<16);tc++;}if(tc>=34)break;}for(t=0;t<tc;t++){unsigned xx=tiles[t].x;for(p=0;p<8;p++){unsigned shift;uint8_t col;xx&=511u;if(xx<256u){shift=tiles[t].hflip?p:7u-p;col=(uint8_t)(((tiles[t].data>>shift)&1u)|(((tiles[t].data>>(shift+8u))&1u)<<1)|(((tiles[t].data>>(shift+16u))&1u)<<2)|(((tiles[t].data>>(shift+24u))&1u)<<3));if(col){pals[xx]=(uint8_t)(tiles[t].palette+col);pris[xx]=tiles[t].priority;}}xx++;}}}
static uint8_t wnib(unsigned l){if(l<2)return(uint8_t)((regv(0x2123u)>>(l*4u))&15u);if(l<4)return(uint8_t)((regv(0x2124u)>>((l-2u)*4u))&15u);if(l==4)return regv(0x2125u)&15u;return regv(0x2125u)>>4;}static unsigned wlogic(unsigned l){if(l<4)return(regv(0x212au)>>(l*2u))&3u;if(l==4)return regv(0x212bu)&3u;return(regv(0x212bu)>>2)&3u;}static int inside(unsigned x,unsigned a,unsigned b){return a<=b&&x>=a&&x<=b;}static int wmask(unsigned l,unsigned x){uint8_t n=wnib(l);int e1=(n&2)!=0,e2=(n&8)!=0,v1=inside(x,regv(0x2126u),regv(0x2127u)),v2=inside(x,regv(0x2128u),regv(0x2129u));unsigned q;if(!e1&&!e2)return 0;if(n&1)v1=!v1;if(n&4)v2=!v2;if(!e1)return v2;if(!e2)return v1;q=wlogic(l);if(q==0)return v1||v2;if(q==1)return v1&&v2;if(q==2)return v1!=v2;return v1==v2;}static int applies(unsigned s,int in){if(s==0)return 0;if(s==1)return!in;if(s==2)return in;return 1;}
static TgPixel screenpx(unsigned mask,unsigned wen,unsigned x,unsigned y,uint8_t opal,uint8_t opri){TgPixel best;unsigned mode=regv(0x2105u)&7u,l;memset(&best,0,sizeof(best));best.color=cg(0);best.layer=5;for(l=0;l<4;l++){TgPixel c;if((mask&(1u<<l))==0)continue;if((wen&(1u<<l))&&wmask(l,x))continue;if(mode==7){if(!mode7_pixel(l,x,y,&c))continue;}else{if(!bpp(mode,l)||!tiled_pixel(l,x,y,&c))continue;}if(!c.transparent&&c.priority>best.priority)best=c;}if((mask&0x10u)&&opal){uint8_t pr=objpri(mode,opri);if(!((wen&0x10u)&&wmask(4,x))&&pr>best.priority){best.color=cg(opal);best.palette_index=opal;best.priority=pr;best.layer=4;best.obj_palette=(uint8_t)((opal-128u)>>4);}}return best;}

int tg_v23_render_scanline(TopGearRecomp *i,unsigned y){
    unsigned x;uint8_t opal[256],opri[256];
    if(!i||y>=224u)return 0;
    g_i=i;objline(y,opal,opri);
    for(x=0;x<256u;x++){
        TgPixel mp,sp;uint16_t color,add=i->ppu_fixed_color;uint8_t inid=regv(0x2100u),main=regv(0x212cu)&0x1fu,sub=regv(0x212du)&0x1fu,mw=regv(0x212eu)&0x1fu,swm=regv(0x212fu)&0x1fu,cgw=regv(0x2130u),cga=regv(0x2131u);unsigned br=inid&15u;int blank=(inid&0x80u)!=0,cw,clip,prevent,math;
        if(blank)color=0;
        else{
            mp=screenpx(main,mw,x,y,opal[x],opri[x]);color=mp.color;cw=wmask(5,x);clip=applies((cgw>>6)&3u,cw);prevent=applies((cgw>>4)&3u,cw);math=(cga&(1u<<mp.layer))!=0;
            if(clip)color=0;
            if(cgw&2u){sp=screenpx(sub,swm,x,y,opal[x],opri[x]);add=sp.color;}
            if(mp.layer==4&&mp.obj_palette<4)math=0;
            if(prevent)math=0;
            if(math)color=(cga&0x80u)?csub(color,add,(cga&0x40u)!=0):cadd(color,add,(cga&0x40u)!=0);
            color=bright(color,br);
        }
        i->mode1_frame[(y*256u+x)*2u]=(uint8_t)color;i->mode1_frame[(y*256u+x)*2u+1u]=(uint8_t)(color>>8);
    }
    return 1;
}

int topgear_recomp_v22_render_current_frame(TopGearRecomp *i,TopGearV22VideoInfo *info){unsigned x,y;uint8_t opal[256],opri[256];uint32_t non=0;uint8_t seen[32768/8];if(!i||!info)return 0;memset(info,0,sizeof(*info));memset(seen,0,sizeof(seen));g_i=i;for(y=0;y<224;y++){unsigned mode=regv(0x2105u)&7u;uint8_t inid=regv(0x2100u),main=regv(0x212cu)&0x1fu,sub=regv(0x212du)&0x1fu,mw=regv(0x212eu)&0x1fu,swm=regv(0x212fu)&0x1fu,cgw=regv(0x2130u),cga=regv(0x2131u);unsigned br=inid&15u;int blank=(inid&0x80u)!=0;objline(y,opal,opri);for(x=0;x<256;x++){TgPixel mp,sp;uint16_t color,add=g_i->ppu_fixed_color;int cw,clip,prevent,math;if(blank){color=0;}else{mp=screenpx(main,mw,x,y,opal[x],opri[x]);color=mp.color;cw=wmask(5,x);clip=applies((cgw>>6)&3u,cw);prevent=applies((cgw>>4)&3u,cw);math=(cga&(1u<<mp.layer))!=0;if(clip)color=0;if(cgw&2u){sp=screenpx(sub,swm,x,y,opal[x],opri[x]);add=sp.color;}if(mp.layer==4&&mp.obj_palette<4)math=0;if(prevent)math=0;if(math)color=(cga&0x80u)?csub(color,add,(cga&0x40u)!=0):cadd(color,add,(cga&0x40u)!=0);color=bright(color,br);}i->mode1_frame[(y*256u+x)*2u]=(uint8_t)color;i->mode1_frame[(y*256u+x)*2u+1u]=(uint8_t)(color>>8);if(color)non++;seen[(color&0x7fffu)>>3]|=(uint8_t)(1u<<(color&7u));} (void)mode;}info->mode=(uint8_t)(regv(0x2105u)&7u);info->brightness=(uint8_t)(regv(0x2100u)&15u);info->forced_blank=(uint8_t)((regv(0x2100u)>>7)&1u);info->main_screen_mask=regv(0x212cu)&0x1fu;info->sub_screen_mask=regv(0x212du)&0x1fu;info->non_backdrop_pixels=non;for(x=0;x<sizeof(seen);x++){uint8_t v=seen[x];while(v){info->unique_colors+=(uint32_t)(v&1u);v>>=1;}}tg_sha256_hex(i->mode1_frame,sizeof(i->mode1_frame),info->bgr555_sha256);info->tiled_modes_0_to_6=1u;info->mode7=1u;info->objects=1u;info->windows=1u;info->main_sub_screen=1u;info->color_math=1u;info->brightness_and_forced_blank=1u;info->current_state_not_natural_frame=1u;info->passed=1u;i->mode1_frame_count++;i->mode1_non_backdrop_pixels=non;return 1;}
int topgear_recomp_v22_read_frame_bgr555(const TopGearRecomp *i,uint32_t off,void *out,size_t n){if(!i||!out||off+n>sizeof(i->mode1_frame))return 0;memcpy(out,i->mode1_frame+off,n);return 1;}
