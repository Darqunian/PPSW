#include <LPC21xx.H>

#define LED0_bm 1<<16
#define LED1_bm 1<<17
#define LED2_bm 1<<18
#define LED3_bm 1<<19

#define S0_bm 1<<4
#define S1_bm 1<<6
#define S2_bm 1<<5
#define S3_bm 1<<7

enum ButtonState {RELEASED, BUTTON_0, BUTTON_1, BUTTON_2, BUTTON_3};
enum LedDirection {LEFT, RIGHT};

void Delay(int iLoopTimer){
	iLoopTimer = (iLoopTimer/7.8551)*100000;
	for(  ; iLoopTimer > 0 ; iLoopTimer--){}
}

void LedInit(){
	IO1DIR = IO1DIR | LED0_bm | LED1_bm | LED2_bm | LED3_bm;
	IO1SET = LED0_bm;
}

void LedOn(unsigned char ucLedIndeks){
	IO1CLR = LED0_bm | LED1_bm | LED2_bm | LED3_bm;
	switch (ucLedIndeks){
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
			break;
		}
}

enum ButtonState eKeyboardRead(){
	if((IO0PIN & S0_bm) == 0){
		return BUTTON_0; //sam iloczyn dla 1/0
	}
	else if((IO0PIN & S1_bm) == 0){ //  puszczony 0x40  wcisniety 0x00
		return BUTTON_1;
  }
	else if((IO0PIN & S2_bm) == 0){ // puszczony 0x20 wcisniety 0x00
    return BUTTON_2;
  }
	else if((IO0PIN & S3_bm) == 0){
    return BUTTON_3;
  }
	else{
    return RELEASED;
  }
}

void KeyboardInit(){
    IO0DIR = IO0DIR & (~(S0_bm | S1_bm | S2_bm | S3_bm)); //Tutaj jest negacja poniewaz kontrolujemy kierunek poszczegolnych pinow, chcemy odczytywac stan przyciskow, odczytywanie jest dla DIR = 0 a zapis dla DIR = 1, a define ustawia 1 na danym porcie
}

void LedStep(enum LedDirection Direction){
	
	static unsigned int uiCurrentLed;
	
	if(Direction == LEFT){
		uiCurrentLed++;
	}
	else if(Direction == RIGHT){
		uiCurrentLed--;
	}
	LedOn(uiCurrentLed%4);
}

void LedStepLeft(void){
	LedStep(LEFT);
}

void LedStepRight(void){
	LedStep(RIGHT);
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
