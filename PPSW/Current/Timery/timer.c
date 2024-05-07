#include <LPC21xx.H>
#include "timer.h"

#define COUNTER_ENABLE (1<<0)
#define COUNTER_RESET (1<<1)

void InitTimer0(void){
	T0TCR=COUNTER_ENABLE;
}

void WaitOnTimer0(unsigned int uiTime){
	
	T0TCR|=COUNTER_RESET;
	T0TCR&=~COUNTER_RESET;
	while ((uiTime*4)> T0TC){}
}
