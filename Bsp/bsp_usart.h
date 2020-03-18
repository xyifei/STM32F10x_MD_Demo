/**
  ********************************  STM32F10x  *********************************
  * @文件名     ： bsp_usart.h
  * @作者       ： xuyifei
  * @库版本     ： V3.5.0
  * @文件版本   ： V1.0.0
  * @日期       ： 2020年3月18日
  * @摘要       ： BSP板级支持包头文件
  ******************************************************************************/

/* 定义防止递归包含 ----------------------------------------------------------*/
#ifndef _BSP_H
#define _BSP_H

/* 包含的头文件 --------------------------------------------------------------*/
#include "stm32f10x.h"


/* 宏定义 --------------------------------------------------------------------*/
// 串口1-USART1
#define  USARTx                   USART1
#define  USART_CLK                RCC_APB2Periph_USART1
#define  USART_BAUDRATE           9600

// USART GPIO 引脚宏定义
#define  USART_GPIO_CLK           (RCC_APB2Periph_GPIOA)
    
#define  USART_TX_GPIO_PORT       GPIOA   
#define  USART_TX_GPIO_PIN        GPIO_Pin_9
#define  USART_RX_GPIO_PORT       GPIOA
#define  USART_RX_GPIO_PIN        GPIO_Pin_10

#define  USART_IRQ                USART1_IRQn
#define  USART_IRQHandler         USART1_IRQHandler


/* 函数申明 ------------------------------------------------------------------*/
void USART_Config(void);


#endif /* _BSP_H */

