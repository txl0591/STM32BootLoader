/*********************************************************
 Copyright (C),2011-2017,NewLand Auto-ID Tech.,Ltd.
 File name: 		hw_config.h
 Author: 			Tangxl
 Version: 			1.0
 Date: 				2014-8-23
 Description: 		
 History: 			
 					
   1.Date:	 		2014-8-23
 	 Author:	 	Tangxl
 	 Modification:  Created file
 	 
*********************************************************/
#ifndef _HW_CONFIG_H_
#define _HW_CONFIG_H_

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f10x.h"

/*Unique Devices IDs register set*/

#define USB_DISCONNECT_ENABLE    0

#if defined(STM32L1XX_MD) || defined(STM32L1XX_HD) || defined(STM32L1XX_MD_PLUS) 

#define         ID1          (0x1FF80050)
#define         ID2          (0x1FF80054)
#define         ID3          (0x1FF80064)

#elif defined (STM32F37X) || defined(STM32F30X)

#define         ID1          (0x1FFFF7AC)
#define         ID2          (0x1FFFF7B0)
#define         ID3          (0x1FFFF7B4)

#else /*STM32F1x*/

#define         ID1          (0x1FFFF7E8)
#define         ID2          (0x1FFFF7EC)
#define         ID3          (0x1FFFF7F0)

#endif

#if USB_DISCONNECT_ENABLE
  #define USB_DISCONNECT                      GPIOA  
  #define USB_DISCONNECT_PIN                  GPIO_Pin_12
  #define RCC_APB2Periph_GPIO_DISCONNECT      RCC_APB2Periph_GPIOA
#endif

#define BootInfoAddress    0x08007800
#define ApplicationAddress 0x08007C00

void Set_System(void);
void Set_USBClock(void);
void Enter_LowPowerMode(void);
void Leave_LowPowerMode(void);
void USB_Cable_Config (FunctionalState NewState);
void USB_Interrupts_Config(void);
void Reset_Device(void);
void Get_SerialNum(void);

#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif

#endif /* ifndef _HW_CONFIG_H_ Edit By Tangxl 2014-8-23 */

