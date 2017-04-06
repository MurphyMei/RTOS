#include "public.h"

void led1_task(void *pdata)    //任务
{

	pdata=pdata;
	while(1)
	{
		if(TOUCH_Scan() == 0)
		{		
			TFT_ClearScreen(BLACK);	
			GUI_Show12Char(10,10,"LED灯实验",YELLOW,BLACK);
		
			GUI_Show12Char(200,380,"返回",YELLOW,BLACK);	
		}
		GPIO_Write(GPIOC,(u16)(0x00));
		Delay_ms(100);
		GPIO_Write(GPIOC,(u16)(0xff));
		Delay_ms(100);

		if(TouchData.lcdx>200&&TouchData.lcdx<240&&TouchData.lcdy>380&&TouchData.lcdy<400)	
		{
			GUI_DisplayInit();
			TouchData.lcdx=0;
			TouchData.lcdy=0;
			GPIO_Write(GPIOC,(u16)(0xff));
			OSTaskDel(LED1_TASK_PRIO);			
		}
	}
	
}
