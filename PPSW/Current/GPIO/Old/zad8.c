#include <LPC21xx.H>
#include <stdio.h>



void Delay(iLoopTimer)
{
	iLoopTimer = (iLoopTimer/7.8551)*100000;
	for(  ; iLoopTimer > 0 ; iLoopTimer--)
	{}
}

int main()
{
	IO1DIR = 0x00010000;
	IO1SET = 0x00010000;
	IO1CLR = 0x00010000;
	
	while(1)
	{
		IO1SET = 0x00010000;
		Delay(50);
		IO1CLR = 0x00010000;
		Delay(50);
	}
}
