#include "public.h"

void rs485_task(void *pdata)    //����
{	

	pdata=pdata;
	rs485_init();
	GPIO_ResetBits(GPIOG,GPIO_Pin_3);//����Ҫ��485�������ݵĿ��ƶ�

	while(1)
	{
		if(TOUCH_Scan() == 0)
		{			
			TFT_ClearScreen(BLACK);		
			GUI_Show12Char(10,10,"RS485����COM2���ԣ�ͨ���������ֲ鿴���ͺͽ�������",YELLOW,BLACK);
			GUI_Show12Char(10,50,"ע�⣺���������ϵ�A B���Ӷ�Ӧ�ӵ�USBת485���ӵ�A B",YELLOW,BLACK);
			GUI_Show12Char(10,100,"�ڴ��������ϲ������趨Ϊ9600�����ݸ�ʽΪ8������żУ��",YELLOW,BLACK);
			GUI_Show12Char(10,180,"���Ҫʹ��WIFI�����Խ�RS485ģ��̽�Ƭ�̽ӵ�WIFI�ˣ����ʱ��485���ܾ�ʧЧ�������Ҫ����485��Ҫ���̽�Ƭ��ԭ����",YELLOW,BLACK);
			

			GUI_Show12Char(200,380,"����",YELLOW,BLACK);
					
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
