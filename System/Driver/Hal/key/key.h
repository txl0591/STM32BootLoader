/*********************************************************
 Copyright (C),2011-2017,Electronic Technology Co.,Ltd.
 File name: 		key.h
 Author: 			Txl
 Version: 			1.0
 Date: 				2014-12-27
 Description: 		
 History: 			
 					
   1.Date:	 		2014-12-27
 	 Author:	 	Txl
 	 Modification:  Created file
 	 
*********************************************************/
#ifndef _KEY_H_
#define _KEY_H_

#include "stm32f10x.h"

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif

#define KEY_FLASH       0
#define KEY_MAX         1
typedef struct 
{
    uint16_t Index;
    uint32_t Gpio;
    uint16_t Pin;
    GPIO_TypeDef* Gpiox;
}KEY_INFO,*PKEY_INFO;

/*************************************************
 Function:		hw_get_key
 Descroption:	 
 Input: 		None
 Output: 
 Return: 	
 Other:  
*************************************************/
uint8_t hw_get_key(uint16_t Index);

/*************************************************
 Function:		hw_key_init
 Descroption:	 
 Input: 		None
 Output: 
 Return: 	
 Other:  
*************************************************/
void hw_key_init(void);



#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif

#endif /* ifndef _KEY_H_ Edit By Txl 2014-12-27 */

