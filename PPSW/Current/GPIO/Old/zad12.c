#include <LPC21xx.H>
#include <stdio.h>

#define LED0_bm 1<<16
#define LED1_bm 1<<17
#define LED2_bm 1<<18
#define LED3_bm 1<<19

void Delay(iLoopTimer)
{
	iLoopTimer = (iLoopTimer/7.8551)*100000;
	for(  ; iLoopTimer > 0 ; iLoopTimer--)
	{}
}

int main()
{
	IO1DIR = LED0_bm | LED1_bm | LED2_bm | LED3_bm; 


	
	while(1)
	{
		IO1CLR = LED3_bm;
		IO1SET = LED0_bm;
		Delay(250);
		IO1CLR = LED0_bm;
		IO1SET = LED1_bm;
		Delay(250);
		IO1CLR = LED1_bm;
		IO1SET = LED2_bm;
		Delay(250);
		IO1CLR = LED2_bm;
		IO1SET = LED3_bm;
		Delay(250);
	}
}
