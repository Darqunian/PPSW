#include <LPC21xx.H>
#include "led.h"
#include "keyboard.h"

void Delay(int iLoopTimer){
	iLoopTimer = (iLoopTimer/7.8551)*100000;
	for(  ; iLoopTimer > 0 ; iLoopTimer--){}
}

int main(){
	
	LedInit();
	KeyboardInit();
	
	while(1)
	{
		Delay(250);
		switch(eKeyboardRead()){
			case BUTTON_1:
				LedStepRight();
				break;
			case BUTTON_2:
				LedStepLeft();
				break;
			default:
				break;
		}	 
		/*
		Delay(250);
		switch(eKeyboardRead()){
			case BUTTON_1:
				LedStep(RIGHT);
				break;
			case BUTTON_2:
				LedStep(LEFT);
				break;
			case RELEASED:
				break;
		}	 
		*/		 
		/*
		Delay(250);
		LedStep(RIGHT);
		*/
		/*
		Delay(250);
		LedStep(LEFT);
		*/
		/*
		Delay(250);
		StepRight();
		*/
		/*
		Delay(250);
		StepLeft();
		*/
		/*
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
		*/
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
		*/
	}
}
