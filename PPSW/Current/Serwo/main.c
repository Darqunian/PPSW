#include "timer_interrupts.h"
#include "led.h"
#include "keyboard.h"

void Automat(void){
		enum LedState {LEFT, RIGHT, WAITING};
		static enum LedState eLedState = WAITING;
		
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
					break;
				}
			case LEFT:
				if(eKeyboardRead()== BUTTON_1){
					eLedState = WAITING;
					break;
				}
				else{
					LedStepLeft();
					break;
				}
			case RIGHT:
				if(eKeyboardRead()== BUTTON_1){
					eLedState = WAITING;
					break;
				}
				else{
					LedStepRight();
					break;
				}
					
			}
	}

/**********************************************/
int main (){
	unsigned int iMainLoopCtr;
	
	LedInit();
	KeyboardInit();

	while(1){
	 	iMainLoopCtr++;
		Timer0Interrupts_Init(20000, &Automat);
	}
}
