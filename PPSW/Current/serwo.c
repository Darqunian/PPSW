#include <LPC21xx.H>
#include "timer_interrupts.h"
#include "led.h"
#include "serwo.h"

#define DETECTOR (1<<10)

void DetectorInit(void){
	IO0DIR = IO0DIR & (~DETECTOR);
}

enum DetectorState {ACTIVE, INACTIVE};

enum DetectorState eReadDetector(void) {
	if((IO0PIN & DETECTOR) == 0) {
		return ACTIVE;
	}
	else{
		return INACTIVE;
	}
}

enum ServoState {CALLIB, IDLE, IN_PROGRESS};

struct Servo{
	enum ServoState eState; 
	unsigned int uiCurrentPosition; 
	unsigned int uiDesiredPosition;
}; 

struct Servo sServo;

void Automat(){
	
	switch(sServo.eState) {
		case CALLIB:
			if(eReadDetector() == ACTIVE) {
				sServo.uiCurrentPosition = 0;
			} else {
				if(sServo.uiCurrentPosition>24){
					LedStepRight();
				}
				else{
					LedStepLeft();
				}
				sServo.eState = CALLIB;
			}
			break;
		case IDLE:
			if(sServo.uiCurrentPosition == sServo.uiDesiredPosition) {
				sServo.eState = IDLE;
			} else {
				sServo.eState = IN_PROGRESS;
			}
			break;
		case IN_PROGRESS:
			if(sServo.uiCurrentPosition == sServo.uiDesiredPosition) {
				sServo.eState = IDLE;
			} else {
				if(sServo.uiCurrentPosition < sServo.uiDesiredPosition) {
					LedStepRight();
					sServo.uiCurrentPosition += 1;
				} else {
					LedStepLeft();
					sServo.uiCurrentPosition -= 1;
				}
			}
			break;
	}
}

void ServoInit(unsigned int uiServoFrequency){
	uiServoFrequency = (1000000/uiServoFrequency);
	DetectorInit();
	LedInit();
	sServo.eState = CALLIB;
	Timer0Interrupts_Init(uiServoFrequency, &Automat);
}

void ServoCallib(void) {
	sServo.eState = CALLIB;
}

void ServoGoTo(unsigned int uiPosition){
	sServo.uiDesiredPosition = uiPosition;
	sServo.eState = IN_PROGRESS;
	while(sServo.eState == IN_PROGRESS) {};
}
