/**
  ********************************  STM32F10x  *********************************
  * @�ļ���     �� bsp_usart.c
  * @����       �� xuyifei
  * @��汾     �� V3.5.0
  * @�ļ��汾   �� V1.0.0
  * @����       �� 2020��3��18��
  * @ժҪ       �� BSP�弶֧�ְ�Դ�ļ�
  ******************************************************************************/
/*----------------------------------------------------------------------------
  ������־:
  2020-3-18 V1.0.0:��ʼ�汾
  ----------------------------------------------------------------------------*/
/* ������ͷ�ļ� --------------------------------------------------------------*/
#include "bsp_usart.h"

static void NVIC_Configuration(void)
{
  NVIC_InitTypeDef NVIC_InitStructure;
  
  /* Ƕ�������жϿ�������ѡ�� */
  NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
  
  /* ����USARTΪ�ж�Դ */
  NVIC_InitStructure.NVIC_IRQChannel = USART_IRQ;
  /* �������ȼ�*/
  NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;
  /* �����ȼ� */
  NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;
  /* ʹ���ж� */
  NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
  /* ��ʼ������NVIC */
  NVIC_Init(&NVIC_InitStructure);
}

void USART_Config(void)
{
  GPIO_InitTypeDef GPIO_InitStructure;
  USART_InitTypeDef USART_InitStructure;

  // �򿪴���GPIO��ʱ��
  RCC_APB2PeriphClockCmd(USART_GPIO_CLK, ENABLE);

  // �򿪴��������ʱ��
  RCC_APB2PeriphClockCmd(USART_CLK, ENABLE);

  // ��USART Tx��GPIO����Ϊ���츴��ģʽ
  GPIO_InitStructure.GPIO_Pin = USART_TX_GPIO_PIN;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(USART_TX_GPIO_PORT, &GPIO_InitStructure);

  // ��USART Rx��GPIO����Ϊ��������ģʽ
  GPIO_InitStructure.GPIO_Pin = USART_RX_GPIO_PIN;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
  GPIO_Init(USART_RX_GPIO_PORT, &GPIO_InitStructure);

  // ���ô��ڵĹ�������
  // ���ò�����
  USART_InitStructure.USART_BaudRate = USART_BAUDRATE;
  // ���� �������ֳ�
  USART_InitStructure.USART_WordLength = USART_WordLength_8b;
  // ����ֹͣλ
  USART_InitStructure.USART_StopBits = USART_StopBits_1;
  // ����У��λ
  USART_InitStructure.USART_Parity = USART_Parity_No ;
  // ����Ӳ��������
  USART_InitStructure.USART_HardwareFlowControl = 
  USART_HardwareFlowControl_None;
  // ���ù���ģʽ���շ�һ��
  USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;
  // ��ɴ��ڵĳ�ʼ������
  USART_Init(USARTx, &USART_InitStructure);

  // �����ж����ȼ�����
  NVIC_Configuration();

  // ʹ�ܴ��ڽ����ж�
  USART_ITConfig(USARTx, USART_IT_RXNE, ENABLE);	

  // ʹ�ܴ���
  USART_Cmd(USARTx, ENABLE);	    
}


