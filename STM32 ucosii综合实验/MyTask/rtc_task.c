#include "public.h"

void rtc_time_task(void *pdata)    //任务
{	
	u16 hour=0,min=0,sec=0;
	u32 timedata=0;
	u8 dat[9];
	pdata=pdata;
	while(1)
	{
		if(TOUCH_Scan() == 0)
		{			
			TFT_ClearScreen(BLACK);	
			GUI_Show12Char(10,10,"RTC时钟实验",YELLOW,BLACK);
			GUI_Show12Char(200,380,"返回",YELLOW,BLACK);	
		}
		if(timebz==1)
		{
			timebz=0;
			timedata=RTC_GetCounter();//获取RTC计数器的值
			hour=timedata/3600;
			min=(timedata%3600)/60;
			sec=timedata%60;
			dat[0]=hour/10+'0';
			dat[1]=hour%10+'0';
			dat[2]=':';
			dat[3]=min/10+'0';
			dat[4]=min%10+'0';
			dat[5]=':';
			dat[6]=sec/10+'0';
			dat[7]=sec%10+'0';
			dat[8]='\0';
			
		}
		GUI_Show12Char(80,100,dat,YELLOW,BLACK);
	
		Delay_ms(10);			
		if(TouchData.lcdx>200&&TouchData.lcdx<240&&TouchData.lcdy>380&&TouchData.lcdy<400)	
		{
			GUI_DisplayInit();
			TouchData.lcdx=0;
			TouchData.lcdy=0;
			OSTaskDel(RTC_TASK_PRIO);					
		}
	}
	
}
