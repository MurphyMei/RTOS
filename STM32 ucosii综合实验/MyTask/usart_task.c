#include "public.h"

void com_task(void *pdata)    //任务
{	

	pdata=pdata;
	usart_init();

	while(1)
	{
		if(TOUCH_Scan() == 0)
		{			
			TFT_ClearScreen(BLACK);		
			GUI_Show12Char(10,10,"串口COM1测试，通过串口助手查看发送和接收数据",YELLOW,BLACK);
			GUI_Show12Char(10,50,"在串口助手上波特率设定为9600，数据格式为8，无奇偶校验",YELLOW,BLACK);
			GUI_Show12Char(10,100,"如果要使用COM3，可以将COM3模块短接片P232短接到COM3端，这个时候IIC功能就失效，如果还要测试IIC就要将短接片还原回来",YELLOW,BLACK);
			

			GUI_Show12Char(200,380,"返回",YELLOW,BLACK);
					
		}	
		if(TouchData.lcdx>200&&TouchData.lcdx<240&&TouchData.lcdy>380&&TouchData.lcdy<400)	
		{
			GUI_DisplayInit();
			TouchData.lcdx=0;
			TouchData.lcdy=0;
			OSTaskDel(COM1_TASK_PRIO);					
		}
	}
	
}
