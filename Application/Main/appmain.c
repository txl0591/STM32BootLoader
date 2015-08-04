/*********************************************************
 Copyright (C),2011-2017,Electronic Technology Co.,Ltd.
 File name: 		appmain.c
 Author: 			Tangxl
 Version: 			1.0
 Date: 				2017-5-18
 Description: 		
 History: 			
 					
   1.Date:	 		2017-5-18
 	 Author:	 	Tangxl
 	 Modification:  Created file
   2. ... 
*********************************************************/
#include "hw_define.h"
#include "hw_config.h"

#define FLASH_CMD_NONE   0xFF
#define FLASH_CMD_START  0xF0
#define FLASH_CMD_RESET  0xF1
#define FLASH_CMD_BOOT   0xF2
#define FLASH_CMD_ADDR   0xF3
#define FLASH_CMD_WRITE  0xF4
#define FLASH_CMD_READ   0xF5
#define FLASH_CMD_END    0xF6
#define FLASH_CMD_ERASE  0xF7

#define FLASH_ACK        0xF0

#define MAX_USBBUF_SIZE  64 

static uint8_t  flashBuffer[MAX_USBBUF_SIZE];
static uint32_t flashAddress = ApplicationAddress;
static uint32_t flashAddressRun = ApplicationAddress;
static uint8_t  AckBuffer[MAX_USBBUF_SIZE];
static uint8_t  AckBufferLen = 0;
static uint8_t  flashoper = 0;
static uint8_t  flashread = 0;

typedef  void (*pFunction)(void);
static pFunction Jump_To_Application;
static uint32_t JumpAddress;

/*************************************************
 Function:		get_exec_appmain_addr
 Descroption:	执行APP部分
 Input: 		None
 Output: 
 Return: 	
 Other:  
*************************************************/
uint32_t get_exec_appmain_addr(void)
{
    return flashAddressRun;
}

/*************************************************
 Function:		exec_appmain
 Descroption:	执行APP部分
 Input: 		None
 Output: 
 Return: 	
 Other:  
*************************************************/
void exec_appmain(void)
{
    JumpAddress = *(__IO uint32_t*) (flashAddressRun + 4);
    Jump_To_Application = (pFunction) JumpAddress;
    __set_MSP(*(__IO uint32_t*) flashAddressRun);
    Jump_To_Application();
}

/*************************************************
 Function:		flash_fill_buffer
 Descroption:	 
 Input: 
	1.buf
	2.len
 Output: 
 Return: 	
 Other:  
*************************************************/
void flash_fill_buffer(uint8_t* buf, int len)
{
    int i;
    if(len <= MAX_USBBUF_SIZE)
    {
        for (i = 0 ; i < len; i++)
        {
            flashBuffer[i] = buf[i];
        } 
        flashoper = 1;
    }
}

/*************************************************
 Function:		flash_erase
 Descroption:	 
 Input: 
	1.buf
	2.len
 Output: 
 Return: 	
 Other:  
*************************************************/
void flash_erase(void)
{
    uint32_t startaddr,endaddr;

    startaddr = 0;
    endaddr = 0;
    
    startaddr |= flashBuffer[1];
    startaddr <<= 8;
    startaddr |= flashBuffer[2];
    startaddr <<= 8;
    startaddr |= flashBuffer[3];
    startaddr <<= 8;
    startaddr |= flashBuffer[4];

    endaddr |= flashBuffer[5];
    endaddr <<= 8;
    endaddr |= flashBuffer[6];
    endaddr <<= 8;
    endaddr |= flashBuffer[7];
    endaddr <<= 8;
    endaddr |= flashBuffer[8];

    
    do
    {
        hw_flash_erase(startaddr);
        startaddr += 1024;
    }while(startaddr < endaddr);
    
}

/*************************************************
 Function:		appmain_proc
 Descroption:	 
 Input: 		None
 Output: 
 Return: 	
 Other:  
*************************************************/
void appmain_proc(void)
{
    uint32_t addr,i;
    if(flashoper == 0)
    {
        return;
    }
    
    switch(flashBuffer[0])
    {
        case FLASH_CMD_START:
            hw_serial_printf("FLASH_CMD_SRART\r\n");
            hw_flash_init();
            break;
        
        case FLASH_CMD_RESET:
            break;
        
        case FLASH_CMD_BOOT:
            hw_serial_printf("FLASH_CMD_BOOT==========[%x]\r\n",flashAddressRun);
            exec_appmain();
            break;
        
        case FLASH_CMD_ADDR:
            flashAddressRun |= flashBuffer[1];
            flashAddressRun <<= 8;
            flashAddressRun |= flashBuffer[2];
            flashAddressRun <<= 8;
            flashAddressRun |= flashBuffer[3];
            flashAddressRun <<= 8;
            flashAddressRun |= flashBuffer[4];
            flashAddress = flashAddressRun;
            hw_serial_printf("FLASH_CMD_ADDR==========[%x]\r\n",flashAddressRun);
            break;
        
        case FLASH_CMD_WRITE:
            //hw_serial_printf("FLASH_CMD_WRITE==========[%x]\r\n",flashAddress);
            if(flashBuffer[1] > (MAX_USBBUF_SIZE-2))
            {
               flashBuffer[1] = (MAX_USBBUF_SIZE-2);
            }
            flashAddress = hw_flash_program(flashAddress, flashBuffer+2, flashBuffer[1]);
            break;
        
        case FLASH_CMD_READ:
            addr = 0;
            addr |= flashBuffer[1];
            addr <<= 8;
            addr |= flashBuffer[2];
            addr <<= 8;
            addr |= flashBuffer[3];
            addr <<= 8;
            addr |= flashBuffer[4];
            flashread = hw_flash_read(addr, AckBuffer, flashBuffer[5]);
            hw_serial_printf("FLASH_CMD_READ==========[%x] [%d] ",addr,flashread);
            for (i = 0 ; i < flashread; i++)
            {
                hw_serial_printf(" %x",AckBuffer[i]);
            }
            hw_serial_printf("\r\n");
            break;

        case FLASH_CMD_END:
            hw_flash_deinit();
            hw_serial_printf("FLASH_CMD_END\r\n");
            break;

        case FLASH_CMD_ERASE:
            flash_erase();
            hw_serial_printf("FLASH_CMD_ERASE\r\n");
            break;
        
        default:
            
            break;
    }

    if(flashBuffer[0] != FLASH_CMD_NONE && FLASH_CMD_RESET != flashBuffer[0] && flashBuffer[0] != FLASH_CMD_BOOT)
    {
        AckBuffer[0] = FLASH_ACK;
        AckBuffer[1] = flashBuffer[0];
        AckBufferLen = 2;
        UserToPMABufferCopy(AckBuffer, ENDP1_TXADDR, AckBufferLen);
        SetEPTxCount(ENDP1,AckBufferLen);
        SetEPTxValid(ENDP1);
    }
    
    if(FLASH_CMD_NONE != flashBuffer[0])
    {
        flashBuffer[0] = FLASH_CMD_NONE;    
    }
    flashoper = 0;
}

/*************************************************
  Function:		appmain_init
  Description:  
  Input:		
  Output:		
  Return:		
  Others:
*************************************************/
void appmain_init(void)
{
	flashBuffer[0] = FLASH_CMD_NONE;
}

