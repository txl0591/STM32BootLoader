/*********************************************************
  Copyright (C), 2013-2016
  File name:	hw_serial_init.c
  Author:   	
  Version:   	1.0
  Date: 		14.04.08
  Description:  
  History:                   
    1. Date:
       Author:
       Modification:
    2. ...
*********************************************************/
#include "hw_define.h"

USART_TypeDef* Get_USART(uint8_t n)
{
	switch (n)
	{
		case 1:
			return USART_PORT1;

		case 2:
			return USART_PORT2;

		case 3:
			return USART_PORT3;
	}

	return USART_PORT1;
}

 GPIO_TypeDef* Get_USART_GPIO(uint8_t n)
{
	switch (n)
	{
		case 1:
			return USART_PORT1_GPIO;

		case 2:
			return USART_PORT2_GPIO;

		case 3:
			return USART_PORT3_GPIO;
	}

	return USART_PORT1_GPIO;
}

 int Get_USART_BAUDRATE(uint8_t n)
{
	switch (n)
	{
		case 1:
			return USART_PORT1_BAUDRATE;

		case 2:
			return USART_PORT2_BAUDRATE;

		case 3:
			return USART_PORT3_BAUDRATE;
	}

	return USART_PORT1_BAUDRATE;
}

 uint32_t Get_USART_CLK(uint8_t n)
{
	switch (n)
	{
		case 1:
			return USART_PORT1_CLK;

		case 2:
			return USART_PORT2_CLK;

		case 3:
			return USART_PORT3_CLK;
	}

	return USART_PORT1_CLK;
}

 uint32_t Get_USART_GPIO_CLK(uint8_t n)
{
	switch (n)
	{
		case 1:
			return USART_PORT1_GPIO_CLK;

		case 2:
			return USART_PORT2_GPIO_CLK;

		case 3:
			return USART_PORT3_GPIO_CLK;
	}

	return USART_PORT1_GPIO_CLK;
}

 uint16_t Get_USART_RxPin(uint8_t n)
{
	switch (n)
	{
		case 1:
			return USART_PORT1_RxPin;

		case 2:
			return USART_PORT2_RxPin;

		case 3:
			return USART_PORT3_RxPin;
	}

	return USART_PORT1_RxPin;
}

 uint16_t Get_USART_TxPin(uint8_t n)
{
	switch (n)
	{
		case 1:
			return USART_PORT1_TxPin;

		case 2:
			return USART_PORT2_TxPin;

		case 3:
			return USART_PORT3_TxPin;
	}

	return USART_PORT1_TxPin;
}

 uint32_t Get_USART_Remap_GPIO(uint8_t n)
{
	switch (n)
	{
		case 1:
			return USART_PORT1_Remap_GPIO;

		case 2:
			return USART_PORT2_Remap_GPIO;

		case 3:
			return USART_PORT3_Remap_GPIO;
	}

	return USART_PORT1_Remap_GPIO;
}

 DMA_Channel_TypeDef* Get_USART_Tx_DMA_Channel(uint8_t n)
{
	switch (n)
	{
		case 1:
			return USART_PORT1_Tx_DMA_Channel;

		case 2:
			return USART_PORT2_Tx_DMA_Channel;

		case 3:
			return USART_PORT3_Tx_DMA_Channel;
	}

	return USART_PORT1_Tx_DMA_Channel;
}

 uint32_t Get_USART_Tx_DMA_FLAG(uint8_t n)
{
	switch (n)
	{
		case 1:
			return USART_PORT1_Tx_DMA_FLAG;

		case 2:
			return USART_PORT2_Tx_DMA_FLAG;

		case 3:
			return USART_PORT3_Tx_DMA_FLAG;
	}

	return USART_PORT1_Tx_DMA_FLAG;
}

 uint32_t Get_USART_Tx_DMA_IRQ(uint8_t n)
{
	switch (n)
	{
		case 1:
			return USART_PORT1_Tx_DMA_IRQ;

		case 2:
			return USART_PORT2_Tx_DMA_IRQ;

		case 3:
			return USART_PORT3_Tx_DMA_IRQ;
	}

	return USART_PORT1_Tx_DMA_IRQ;
}

 uint32_t Get_USART_DR_Base(uint8_t n)
{
	switch (n)
	{
		case 1:
			return USART_PORT1_DR_Base;

		case 2:
			return USART_PORT2_DR_Base;

		case 3:
			return USART_PORT3_DR_Base;
	}

	return USART_PORT1_DR_Base;
}

 uint32_t Get_USART_IRQn(uint8_t n)
{
	switch (n)
	{
		case 1:
			return USART_PORT1_IRQn;

		case 2:
			return USART_PORT2_IRQn;

		case 3:
			return USART_PORT3_IRQn;
	}

	return USART_PORT1_IRQn;
}

