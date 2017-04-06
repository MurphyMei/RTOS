#ifndef _public_H
#define _public_H
#include "stm32f10x.h"

#include "includes.h"
#include "misc.h"

#include "start_task.h"
#include "touch_task.h"
#include "led_task.h"
#include "beep_task.h"
#include "smg_task.h"
#include "adc_task.h"
#include "key_task.h"
#include "ds18b20_task.h"
#include "eeprom_task.h"
#include "rtc_task.h"
#include "hwjs_task.h"
#include "iwdg_task.h"
#include "lowpower_task.h"
#include "flash_task.h"
#include "sd_task.h"
#include "adx345_task.h"
#include "sram_task.h"
#include "dac_task.h"
#include "usart_task.h"
#include "rs485_task.h"
#include "can_task.h"



#include "systick.h"
#include "touch.h"
#include "spi.h"
#include "flash.h"
#include "gui.h"
#include "malloc.h"
#include "lcd_driver.h"
#include "led.h"
#include "beep.h"
#include "smg.h"
#include "adc.h"
#include "key.h"
#include "ds18b20.h"
#include "AT24CXX.h"
#include "iic.h"
#include "rtc.h"
#include "hwjs.h"
#include "iwdg.h"
#include "lowpower.h"
#include "sd.h"
#include "adx345.h"
#include "math.h"
#include"sram.h"
#include "dac.h"
#include "usart.h"
#include "rs485.h"
#include "can.h"
#include "ff.h"
#include "myfatapp.h"




//¶¨Òåº¯Êý


void Delay_Init(void);
void Delay_us(u32 nus);
void Delay_ms(u16 nms);
void Delay(u32 i);
void GUI_DisplayInit(void);

#endif
