#include "public.h"

void low_task(void *pdata)    //任务
{	
	pdata=pdata;
	while(1)
	{
		if(TOUCH_Scan() == 0)
		{			
			TFT_ClearScreen(BLACK);
			GUI_Show12Char(10,10,"低功耗-待机模式实验",YELLOW,BLACK);	
			GUI_Show12Char(10,30,"K_LEFT: 进入待机模式！",YELLOW,BLACK);
			GUI_Show12Char(10,50,"K_UP: 退出待机模式！",YELLOW,BLACK);
			GUI_Show12Char(10,130,"等待进入待机模式...",YELLOW,BLACK);
			GUI_Show12Char(10,180,"进入待机模式以后按下K_UP键退出返回主界面",YELLOW,BLACK);
			GUI_Show12Char(200,380,"返回",YELLOW,BLACK);	
		}
		if(k_left==0)
		{
			Delay_ms(10);
			if(k_left==0)
			{
				GUI_Show12Char(10,130,"***进入待机模式！***",YELLOW,BLACK);
				standmodeinit();   //待机模式
			}
		}		
		Delay_ms(10);			
		if(TouchData.lcdx>200&&TouchData.lcdx<240&&TouchData.lcdy>380&&TouchData.lcdy<400)	
		{
			GUI_DisplayInit();
			TouchData.lcdx=0;
			TouchData.lcdy=0;
			OSTaskDel(LOW_TASK_PRIO);					
		}
	}
	
}
