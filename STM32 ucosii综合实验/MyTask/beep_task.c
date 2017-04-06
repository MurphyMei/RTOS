#include "public.h"

void beep_task(void *pdata)    //任务
{
	u16 i=1000;
	pdata=pdata;
	while(1)
	{
		i=1000;
		if(TOUCH_Scan() == 0)
		{		
			TFT_ClearScreen(BLACK);	
			GUI_Show12Char(10,10,"蜂鸣器实验",YELLOW,BLACK);
		
			GUI_Show12Char(200,380,"返回",YELLOW,BLACK);	
		}
		
		GPIO_SetBits(GPIOB,BZ);
		Delay(i);
		GPIO_ResetBits(GPIOB,BZ);
		Delay(i--);	
		
		if(TouchData.lcdx>200&&TouchData.lcdx<240&&TouchData.lcdy>380&&TouchData.lcdy<400)	
		{
			GUI_DisplayInit();
			TouchData.lcdx=0;
			TouchData.lcdy=0;
			OSTaskDel(BEEP_TASK_PRIO);					
		}
	}
	
}
