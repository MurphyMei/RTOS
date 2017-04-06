#include "public.h"

void rs485_task(void *pdata)    //任务
{	

	pdata=pdata;
	rs485_init();
	GPIO_ResetBits(GPIOG,GPIO_Pin_3);//首先要打开485接收数据的控制端

	while(1)
	{
		if(TOUCH_Scan() == 0)
		{			
			TFT_ClearScreen(BLACK);		
			GUI_Show12Char(10,10,"RS485串口COM2测试，通过串口助手查看发送和接收数据",YELLOW,BLACK);
			GUI_Show12Char(10,50,"注意：将开发板上的A B端子对应接到USB转485端子的A B",YELLOW,BLACK);
			GUI_Show12Char(10,100,"在串口助手上波特率设定为9600，数据格式为8，无奇偶校验",YELLOW,BLACK);
			GUI_Show12Char(10,180,"如果要使用WIFI，可以将RS485模块短接片短接到WIFI端，这个时候485功能就失效，如果还要测试485就要将短接片还原回来",YELLOW,BLACK);
			

			GUI_Show12Char(200,380,"返回",YELLOW,BLACK);
					
		}	
		if(TouchData.lcdx>200&&TouchData.lcdx<240&&TouchData.lcdy>380&&TouchData.lcdy<400)	
		{
			GUI_DisplayInit();
			TouchData.lcdx=0;
			TouchData.lcdy=0;
			OSTaskDel(COM2_TASK_PRIO);					
		}
	}
	
}
