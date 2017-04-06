#include "public.h"

void sram_task(void *pdata)    //任务
{	
	uint8_t showData[5]={0,0,0,0,0};
	u16 cap;
	u8 sbuf[15]="www.prechin.com";
	pdata=pdata;

	while(1)
	{
		if(TOUCH_Scan() == 0)
		{			
			TFT_ClearScreen(BLACK);	
			GUI_Show12Char(10, 0, "SRAM 测试...", RED, BLACK);
			GUI_Show12Char(10, 18, "按键K_up 写数据", RED, BLACK);
			GUI_Show12Char(10, 36, "按键K_down 读数据", RED, BLACK);
			GUI_Show12Char(10, 64, "SRAM Cap:     KB", RED, BLACK);
			GUI_Show12Char(200,380,"返回",YELLOW,BLACK);
					
		}
		cap=SRAM_Test();
		/* 显示读取到的容量 */
	    showData[0] = (cap % 10000 /1000) + '0';
	    showData[1] = (cap % 1000 /100) + '0';
	    showData[2] = (cap % 100 /10) + '0';
	    showData[3] = (cap % 10) + '0';
	    GUI_Show12Char(83, 64, showData, RED, BLACK);

		if(k_up==1)
		{
			Delay_ms(10);
			if(k_up==1)	
			{	
				SRAM_WriteBuffer((uint16_t *)sbuf, 2, 15);
				GUI_Show12Char(10, 86, "Write OK!", RED, BLACK);		
			}
			while(k_up);
		}
		
		if(k_down==0)
		{
			Delay_ms(10);
			if(k_down==0)
			{
				GUI_Show12Char(10, 106, "Read OK!", RED, BLACK);
				SRAM_ReadBuffer((uint16_t *)sbuf, 2, 15);
				GUI_Show12Char(10, 126, sbuf, RED, BLACK);
			}
			while(!k_down);			
		}

		Delay_ms(10);			
		if(TouchData.lcdx>200&&TouchData.lcdx<240&&TouchData.lcdy>380&&TouchData.lcdy<400)	
		{
			GUI_DisplayInit();
			TouchData.lcdx=0;
			TouchData.lcdy=0;
			OSTaskDel(SRAM_TASK_PRIO);					
		}
	}
	
}
