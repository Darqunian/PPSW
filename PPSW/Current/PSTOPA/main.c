#include <LPC21xx.H>
#include <stdio.h>



void Delay(iLoopTimer)
{
	iLoopTimer = (iLoopTimer/4.1551)*10000;
	for(; iLoopTimer > 0 ; iLoopTimer--)
	{
		
	}
}

int main()
{
	IO1DIR = 0x00010000;
	IO1SET = 0x00010000;
	IO1CLR = 0x00010000;
	
	while(1)
	{
		IO1SET = 0x00010000;
		Delay(1000);
		IO1CLR = 0x00010000;
		Delay(1000);
	}
}
