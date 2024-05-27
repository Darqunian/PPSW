#include <LPC21xx.H>
#include "timer.h"

#define COUNTER_ENABLE (1<<0)
#define COUNTER_RESET (1<<1)
#define MR0_INTERRUPT_FLAG (1<<0)
#define MR0_INTERRUPT_MATCH (1<<0)
#define MR0_INTERRUPT_RESET (1<<1)

void InitTimer0(void){
	T0TCR=COUNTER_ENABLE;
}

void WaitOnTimer0(unsigned int uiTime){
	
	T0TCR |= (COUNTER_RESET);
	T0TCR &= (~COUNTER_RESET);
	
	while ((uiTime*15) >= T0TC){}
}

void InitTimer0Match0(unsigned int uiDelayTime){
	
	T0MR0 = uiDelayTime*15;
	T0TCR=COUNTER_ENABLE;
	T0TCR |= (COUNTER_RESET);
	T0TCR &= (~COUNTER_RESET);
	T0MCR |= MR0_INTERRUPT_MATCH | MR0_INTERRUPT_RESET;
	
	
	}

void WaitOnTimer0Match0(void){
	while(T0IR != MR0_INTERRUPT_FLAG){}
	T0IR = MR0_INTERRUPT_FLAG;
	}


