/*********************************************************
  Copyright (C), 2013-2016
  File name:	hw_define.h
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
#ifndef _HW_DEFINE_H_
#define _HW_DEFINE_H_

#include <stdio.h>

#include "stm32f10x.h"
#include "usb_lib.h"
#include "usb_conf.h"
#include "usb_prop.h"
#include "usb_pwr.h"
#include "hw_serial.h"
#include "hw_flash.h"
#include "key.h"

#include "config.h"

#ifdef __cplusplus
extern "C" {
#endif 

#define SYS_CLOCK					 72

/*******************TIME********************/
#define TIME_CLOCK 					(SYS_CLOCK/8) 

/*******************UART********************/
#define USART_NONE					 0
#define USART_GPRS					 1
#define USART_GPS					 2
#define USART_RS232					 3

#define USART_DEBUG					 USART_RS232  

/*******************USB********************/
#define USB_CUSTOM                   1
#define USB_DFU                      2

#define USB_TYPE                     USB_CUSTOM


#ifdef __cplusplus
}
#endif

#endif