#define USART(n)					 Get_USART(n)
#define USART_GPIO(n) 		         Get_USART_GPIO(n) 
#define USART_CLK(n)             	 Get_USART_CLK(n)
#define USART_GPIO_CLK(n)          	 Get_USART_GPIO_CLK(n)
#define USART_RxPin(n)             	 Get_USART_RxPin(n)
#define USART_TxPin(n)               Get_USART_TxPin(n)
#define USART_Remap_GPIO(n) 		 Get_USART_Remap_GPIO(n)
#define USART_Tx_DMA_Channel(n)      Get_USART_Tx_DMA_Channel(n)
#define USART_Tx_DMA_FLAG(n)         Get_USART_Tx_DMA_FLAG(n)
#define USART_Tx_DMA_IRQ(n)		 	 Get_USART_Tx_DMA_IRQ(n)
#define USART_DR_Base(n)             Get_USART_DR_Base(n)
#define USART_IRQn(n)                Get_USART_IRQn(n)
#define USART_BAUDRATE(n) 		     Get_USART_BAUDRATE(n)

#ifdef __GNUC__
#define PUTCHAR_PROTOTYPE int __io_putchar(int ch)
#else
#define PUTCHAR_PROTOTYPE int fputc(int ch, FILE *f)
#endif 

#if(USART_DEBUG != USART_NONE)
/*************************************************
  Function:		fputc
  Description:  
  Input:		
  Output:		
  Return:		
  Others:
*************************************************/
#ifdef __GNUC__
int __io_putchar(int ch)
#else
int fputc(int ch, FILE *f)
#endif 
{

  USART_SendData(USART(USART_DEBUG), (uint8_t) ch);
  /* Loop until the end of transmission */
  while (USART_GetFlagStatus(USART(USART_DEBUG), USART_FLAG_TC) == RESET)
  {}

  return ch;
}
#endif

/*************************************************
  Function:		hw_serial_printf
  Description:  
  Input:		
  Output:		
  Return:		
  Others:
*************************************************/
void hw_serial_printf(const char *fmt, ...)
{
	#if(USART_DEBUG != USART_NONE)
	printf(fmt);
	#endif
}

/*************************************************
  Function:		DMA1_Channel2_IRQHandler
  Description:  
  Input:		
  Output:		
  Return:		
  Others:
*************************************************/
void DMA1_Channel2_IRQHandler(void)
{
	DMA_ClearFlag(USART_Tx_DMA_FLAG(USART_RS232));
	DMA_Cmd(USART_Tx_DMA_Channel(USART_RS232), DISABLE);
}

/*************************************************
  Function:		DMA1_Channel2_IRQHandler
  Description:  
  Input:		
  Output:		
  Return:		
  Others:
*************************************************/
void DMA1_Channel4_IRQHandler(void)
{
  	DMA_ClearFlag(USART_Tx_DMA_FLAG(USART_GPRS));
	DMA_Cmd(USART_Tx_DMA_Channel(USART_GPRS), DISABLE);
}

/*************************************************
  Function:		DMA1_Channel7_IRQHandler
  Description:  
  Input:		
  Output:		
  Return:		
  Others:
*************************************************/
void DMA1_Channel7_IRQHandler(void)
{
	DMA_ClearFlag(USART_Tx_DMA_FLAG(USART_GPS));

	DMA_Cmd(USART_Tx_DMA_Channel(USART_GPS), DISABLE);
}

/*************************************************
  Function:		USART1_IRQHandler
  Description:  
  Input:		
  Output:		
  Return:		
  Others:
*************************************************/
void USART1_IRQHandler(void)
{
	
}

/*************************************************
  Function:		USART2_IRQHandler
  Description:  
  Input:		
  Output:		
  Return:		
  Others:
*************************************************/
void USART2_IRQHandler(void)
{
    char data = 0x00;
    if(USART_GetITStatus(Get_USART(USART_GPS), USART_IT_RXNE) != RESET)
    {
        data = USART_ReceiveData(Get_USART(USART_GPS));
        hw_serial_printf(&data);
    }    
}

/*************************************************
  Function:		USART3_IRQHandler
  Description:  
  Input:		
  Output:		
  Return:		
  Others:
*************************************************/
void USART3_IRQHandler(void)
{
	char data = 0x00;
    if(USART_GetITStatus(Get_USART(USART_RS232), USART_IT_RXNE) != RESET)
    {
        data = USART_ReceiveData(Get_USART(USART_RS232));
        hw_serial_printf(&data);
    }   
}

/*************************************************
  Function:		hw_usart_configures
  Description:  
  Input:		
  Output:		
  Return:		
  Others:
*************************************************/
static void hw_usart_configures(uint8_t port, uint32_t BaudRate)
{
	/*USARTy configuration*/
	USART_InitTypeDef USART_InitStructure;

	USART_InitStructure.USART_BaudRate = BaudRate;
	USART_InitStructure.USART_WordLength = USART_WordLength_8b;
	USART_InitStructure.USART_StopBits = USART_StopBits_1;
	USART_InitStructure.USART_Parity = USART_Parity_No;
	USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
	USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;

	/* Configure USART */
	USART_Init(USART(port), &USART_InitStructure);
	
	/* Enable the USART Receive Interrupt */
	USART_ITConfig(USART(port), USART_IT_RXNE, ENABLE);
	
	NVIC_InitTypeDef NVIC_InitStructure;
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);  
	NVIC_InitStructure.NVIC_IRQChannel = USART_IRQn(port);
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_Init(&NVIC_InitStructure);

	if (USART_DEBUG != port)
	{
		USART_DMACmd(USART(port), USART_DMAReq_Tx, ENABLE);
	}
	/* Enable the USARTy */
  	USART_Cmd(USART(port), ENABLE);
}

