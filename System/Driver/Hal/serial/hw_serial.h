/*********************************************************
  Copyright (C), 2013-2016
  File name:	hw_serial.h
  Author:   	
  Version:   	1.0
  Date: 		
  Description:  
  History:                   
    1. Date:
       Author:
       Modification:
    2. ...
*********************************************************/
#ifndef _HW_SERIAL_H_
#define _HW_SERIAL_H_

#include "stm32f10x.h"

#ifdef __cplusplus
 extern "C" {
#endif 


#define USART_PORT1             	  USART1
#define USART_PORT1_GPIO              GPIOA
#define USART_PORT1_CLK               RCC_APB2Periph_USART1
#define USART_PORT1_GPIO_CLK          RCC_APB2Periph_GPIOA
#define USART_PORT1_RxPin             GPIO_Pin_10
#define USART_PORT1_TxPin             GPIO_Pin_9
#define	USART_PORT1_Remap_GPIO		  GPIO_Remap_USART1
#define USART_PORT1_Tx_DMA_Channel    DMA1_Channel4
#define USART_PORT1_Tx_DMA_FLAG       DMA1_FLAG_TC4
#define USART_PORT1_Tx_DMA_IRQ		  DMA1_Channel4_IRQn
#define USART_PORT1_DR_Base           0x40013804
#define USART_PORT1_IRQn              USART1_IRQn
#define USART_PORT1_BAUDRATE 		  115200

#define USART_PORT2                   USART2
#define USART_PORT2_GPIO              GPIOA
#define USART_PORT2_CLK               RCC_APB1Periph_USART2
#define USART_PORT2_GPIO_CLK          RCC_APB2Periph_GPIOA
#define USART_PORT2_RxPin             GPIO_Pin_3
#define USART_PORT2_TxPin             GPIO_Pin_2
#define	USART_PORT2_Remap_GPIO		  GPIO_Remap_USART2 
#define USART_PORT2_Tx_DMA_Channel    DMA1_Channel7
#define USART_PORT2_Tx_DMA_FLAG       DMA1_FLAG_TC7
#define USART_PORT2_Tx_DMA_IRQ		  DMA1_Channel7_IRQn 
#define USART_PORT2_DR_Base           0x40004404
#define USART_PORT2_IRQn              USART2_IRQn
#define USART_PORT2_BAUDRATE 		  115200

#define USART_PORT3                   USART3
#define USART_PORT3_GPIO              GPIOB
#define USART_PORT3_CLK               RCC_APB1Periph_USART3
#define USART_PORT3_GPIO_CLK          RCC_APB2Periph_GPIOB
#define USART_PORT3_RxPin             GPIO_Pin_11
#define USART_PORT3_TxPin             GPIO_Pin_10
#define	USART_PORT3_Remap_GPIO		  GPIO_PartialRemap_USART3
#define USART_PORT3_Tx_DMA_Channel    DMA1_Channel2
#define USART_PORT3_Tx_DMA_FLAG       DMA1_FLAG_TC2
#define USART_PORT3_Tx_DMA_IRQ		  DMA1_Channel2_IRQn
#define USART_PORT3_DR_Base           0x40004804
#define USART_PORT3_IRQn              USART3_IRQn
#define USART_PORT3_BAUDRATE 		  115200

/*************************************************
  Function:		hw_serial_init
  Description:  
  Input:		
  Output:		
  Return:		
  Others:
*************************************************/
void hw_serial_init(void);

/*************************************************
  Function:		hw_serial_printf
  Description:  
  Input:		
  Output:		
  Return:		
  Others:
*************************************************/
void hw_serial_printf(const char *fmt, ...);

/*************************************************
  Function:		hw_serial_send_rs232
  Description:  
  Input:		
  Output:		
  Return:		
  Others:
*************************************************/
void hw_serial_send_gps(uint32_t buf, uint16_t len);

/*************************************************
  Function:		hw_serial_send_gprs
  Description:  
  Input:		
  Output:		
  Return:		
  Others:
*************************************************/
void hw_serial_send_gprs(uint32_t buf, uint16_t len);

/*************************************************
  Function:		hw_serial_send_rs232
  Description:  
  Input:		
  Output:		
  Return:		
  Others:
*************************************************/
void hw_serial_send_rs232(uint32_t buf, uint16_t len);

#ifdef __cplusplus
}
#endif

#endif
