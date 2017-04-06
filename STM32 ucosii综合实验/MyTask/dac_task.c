#include "public.h"

void da_task(void *pdata)    //任务
{	
	u16 value;
	float da;
	u8 i=0,dat[7];
	pdata=pdata;

	while(1)
	{
		if(TOUCH_Scan() == 0)
		{			
			TFT_ClearScreen(BLACK);	
			TFT_ClearScreen(BLACK);		
			GUI_Show12Char(10,10,"DAC测试...",YELLOW,BLACK);
			GUI_Show12Char(10,100,"The Output Vologe is:",YELLOW,BLACK);
			GUI_Show12Char(200,380,"返回",YELLOW,BLACK);
					
		}
		value=0;
		for(i=0;i<=10;i++)	
		{
			value=i*400;
			DAC_SetChannel1Data(DAC_Align_12b_R,value);//12位 右对齐 PA4 端口输出	
			da=3.3*value/4095;
			value=da*100;
			dat[0]=value/100+0x30;
			dat[1]='.';
			dat[2]=value%100/10+0x30;
			dat[3]=value%100%10+0x30;
			dat[4]='V';
			dat[5]='\0';
			GUI_Show12Char(180,100,dat,YELLOW,BLACK);
			if(TouchData.lcdx>200&&TouchData.lcdx<240&&TouchData.lcdy>380&&TouchData.lcdy<400)	
			{
				break;					
			}
			TOUCH_Scan();
			Delay_ms(500);
		}			
		if(TouchData.lcdx>200&&TouchData.lcdx<240&&TouchData.lcdy>380&&TouchData.lcdy<400)	
		{
			GUI_DisplayInit();
			TouchData.lcdx=0;
			TouchData.lcdy=0;
			OSTaskDel(DA_TASK_PRIO);					
		}
	}
	
}
