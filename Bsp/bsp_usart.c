/**
  ********************************  STM32F10x  *********************************
  * @文件名     ： bsp_usart.c
  * @作者       ： xuyifei
  * @库版本     ： V3.5.0
  * @文件版本   ： V1.0.0
  * @日期       ： 2020年3月18日
  * @摘要       ： BSP板级支持包源文件
  ******************************************************************************/
/*----------------------------------------------------------------------------
  更新日志:
  2020-3-18 V1.0.0:初始版本
  ----------------------------------------------------------------------------*/
/* 包含的头文件 --------------------------------------------------------------*/
#include "bsp_usart.h"

static void NVIC_Configuration(void)
{
  NVIC_InitTypeDef NVIC_InitStructure;
  
  /* 嵌套向量中断控制器组选择 */
  NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
  
  /* 配置USART为中断源 */
  NVIC_InitStructure.NVIC_IRQChannel = USART_IRQ;
  /* 抢断优先级*/
  NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;
  /* 子优先级 */
  NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;
  /* 使能中断 */
  NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
  /* 初始化配置NVIC */
  NVIC_Init(&NVIC_InitStructure);
}

void USART_Config(void)
{
  GPIO_InitTypeDef GPIO_InitStructure;
  USART_InitTypeDef USART_InitStructure;

  // 打开串口GPIO的时钟
  RCC_APB2PeriphClockCmd(USART_GPIO_CLK, ENABLE);

  // 打开串口外设的时钟
  RCC_APB2PeriphClockCmd(USART_CLK, ENABLE);

  // 将USART Tx的GPIO配置为推挽复用模式
  GPIO_InitStructure.GPIO_Pin = USART_TX_GPIO_PIN;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(USART_TX_GPIO_PORT, &GPIO_InitStructure);

  // 将USART Rx的GPIO配置为浮空输入模式
  GPIO_InitStructure.GPIO_Pin = USART_RX_GPIO_PIN;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
  GPIO_Init(USART_RX_GPIO_PORT, &GPIO_InitStructure);

  // 配置串口的工作参数
  // 配置波特率
  USART_InitStructure.USART_BaudRate = USART_BAUDRATE;
  // 配置 针数据字长
  USART_InitStructure.USART_WordLength = USART_WordLength_8b;
  // 配置停止位
  USART_InitStructure.USART_StopBits = USART_StopBits_1;
  // 配置校验位
  USART_InitStructure.USART_Parity = USART_Parity_No ;
  // 配置硬件流控制
  USART_InitStructure.USART_HardwareFlowControl = 
  USART_HardwareFlowControl_None;
  // 配置工作模式，收发一起
  USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;
  // 完成串口的初始化配置
  USART_Init(USARTx, &USART_InitStructure);

  // 串口中断优先级配置
  NVIC_Configuration();

  // 使能串口接收中断
  USART_ITConfig(USARTx, USART_IT_RXNE, ENABLE);	

  // 使能串口
  USART_Cmd(USARTx, ENABLE);	    
}


