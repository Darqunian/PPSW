#include "keyboard.h"
#include "serwo.h"

/**********************************************/
int main (){
	
	enum ButtonState eKeyboardState;
	
	KeyboardInit();
	ServoInit(20);

	while(1){
		eKeyboardState = eKeyboardRead();
		switch(eKeyboardState) {
				case BUTTON_0:
					ServoCallib();
					break;
				case BUTTON_1:
					ServoGoTo(12);
					break;
				case BUTTON_2:
					ServoGoTo(24);
					break;
				case BUTTON_3:
					ServoGoTo(36);
					break;
				default:
					break;
		}
	}
}
