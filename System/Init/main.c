/*********************************************************
  Copyright (C), 2013-2016
  File name:	Main.c
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
#include <stdio.h>
#include "stm32f10x.h"
#include "hw_define.h"
#include "hw_config.h"
#include "appmain.h"

#ifdef USE_FULL_ASSERT
/*************************************************
 Function:		assert_failed
 Descroption:	 
 Input: 
	1.file
	2.line
 Output: 
 Return: 	
 Other:  
*************************************************/
void assert_failed(uint8_t* file, uint32_t line)
{
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */

  /* Infinite loop */
  while (1)
  {}
}
#endif

/*************************************************
  Function:		hw_init
  Description:  
  Input:		
  Output:		
  Return:		
  Others:
*************************************************/
static void hw_init(void)
{
	SystemInit();
    hw_key_init();
	hw_serial_init();	
}

/*************************************************
  Function:		Main
  Description:  
  Input:		
  Output:		
  Return:		
  Others:
*************************************************/
int main(void)
{
    hw_init();   
    if(Bit_RESET == hw_get_key(KEY_FLASH))
    {
        hw_serial_printf("************************************************\r\n");
        hw_serial_printf("               CoreSoft Bootloader              \r\n");
        hw_serial_printf("  BuildTime:    %s\r\n",_BUILE_TIMER_);
        hw_serial_printf("  Hardware Ver: %s\r\n",_HARDWARE_VERSION_);
        hw_serial_printf("  Software Ver: %s\r\n",_SOFTWARE_VERSION_);
        hw_serial_printf("************************************************\r\n");        
        Set_System();
        USB_Interrupts_Config();
        Set_USBClock();
        USB_Init();  
        appmain_init();
        
        while (1)
        {
        	appmain_proc();
        }

    }
    else
    {
        hw_serial_printf("Loading Kernel ....................\r\n");
        exec_appmain();
    }

    while(1)
    {
    }
}

