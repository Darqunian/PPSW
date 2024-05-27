#include <LPC21xx.H>
#include <stdio.h>

#define LED0_bm 1<<16
#define LED1_bm 1<<17
#define LED2_bm 1<<18
#define LED3_bm 1<<19

#define S0_bm 1<<4
#define S1_bm 1<<6
#define S2_bm 1<<5
#define S3_bm 1<<7

enum ButtonState {RELASED, BUTTON_0, BUTTON_1, BUTTON_2, BUTTON_3};

char test;

void Delay(iLoopTimer)
{
	iLoopTimer = (iLoopTimer/7.8551)*100000;
	for(  ; iLoopTimer > 0 ; iLoopTimer--)
	{}
}

void LedInit()
{
	IO1DIR = IO1DIR | LED0_bm;
	IO1DIR = IO1DIR | LED1_bm;
	IO1DIR = IO1DIR | LED2_bm;
	IO1DIR = IO1DIR | LED3_bm;
	IO1SET = LED0_bm;
}

void LedOn(unsigned char ucLedIndeks)
{
	IO1CLR = LED0_bm | LED1_bm | LED2_bm | LED3_bm;
	switch (ucLedIndeks)
		{
			case 0:
				IO1SET = LED0_bm;
				break;
			case 1:
				IO1SET = LED1_bm;
				break;
			case 2:
				IO1SET = LED2_bm;
				break;
			case 3:
				IO1SET = LED3_bm;
				break;
			default:
				IO1CLR = LED0_bm | LED1_bm | LED2_bm | LED3_bm;
		}
}

enum ButtonState eKeyboardRead(){
	if((IO0PIN & S0_bm) == 0){
		return BUTTON_0;
	}
	else if((IO0PIN & S1_bm) == 0){
		return BUTTON_1;
  }
	else if((IO0PIN & S2_bm) == 0){
    return BUTTON_2;
  }
	else if((IO0PIN & S3_bm) == 0){
    return BUTTON_3;
  }
	else{
    return RELASED;
  }
}

void KeyboardInit(){
    IO0DIR = IO0DIR & (~(S0_bm | S1_bm | S2_bm | S3_bm));
}

int main()
{
	LedInit();
	KeyboardInit();
	while(1)
	{
		 switch(eKeyboardRead()){
            case BUTTON_0:
                LedOn(0);
                break;
            case BUTTON_1:
                LedOn(1);
                break;
            case BUTTON_2:
                LedOn(2);
                break;
            case BUTTON_3:
                LedOn(3);
                break;
            case RELASED:
                LedOn(4);
                break;
        }
		/*
		LedInit();
		IO1CLR = LED3_bm;
		LedOn(0);
		Delay(250);
		IO1CLR = LED0_bm;
		LedOn(1);
		Delay(250);
		IO1CLR = LED1_bm;
		LedOn(2);
		Delay(250);
		IO1CLR = LED2_bm;
		LedOn(3);
		Delay(250);
		test = IO0PIN;
		*/
	}
}
