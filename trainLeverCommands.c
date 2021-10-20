#include <RTL.h> 
#include "trainCommandsIO.h"
#include <stm32f10x.h> 

int lastPinLed;
int lastPin;
int state;
int lastState;

int counterTimerNOINPUT = 0;
int counterTimerBrakingInput = 0;
int counterTimerMaxAcceleration = 0;

extern OS_TID BrokenLeverStopTaskID;
extern int pinEvent;

/*----------------------------------------------------------------------------
  Check the position of the lever
 *----------------------------------------------------------------------------*/

void trainLever(){
	
		state = (pinEvent) ? pinEvent : GPIOB->IDR;
	
		if(state != 00000000){
			counterTimerNOINPUT = 0;
		}
		
// 		if(lastState == state){
// 			counterTimerBrakingInput++;
// 			if(counterTimerBrakingInput >= 500){
// 				os_evt_set(1, BrokenLeverStopTaskID);
// 			}
// 		} else {
// 			counterTimerBrakingInput = 0;
// 		}
		
		lastState = state;
	
		switch(state){
			case 1<<maxAcceleration:
				GPIOC->ODR &=  ~(1<<lastPinLed);
				GPIOC->ODR |= 1<<maxAccelerationLed;
				lastPinLed = maxAccelerationLed;
				lastPin = maxAcceleration;
				counterTimerMaxAcceleration++;
				if(counterTimerMaxAcceleration >=  400){
					GPIOC->ODR &=  ~(1<<lastPinLed);
					GPIOC->ODR |= 1<<medAccelerationLed;
					lastPinLed = medAccelerationLed;
					lastPin = medAcceleration;
				}
				counterTimerNOINPUT = 0;
				break;
			case 1<<medAcceleration:
				GPIOC->ODR &=  ~(1<<lastPinLed);
				GPIOC->ODR |= 1<<medAccelerationLed;
				lastPinLed = medAccelerationLed;
				lastPin = medAcceleration;
				counterTimerNOINPUT = 0;
				counterTimerMaxAcceleration = 0;
				break;
			case 1<<minAcceleration:
				GPIOC->ODR &=  ~(1<<lastPinLed);
				GPIOC->ODR |= 1<<minAccelerationLed;
				lastPinLed = minAccelerationLed;
				lastPin = minAcceleration;
			  counterTimerNOINPUT = 0;
				counterTimerMaxAcceleration = 0;
				break;
			case 1<<idleMode:
				GPIOC->ODR &=  ~(1<<lastPinLed);
				//GPIOC->ODR |= 1<<idleModeLed; //turns on the IdleMode led
				lastPinLed = idleModeLed;
				lastPin = idleMode;
				counterTimerNOINPUT = 0;
				counterTimerMaxAcceleration = 0;
				break;
			case 1<<minBraking:
				GPIOC->ODR &=  ~(1<<lastPinLed);
				GPIOC->ODR |= 1<<minBrakingLed;
				lastPinLed = minBrakingLed;
				lastPin = minBraking;
				counterTimerNOINPUT = 0;
				counterTimerMaxAcceleration = 0;
				break;
			case 1<<medBraking:
				GPIOC->ODR &=  ~(1<<lastPinLed);
				GPIOC->ODR |= 1<<medBrakingLed;
				lastPinLed = medBrakingLed;
				lastPin = medBraking;
				counterTimerNOINPUT = 0;
				counterTimerMaxAcceleration = 0;
				break;
			case 1<<maxBraking:
				GPIOC->ODR &=  ~(1<<lastPinLed);
				GPIOC->ODR |= 1<<maxBrakingLed;
				lastPinLed = maxBrakingLed;
				lastPin = maxBraking;
				counterTimerNOINPUT = 0;
				counterTimerMaxAcceleration = 0;
				break;
			case 00000000:
				counterTimerNOINPUT++;
				if(counterTimerNOINPUT >=  300){
					os_evt_set(1, BrokenLeverStopTaskID);
				}
				counterTimerMaxAcceleration = 0;
				break;
			}
}
