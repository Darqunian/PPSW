#include "led.h"
#include "keyboard.h"

void Delay(int iLoopTimer){
	iLoopTimer = (iLoopTimer/7.8551)*100000;
	for(  ; iLoopTimer > 0 ; iLoopTimer--){}
}

int main(){
	
	/* Zadanie 1 
	enum LedState {LED_LEFT, LED_RIGHT};
	enum LedState eLedState = LED_LEFT;
	*/
		/* Zadanie 2
	enum LedState {STATE0, STATE1, STATE2, STATE3, STATE4, STATE5};
	enum LedState eLedState = STATE1;
	 */
	
	/* Zadanie 3 
	enum LedState {LED_LEFT, LED_RIGHT};
	enum LedState eLedState = LED_LEFT;
	*/
	
		/* Zadanie 4 
	enum LedState {WORKING, WAITING};
	enum LedState eLedState = WORKING;
	*/
	
		/* Zadanie 5 	
		enum LedState {WORKING, WAITING};
		enum LedState eLedState = WORKING;
		*/
		/* Zadanie 6 */
		enum LedState {LEFT, RIGHT, WAITING, STANDBY};
		enum LedState eLedState = WAITING;
		
		
	LedInit();
	KeyboardInit();
		

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
			case STATE0:
				eLedState = STATE1;
				LedStepLeft();
				break;
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
				LedStepRight();
				break;
		case STATE4:
				eLedState = STATE5;
				LedStepRight();
				break;
		case STATE5:
				eLedState = STATE0;
				LedStepRight();
				break;
		}
		 */
		/* Zadanie 3
		
		unsigned char ucStepCounter;
		
		
		Delay(250);
		switch(eLedState){
			case LED_LEFT:
				if(ucStepCounter<3){
					LedStepLeft();
					ucStepCounter++ ;
					eLedState = LED_LEFT;
				}
				else{
					eLedState = LED_RIGHT;
				}
				break;
			case LED_RIGHT:
				if(ucStepCounter<6){
					LedStepRight();
					ucStepCounter++ ;
					eLedState = LED_RIGHT;
				}
				else{
					eLedState = LED_LEFT;
					ucStepCounter = 0;
				}
				break; 
		}
		 */
		
		/*Zadanie 4
		unsigned char ucStepCounter;
		
		Delay(250);
		switch(eLedState){
			case WAITING:
				if(eKeyboardRead()== BUTTON_0){
					eLedState = WORKING;
				}
				else{
					eLedState = WAITING;
				}
				break;
			case WORKING:
				if(ucStepCounter<3){
					LedStepRight();
					ucStepCounter++;
					eLedState = WORKING;
				}
				else{
					eLedState = WAITING;
					ucStepCounter = 0;
				}
				break;
		}
		*/

		/* Zadanie 5 
			
		Delay(250);
		switch(eLedState){
			case WAITING:
				if(eKeyboardRead()== BUTTON_1){
					eLedState = WORKING;
				}
				eLedState = WAITING;
				break;
			case WORKING:
				if(eKeyboardRead()== BUTTON_0){
					eLedState = WAITING;
					break;
				}
				LedStepRight();
				eLedState = WORKING;
				break;
			}
			*/
		
		/* Zadanie 6 */
		
		
		Delay(100);
		switch(eLedState){
			case WAITING:
				if(eKeyboardRead()== BUTTON_0){
					eLedState = LEFT;
					break;
				}
				else if (eKeyboardRead()== BUTTON_2){
					eLedState = RIGHT;
					break;
				}
				else{
					eLedState = WAITING;
					break;
				}
			case LEFT:
				if(eKeyboardRead()== BUTTON_1){
					eLedState = WAITING;
					break;
				}
				else if(eKeyboardRead()== BUTTON_3){
					eLedState = STANDBY;
					break;
				}
				else{
					LedStepLeft();
					eLedState = LEFT;
					break;
				}
			case RIGHT:
				if (eKeyboardRead()== BUTTON_1){
					eLedState = WAITING;
					break;
				}
				else if(eKeyboardRead()== BUTTON_3){
					eLedState = STANDBY;
					break;
				}
				else{
					LedStepRight();
					eLedState = RIGHT;
					break;
				}
			case  STANDBY:
					if(eKeyboardRead()== BUTTON_0){
						eLedState = LEFT;
					}
					else if (eKeyboardRead()== BUTTON_2){
						eLedState = RIGHT;
					}
					
			}
	}
}
