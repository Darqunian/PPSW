#include <LPC21xx.H>
#include <stdio.h>

#define LED0_bm 1<<16;
#define LED1_bm 1<<17;
#define LED2_bm 1<<18;
#define LED3_bm 1<<19;

void Delay(iLoopTimer)
{
	iLoopTimer = (iLoopTimer/7.8551)*100000;
	for(  ; iLoopTimer > 0 ; iLoopTimer--)
	{}
}

int main()
{
	IO1DIR = LED3_bm;
	IO1SET = LED3_bm;
	IO1CLR = LED3_bm;
	
	while(1)
	{
		IO1SET = LED3_bm;
		Delay(50);
		IO1CLR = LED3_bm;
		Delay(50);
	}
}
