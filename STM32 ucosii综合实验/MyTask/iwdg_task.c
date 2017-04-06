#include "public.h"

void iwdg_task(void *pdata)    //任务
{	
	pdata=pdata;
	iwdg_init();   //独立看门狗初始化配置
	while(1)
	{
		if(TOUCH_Scan() == 0)
		{			
			TFT_ClearScreen(BLACK);	
			GUI_Show12Char(10,10,"独立看门狗实验",YELLOW,BLACK);
			GUI_Show12Char(10,40,"喂狗时间是1.28秒，如果喂狗时间超过1.28秒将使系统复位重启",YELLOW,BLACK);
			GUI_Show12Char(200,380,"返回",YELLOW,BLACK);	
		}
		IWDG_ReloadCounter();	   //喂狗的时间是1.28s
		GUI_Show12Char(10,100,"进入喂狗...",YELLOW,BLACK);
		//只要在喂狗时间内喂狗就不会让系统以为死机进入复位状态
		Delay_ms(10);			
		if(TouchData.lcdx>200&&TouchData.lcdx<240&&TouchData.lcdy>380&&TouchData.lcdy<400)	
		{
			GUI_DisplayInit();
			TouchData.lcdx=0;
			TouchData.lcdy=0;
			OSTaskDel(IWDG_TASK_PRIO);					
		}
	}
	
}
