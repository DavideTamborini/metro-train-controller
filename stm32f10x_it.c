#include "stm32f10x_it.h"
#include <RTL.h>
#include "trainCommandsIO.h"

extern OS_TID StopTrainSignalID, EmergencyBrakingTaskID, checkTrafficMessageTaskID;

int emergencyActive = 0;
int trafficMessage;

/*----------------------------------------------------------------------------
  Emergency braking Interrupt
 *----------------------------------------------------------------------------*/
 
void EXTI0_IRQHandler(void) {
	EXTI_ClearFlag(EXTI_Line0);
	emergencyActive = 1;
	isr_evt_set(1, EmergencyBrakingTaskID);
}

/*----------------------------------------------------------------------------
  Stop Interrupt
 *----------------------------------------------------------------------------*/

void EXTI1_IRQHandler(void) {
	EXTI_ClearFlag(EXTI_Line1);
	isr_evt_set(1, StopTrainSignalID);
}

/*----------------------------------------------------------------------------
  Message Interrupt
 *----------------------------------------------------------------------------*/

void USART1_IRQHandler(void) {
	if(USART_GetITStatus(USART1, USART_IT_RXNE) != RESET) {
    trafficMessage = USART_ReceiveData(USART1);
		isr_evt_set(1, checkTrafficMessageTaskID);
  }
}
