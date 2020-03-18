/**
  ********************************  STM32F10x  *********************************
  * @�ļ���     �� bsp_usart.h
  * @����       �� xuyifei
  * @��汾     �� V3.5.0
  * @�ļ��汾   �� V1.0.0
  * @����       �� 2020��3��18��
  * @ժҪ       �� BSP�弶֧�ְ�ͷ�ļ�
  ******************************************************************************/

/* �����ֹ�ݹ���� ----------------------------------------------------------*/
#ifndef _BSP_H
#define _BSP_H

/* ������ͷ�ļ� --------------------------------------------------------------*/
#include "stm32f10x.h"


/* �궨�� --------------------------------------------------------------------*/
// ����1-USART1
#define  USARTx                   USART1
#define  USART_CLK                RCC_APB2Periph_USART1
#define  USART_BAUDRATE           9600

// USART GPIO ���ź궨��
#define  USART_GPIO_CLK           (RCC_APB2Periph_GPIOA)
    
#define  USART_TX_GPIO_PORT       GPIOA   
#define  USART_TX_GPIO_PIN        GPIO_Pin_9
#define  USART_RX_GPIO_PORT       GPIOA
#define  USART_RX_GPIO_PIN        GPIO_Pin_10

#define  USART_IRQ                USART1_IRQn
#define  USART_IRQHandler         USART1_IRQHandler


/* �������� ------------------------------------------------------------------*/
void USART_Config(void);


#endif /* _BSP_H */

