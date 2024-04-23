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
	/* Zadanie 1
	enum LedState {LED_LEFT, LED_RIGHT};
	enum LedState eLedState = LED_LEFT;
	*/	

	/* Zadanie 2
	enum LedState {STATE1, STATE2, STATE3, STATE4, STATE5, STATE6};
	enum LedState eLedState = STATE1;
	*/
	
	/* Zadanie 3
	enum LedState {LED_LEFT, LED_RIGHT};
	enum LedState eLedState = LED_LEFT;
	*/
	
	/* Zadanie 4
	enum LedState {WORKING, WAITING};
	enum LedState eLedState = WAITING;
	
	*/

	while(1)
	{
		/* Zadanie 1
		Delay(250);
		switch(eLedState){
			case LED_LEFT:
				eLedState = LED_RIGHT;
				LedStepLeft();
				break;
			case LED_RIGHT:
				eLedState = LED_LEFT;
				LedStepRight();
				break;
			default:
				break;
		}
		*/	 
		
		/* Zadanie 2
		Delay(250);
		switch (eLedState){
			case STATE1:
				eLedState = STATE2;
				LedStepLeft();
				break;
		case STATE2:
				eLedState = STATE3;
				LedStepLeft();
				break;
		case STATE3:
				eLedState = STATE4;
				LedStepLeft();
				break;
		case STATE4:
				eLedState = STATE5;
				LedStepRight();
				break;
		case STATE5:
				eLedState = STATE6;
				LedStepRight();
				break;
		case STATE6:
				eLedState = STATE1;
				LedStepRight();
				break;
		}
		*/
		/* Zadanie 3
		
		unsigned char ucLedPosition;
		ucLedPosition = 0;
		
		Delay(250);
		switch(eLedState){
			case LED_LEFT:
				if(ucLedPosition<3){
					LedStepLeft();
					ucLedPosition++ ;
				}
				else{
					eLedState = LED_RIGHT;
				}
				break;
			case LED_RIGHT:
				if(ucLedPosition<6){
					LedStepRight();
					ucLedPosition++ ;
				}
				else{
					eLedState = LED_LEFT;
					ucLedPosition = 0;
				}
				break; 
		}
		*/
		
		/*Zadanie 4
		unsigned char ucLedPosition;
		ucLedPosition = 0;
		
		Delay(250);
		switch(eLedState){
			case WAITING:
				if(eKeyboardRead()== BUTTON_0){
					eLedState = WORKING;
				}
				break;
			case WORKING:
				if(ucLedPosition<3){
					LedStepRight();
					ucLedPosition = 0;
				}
				else{
					eLedState = WAITING;
				}
				break;
		}
		*/

		
	}
}
