#include "public.h"

void button_task(void *pdata)    //任务
{	
	pdata=pdata;
	while(1)
	{
		if(TOUCH_Scan() == 0)
		{		
			TFT_ClearScreen(BLACK);	
			GUI_Show12Char(100,10,"按键测试",YELLOW,BLACK);
			GUI_Show12Char(10,40,"通过按下开发板上面的按键可在彩屏上的方块变换颜色",YELLOW,BLACK);
			GUI_Show12Char(200,380,"返回",YELLOW,BLACK);
			GUI_Box(10, 180, 70,220, YELLOW);	
			GUI_Box(90, 180, 150,220, YELLOW);
			GUI_Box(10, 240, 70,280, YELLOW);	
			GUI_Box(90, 240, 150,280, YELLOW);	
		}		
		if(k_up==1)	  //判断按键k_up是否按下
		{
			Delay_ms(10); //消抖处理
			if(k_up==1)	 //再次判断按键k_up是否按下
			{
				GUI_Box(10, 180, 70,220, BLUE);					
			}
			while(k_up); //等待按键松开
		}
		if(k_down==0)
		{
			Delay_ms(10);
			if(k_down==0)
			{
				GUI_Box(90, 180, 150,220, BLUE);			
			}
			while(!k_down);
		}
		if(k_left==0)
		{
			Delay_ms(10);
			if(k_left==0)
			{
				GUI_Box(10, 240, 70,280, BLUE);			
			}
			while(!k_left);
		}
		if(k_right==0)
		{
			Delay_ms(10);
			if(k_right==0)
			{
				GUI_Box(90, 240, 150,280, BLUE);			
			}
			while(!k_right);
		}			
		Delay_ms(10);			
		if(TouchData.lcdx>200&&TouchData.lcdx<240&&TouchData.lcdy>380&&TouchData.lcdy<400)	
		{
			GUI_DisplayInit();
			TouchData.lcdx=0;
			TouchData.lcdy=0;
			OSTaskDel(BUTTON_TASK_PRIO);					
		}
	}
	
}
