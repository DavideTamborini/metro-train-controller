#include <stm32f10x.h>                       /* STM32F10x definitions         */

#ifdef __DBG_ITM
volatile int ITM_RxBuffer = ITM_RXBUFFER_EMPTY;  /*  CMSIS Debug Input        */
#endif

NVIC_InitTypeDef NVIC_InitStructureUSART;

/*----------------------------------------------------------------------------
  Initialize UART pins, Baudrate and configure NVIC
 *----------------------------------------------------------------------------*/
void Usart1Cofig(void) {
#ifndef __DBG_ITM
  int i;

  RCC->APB2ENR |=  (   1UL <<  0);         /* enable clock Alternate Function */
  AFIO->MAPR   &= ~(   1UL <<  2);         /* clear USART1 remap              */

  RCC->APB2ENR |=  (   1UL <<  2);         /* enable GPIOA clock              */
  GPIOA->CRH   &= ~(0xFFUL <<  4);         /* clear PA9, PA10                 */
  GPIOA->CRH   |=  (0x0BUL <<  4);         /* USART1 Tx (PA9) output push-pull*/
  GPIOA->CRH   |=  (0x04UL <<  8);         /* USART1 Rx (PA10) input floating */

  RCC->APB2ENR |=  (   1UL << 14);         /* enable USART1 clock             */

  /* 115200 baud, 8 data bits, 1 stop bit, no flow control */
  USART1->CR1   = 0x002C;                  /* enable RX, TX                   */
  USART1->CR2   = 0x0000;
  USART1->CR3   = 0x0000;                  /* no flow control                 */
  USART1->BRR   = 0x0271;
  for (i = 0; i < 0x1000; i++) __NOP();    /* avoid unwanted output           */
  USART1->CR1  |= 0x2000;                    /* enable USART                   */
	
  NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
	NVIC_InitStructureUSART.NVIC_IRQChannel = USART1_IRQn;
  NVIC_InitStructureUSART.NVIC_IRQChannelSubPriority = 0;
  NVIC_InitStructureUSART.NVIC_IRQChannelCmd = ENABLE;
  NVIC_Init(&NVIC_InitStructureUSART);

#endif
}

/*----------------------------------------------------------------------------
  Write character to Serial Port
 *----------------------------------------------------------------------------*/
int SER_PutChar (int c) {

#ifdef __DBG_ITM
    ITM_SendChar(c);
#else
  while (!(USART1->SR & USART_SR_TXE));
  USART1->DR = (c & 0x1FF);
#endif
  return (c);
}


/*----------------------------------------------------------------------------
  Read character from Serial Port   (blocking read)
 *----------------------------------------------------------------------------*/
int SER_GetChar (void) {

#ifdef __DBG_ITM
  while (ITM_CheckChar() != 1) __NOP();
  return (ITM_ReceiveChar());
#else
  while (!(USART1->SR & USART_SR_RXNE));
  return (USART1->DR & 0xFF);
#endif
}


/*----------------------------------------------------------------------------
  Check if a character is received
 *----------------------------------------------------------------------------*/
int SER_CheckChar (void) {

#ifdef __DBG_ITM
  return (ITM_CheckChar());
#else
  if (USART1->SR & USART_SR_RXNE)
    return (1);
  else
    return (0);
#endif
}
