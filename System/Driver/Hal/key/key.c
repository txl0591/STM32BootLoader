/*********************************************************
 Copyright (C),2011-2017,Electronic Technology Co.,Ltd.
 File name: 		key.c
 Author: 			Txl
 Version: 			1.0
 Date: 				2014-12-27
 Description: 		
 History: 			
 					
   1.Date:	 		2014-12-27
 	 Author:	 	Txl
 	 Modification:  Created file
 	 
*********************************************************/

#include "key.h"

static KEY_INFO mKeyInfo[KEY_MAX] = 
{
   {KEY_FLASH, RCC_APB2Periph_GPIOA, GPIO_Pin_1, GPIOA},
};

/*************************************************
 Function:		hw_get_key
 Descroption:	 
 Input: 		None
 Output: 
 Return: 	
 Other:  
*************************************************/
uint8_t hw_get_key(uint16_t Index)
{
    return GPIO_ReadInputDataBit(mKeyInfo[Index].Gpiox, mKeyInfo[Index].Pin);
}

/*************************************************
 Function:		hw_key_init
 Descroption:	 
 Input: 		None
 Output: 
 Return: 	
 Other:  
*************************************************/
void hw_key_init(void)
{
    int i;
    GPIO_InitTypeDef GPIO_InitStructure;
    for (i = 0 ; i < KEY_MAX; i++)
    {
          RCC_APB2PeriphClockCmd(mKeyInfo[i].Gpio, ENABLE);
          GPIO_InitStructure.GPIO_Pin = mKeyInfo[i].Pin;
          GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
          GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
          GPIO_Init(mKeyInfo[i].Gpiox, &GPIO_InitStructure);
    }
    
}

