#include "led.h"
#include "keyboard.h"
#include "timer.h"

int main(){
	
	//InitTimer0();
	LedInit();
	InitTimer0Match0(250000);
					
	while(1){
		//WaitOnTimer0(250000);
		//LedStepLeft();
		WaitOnTimer0Match0();
		LedStepLeft();
	}
}
