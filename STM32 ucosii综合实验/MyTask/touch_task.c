#include "public.h"

void touch_task(void *pdata)    //任务
{
	OS_CPU_SR cpu_sr=0;
	static u8 start=0;
	pdata=pdata;
	while(1)
	{
		if(TOUCH_Scan() == 0)
		{		
			start=1;	
		}
		OS_ENTER_CRITICAL();  //进入临界区，中断无法打断
		if(start==1)
		{
			if(TouchData.lcdx>10&&TouchData.lcdx<70&&TouchData.lcdy>0&&TouchData.lcdy<40)	
			{
				OSTaskCreate(led1_task,(void *)0,(OS_STK *)&LED1_TASK_STK[LED1_STK_SIZE-1]
				,LED1_TASK_PRIO);	
			}
			if(TouchData.lcdx>90&&TouchData.lcdx<150&&TouchData.lcdy>0&&TouchData.lcdy<40)	
			{
				OSTaskCreate(beep_task,(void *)0,(OS_STK *)&BEEP_TASK_STK[BEEP_STK_SIZE-1]
				,BEEP_TASK_PRIO);	
			}
			if(TouchData.lcdx>170&&TouchData.lcdx<230&&TouchData.lcdy>0&&TouchData.lcdy<40)	
			{
				OSTaskCreate(smg_task,(void *)0,(OS_STK *)&SMG_TASK_STK[SMG_STK_SIZE-1]
				,SMG_TASK_PRIO);		
			}
			if(TouchData.lcdx>10&&TouchData.lcdx<70&&TouchData.lcdy>60&&TouchData.lcdy<100)	
			{
				OSTaskCreate(adc_task,(void *)0,(OS_STK *)&ADC_TASK_STK[ADC_STK_SIZE-1]
				,ADC_TASK_PRIO);   //AD转换			
			}
			if(TouchData.lcdx>90&&TouchData.lcdx<150&&TouchData.lcdy>60&&TouchData.lcdy<100)	
			{
				OSTaskCreate(button_task,(void *)0,(OS_STK *)&BUTTON_TASK_STK[BUTTON_STK_SIZE-1]
				,BUTTON_TASK_PRIO);     //按键			
			}
			if(TouchData.lcdx>170&&TouchData.lcdx<230&&TouchData.lcdy>60&&TouchData.lcdy<100)	
			{
				OSTaskCreate(ds18b20_task,(void *)0,(OS_STK *)&TEMP_TASK_STK[TEMP_STK_SIZE-1]
				,TEMP_TASK_PRIO);   //DS18B20温度传感器			
			}
			if(TouchData.lcdx>10&&TouchData.lcdx<70&&TouchData.lcdy>120&&TouchData.lcdy<160)	
			{
				OSTaskCreate(eeprom_task,(void *)0,(OS_STK *)&EEPROM_TASK_STK[EEPROM_STK_SIZE-1]
				,EEPROM_TASK_PRIO);   //eeprom			
			}
			if(TouchData.lcdx>90&&TouchData.lcdx<150&&TouchData.lcdy>120&&TouchData.lcdy<160)	
			{
				OSTaskCreate(rtc_time_task,(void *)0,(OS_STK *)&RTC_TASK_STK[RTC_STK_SIZE-1]
				,RTC_TASK_PRIO);   //RTC时钟			
			}
			if(TouchData.lcdx>170&&TouchData.lcdx<230&&TouchData.lcdy>120&&TouchData.lcdy<160)	
			{
				OSTaskCreate(hwjs_task,(void *)0,(OS_STK *)&HW_TASK_STK[HW_STK_SIZE-1]
				,HW_TASK_PRIO);   //红外遥控			
			}
			if(TouchData.lcdx>10&&TouchData.lcdx<110&&TouchData.lcdy>180&&TouchData.lcdy<220)	
			{
				OSTaskCreate(iwdg_task,(void *)0,(OS_STK *)&IWDG_TASK_STK[IWDG_STK_SIZE-1]
				,IWDG_TASK_PRIO);   //独立看门狗			
			}
			if(TouchData.lcdx>130&&TouchData.lcdx<230&&TouchData.lcdy>180&&TouchData.lcdy<220)	
			{
				//hz_pros();   //字库更新			
			}
			if(TouchData.lcdx>10&&TouchData.lcdx<70&&TouchData.lcdy>240&&TouchData.lcdy<280)	
			{
				OSTaskCreate(low_task,(void *)0,(OS_STK *)&LOW_TASK_STK[LOW_STK_SIZE-1]
				,LOW_TASK_PRIO);   //低功耗 待机模式			
			}
			if(TouchData.lcdx>90&&TouchData.lcdx<150&&TouchData.lcdy>240&&TouchData.lcdy<280)	
			{
				OSTaskCreate(flash_task,(void *)0,(OS_STK *)&FLASH_TASK_STK[FLASH_STK_SIZE-1]
				,FLASH_TASK_PRIO);   //FLASH-EN25Q64			
			}
			if(TouchData.lcdx>170&&TouchData.lcdx<230&&TouchData.lcdy>240&&TouchData.lcdy<280)	
			{
				OSTaskCreate(sd_task,(void *)0,(OS_STK *)&SD_TASK_STK[SD_STK_SIZE-1]
				,SD_TASK_PRIO);   //SD Card测试			
			}
			if(TouchData.lcdx>10&&TouchData.lcdx<70&&TouchData.lcdy>300&&TouchData.lcdy<340)	
			{
				OSTaskCreate(adx345_task,(void *)0,(OS_STK *)&ADX345_TASK_STK[ADX345_STK_SIZE-1]
				,ADX345_TASK_PRIO);   //ADX345加速度传感器测试			
			}
			if(TouchData.lcdx>90&&TouchData.lcdx<150&&TouchData.lcdy>300&&TouchData.lcdy<340)	
			{
				OSTaskCreate(sram_task,(void *)0,(OS_STK *)&SRAM_TASK_STK[SRAM_STK_SIZE-1]
				,SRAM_TASK_PRIO);   //SRAM测试			
			}
			if(TouchData.lcdx>170&&TouchData.lcdx<230&&TouchData.lcdy>300&&TouchData.lcdy<340)	
			{
				OSTaskCreate(da_task,(void *)0,(OS_STK *)&DA_TASK_STK[DA_STK_SIZE-1]
				,DA_TASK_PRIO);   //DA测试			
			}
			if(TouchData.lcdx>0&&TouchData.lcdx<60&&TouchData.lcdy>360&&TouchData.lcdy<399)	
			{
				OSTaskCreate(com_task,(void *)0,(OS_STK *)&COM1_TASK_STK[COM1_STK_SIZE-1]
				,COM1_TASK_PRIO);   //COM1通信测试			
			}
			if(TouchData.lcdx>70&&TouchData.lcdx<130&&TouchData.lcdy>360&&TouchData.lcdy<399)	
			{
				OSTaskCreate(rs485_task,(void *)0,(OS_STK *)&COM2_TASK_STK[COM2_STK_SIZE-1]
				,COM2_TASK_PRIO);   //485通信测试			
			}
			if(TouchData.lcdx>140&&TouchData.lcdx<200&&TouchData.lcdy>360&&TouchData.lcdy<399)	
			{
				OSTaskCreate(can_task,(void *)0,(OS_STK *)&CAN_TASK_STK[CAN_STK_SIZE-1]
				,CAN_TASK_PRIO);   //CAN通信测试			
			}
				
		}
		OS_EXIT_CRITICAL();  //退出临界区，中断可以打断
		Delay_ms(100);
	}
	
}
