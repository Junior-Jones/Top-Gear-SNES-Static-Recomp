#include "topgear_internal.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "career_fuel_driver.inc"
static TopGearRecomp*c;
static void put(unsigned a,unsigned v){c->wram[a]=(uint8_t)v;c->wram[a+1]=(uint8_t)(v>>8);}
#define CHECK(v) do{if(!(v)){printf("FAIL line=%u %s\n",__LINE__,#v);return 1;}}while(0)
int main(void){Driver d={0};unsigned cases=0;c=calloc(1,sizeof(*c));c->rom=calloc(524288,1);put(0x200,40000);put(0x1e56,6);put(0x1ed7,1000);put(0x1e62,43007);
CHECK(!driver_fuel_plan(c,&d)&&!d.fuel_low&&d.fuel_shortfall);cases++;
put(0x1e62,12000);memset(&d,0,sizeof(d));CHECK(driver_fuel_plan(c,&d)&&d.fuel_low&&d.fuel_shortfall);cases++;
put(0x1e76,5);put(0x1ed7,30000);memset(&d,0,sizeof(d));CHECK(!driver_fuel_plan(c,&d)&&d.fuel_low&&!d.fuel_shortfall);cases++;
put(0x1e62,1000);put(0x1ed7,39000);memset(&d,0,sizeof(d));CHECK(!driver_fuel_plan(c,&d)&&d.fuel_required<1000);cases++;
put(0x1ed7,0);memset(&d,0,sizeof(d));CHECK(driver_fuel_plan(c,&d));cases++;
put(0x1e62,43007);put(0x1e76,0);put(0x1ed7,1000);memset(&d,0,sizeof(d));driver_fuel_plan(c,&d);put(0x1ed7,6000);put(0x1e62,42007);driver_fuel_plan(c,&d);CHECK(d.fuel_distance==5000&&d.fuel_burn==1000&&d.fuel_rate_q16>=13107&&d.fuel_rate_q16<=13108);cases++;
put(0x1e62,43007);put(0x1e86,0xfffa);driver_fuel_plan(c,&d);CHECK(d.fuel_distance==5000&&d.fuel_burn==1000);cases++;
put(0x1e86,0);put(0x1ed7,2000);driver_fuel_plan(c,&d);CHECK(d.fuel_distance==5000);cases++;
put(0x1ed7,1000);put(0x1e62,42000);driver_fuel_plan(c,&d);CHECK(d.fuel_distance==5000&&d.fuel_burn==1000);cases++;
put(0x1e76,6);put(0x1ed7,0);put(0x1e62,0);CHECK(!driver_fuel_plan(c,&d)&&!d.fuel_required);cases++;
/* Exercise complete steering: low+shortfall enters; low+sufficient stays out. */
memset(c->wram,0,sizeof(c->wram));memset(&d,0,sizeof(d));put(0x200,40000);put(0x1e56,6);put(0x1ed7,1000);put(0x1e62,0x2fff);put(0x6400+1504/16,0x753c);CHECK(driver_input(c,&d,c->wram,c->mode1_frame,0)&TG_BTN_LEFT);CHECK(d.pit_intent&&d.fuel_low&&d.fuel_shortfall);cases++;
memset(&d,0,sizeof(d));put(0x1e76,5);put(0x1ed7,39000);put(0x1e62,1000);put(0x6400+39904/16,0x753c);driver_input(c,&d,c->wram,c->mode1_frame,0);CHECK(!d.pit_intent&&!d.fuel_shortfall);cases++;
printf("PASS Career fuel cases=%u both_low_and_shortfall=1 low_enough_to_finish_no_pit=1 measured_consumption=1 refill_and_reverse_excluded=1 finish_no_pit=1\n",cases);free(c->rom);free(c);return 0;}