/*************************************************
  Function:		hw_serial_port_init
  Description:  
  Input:		
  Output:		
  Return:		
  Others:
*************************************************/
void hw_serial_port_init(uint8_t port)
{
	/* Enable GPIO clock */
	RCC_APB2PeriphClockCmd(USART_GPIO_CLK(port), ENABLE);

	/* Enable USART Clock */
	if(port > 1)
	{
		RCC_APB1PeriphClockCmd(USART_CLK(port), ENABLE); 	
	}
	else
	{
		RCC_APB2PeriphClockCmd(USART_CLK(port), ENABLE); 	
	}
 	
	/*Configures the different GPIO ports.*/
	GPIO_InitTypeDef GPIO_InitStructure;
	
	/* Enable the USART3 Pins Software Remapping */
  	GPIO_PinRemapConfig(USART_Remap_GPIO(port), ENABLE);
	
	/* Configure USARTy Rx as input floating */
	GPIO_InitStructure.GPIO_Pin = USART_RxPin(port);
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
	GPIO_Init(USART_GPIO(port), &GPIO_InitStructure);

	/* Configure USARTy Tx as alternate function push-pull */
	GPIO_InitStructure.GPIO_Pin = USART_TxPin(port);
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
	GPIO_Init(USART_GPIO(port), &GPIO_InitStructure);

	if (USART_DEBUG != port)
	{
		/*Configures the DMA.*/
		NVIC_InitTypeDef NVIC_InitStructure;
		NVIC_InitStructure.NVIC_IRQChannel = USART_Tx_DMA_IRQ(port);
		NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;
		NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;
		NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
		NVIC_Init(&NVIC_InitStructure);

		
		DMA_InitTypeDef DMA_InitStructure;
		DMA_DeInit(USART_Tx_DMA_Channel(port));
		DMA_InitStructure.DMA_PeripheralBaseAddr = USART_DR_Base(port);
		DMA_InitStructure.DMA_MemoryBaseAddr = (uint32_t)NULL;
		DMA_InitStructure.DMA_DIR = DMA_DIR_PeripheralDST;
		DMA_InitStructure.DMA_BufferSize = 0;
		DMA_InitStructure.DMA_PeripheralInc = DMA_PeripheralInc_Disable;
		DMA_InitStructure.DMA_MemoryInc = DMA_MemoryInc_Enable;
		DMA_InitStructure.DMA_PeripheralDataSize = DMA_PeripheralDataSize_Byte;
		DMA_InitStructure.DMA_MemoryDataSize = DMA_MemoryDataSize_Byte;
		DMA_InitStructure.DMA_Mode = DMA_Mode_Normal;
		DMA_InitStructure.DMA_Priority = DMA_Priority_High;
		DMA_InitStructure.DMA_M2M = DMA_M2M_Disable;
		DMA_Init(USART_Tx_DMA_Channel(port), &DMA_InitStructure);
		DMA_ITConfig(USART_Tx_DMA_Channel(port), DMA_IT_TC,ENABLE);
	}
	hw_usart_configures(port, USART_BAUDRATE(port));
}

/*************************************************
  Function:		hw_serial_send_rs232
  Description:  
  Input:		
  Output:		
  Return:		
  Others:
*************************************************/
void hw_serial_send_rs232(uint32_t buf, uint16_t len)
{
	DMA_SetBuffer(USART_Tx_DMA_Channel(USART_RS232), buf, len);
	DMA_Cmd(USART_Tx_DMA_Channel(USART_RS232), DISABLE);
}

/*************************************************
  Function:		hw_serial_send_rs232
  Description:  
  Input:		
  Output:		
  Return:		
  Others:
*************************************************/
void hw_serial_send_gps(uint32_t buf, uint16_t len)
{
	DMA_SetBuffer(USART_Tx_DMA_Channel(USART_GPS), buf, len);
	DMA_Cmd(USART_Tx_DMA_Channel(USART_GPS), DISABLE);
}

/*************************************************
  Function:		hw_serial_init
  Description:  
  Input:		
  Output:		
  Return:		
  Others:
*************************************************/
void hw_serial_init(void)
{
	RCC_AHBPeriphClockCmd(RCC_AHBPeriph_DMA1, ENABLE);
	hw_serial_port_init(USART_DEBUG);
    
	#if(USART_DEBUG != USART_NONE)
	printf(" \n");
	#endif
}

