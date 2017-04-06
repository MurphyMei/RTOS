#include "public.h"

void flash_task(void *pdata)    //任务
{	
	u8 wsbuf[16]="www.prechin.com";
	u8 rsbuf[16];
	pdata=pdata;
	
	while(1)
	{
		if(TOUCH_Scan() == 0)
		{			
			TFT_ClearScreen(BLACK);
			GUI_Show12Char(10,10,"FLASH-EN25Q64实验",YELLOW,BLACK);	
			GUI_Show12Char(10,50,"FLASH读写测试！",YELLOW,BLACK);
			GUI_Show12Char(200,380,"返回",YELLOW,BLACK);
					
		}
		while(FLASH_Init()!=EN25Q64)
		{
			GUI_Show12Char(10,28,"Flash Error!",YELLOW,BLACK);	
		}
		GUI_Show12Char(10,28,"Flash Success!",YELLOW,BLACK);	
		
		FLASH_WriteData(wsbuf,0,16);
		GUI_Show12Char(10,98,"www.prechin.com",YELLOW,BLACK);
		GUI_Show12Char(10,118,"Flash Write Success",YELLOW,BLACK);

		FLASH_ReadData(rsbuf,0,16);
		GUI_Show12Char(10,158,rsbuf,YELLOW,BLACK);

		/*
		if(k_up==1)
		{
			Delay_ms(10);
			if(k_up==1)
			{	
				FLASH_WriteData(wsbuf,0,16);
				GUI_Show12Char(10,98,"www.prechin.com",YELLOW,BLACK);
				GUI_Show12Char(10,118,"Flash Write Success",YELLOW,BLACK);					
			}
			while(k_up);
		}
		if(k_down==0)
		{
			Delay_ms(10);
			if(k_down==0)
			{
				FLASH_ReadData(rsbuf,0,16);
				GUI_Show12Char(10,158,rsbuf,YELLOW,BLACK);	
			}
			while(!k_down);	
		} */
		Delay_ms(10);			
		if(TouchData.lcdx>200&&TouchData.lcdx<240&&TouchData.lcdy>380&&TouchData.lcdy<400)	
		{
			GUI_DisplayInit();
			TouchData.lcdx=0;
			TouchData.lcdy=0;
			OSTaskDel(FLASH_TASK_PRIO);					
		}
	}
	
}
