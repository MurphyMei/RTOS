#include "public.h"

void smg_task(void *pdata)    //任务
{
	static u8 i=0;
	pdata=pdata;
	while(1)
	{
		if(TOUCH_Scan() == 0)
		{		
			TFT_ClearScreen(BLACK);	
			GUI_Show12Char(10,10,"数码管实验",YELLOW,BLACK);
			GUI_Show12Char(10,50,"数码管循环显示0-F",YELLOW,BLACK);
			GUI_Show12Char(200,380,"返回",YELLOW,BLACK);	
		}		
		GPIO_Write(GPIOC,(u16)(~smgduan[i++]));
		Delay_ms(500);
		if(i==16)i=0;				
		if(TouchData.lcdx>200&&TouchData.lcdx<240&&TouchData.lcdy>380&&TouchData.lcdy<400)	
		{
			GUI_DisplayInit();
			TouchData.lcdx=0;
			TouchData.lcdy=0;
			GPIO_Write(GPIOC,(u16)(0xff));
			OSTaskDel(SMG_TASK_PRIO);					
		}
	}
	
}
