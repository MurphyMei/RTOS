#include "public.h"

void com_task(void *pdata)    //����
{	

	pdata=pdata;
	usart_init();

	while(1)
	{
		if(TOUCH_Scan() == 0)
		{			
			TFT_ClearScreen(BLACK);		
			GUI_Show12Char(10,10,"����COM1���ԣ�ͨ���������ֲ鿴���ͺͽ�������",YELLOW,BLACK);
			GUI_Show12Char(10,50,"�ڴ��������ϲ������趨Ϊ9600�����ݸ�ʽΪ8������żУ��",YELLOW,BLACK);
			GUI_Show12Char(10,100,"���Ҫʹ��COM3�����Խ�COM3ģ��̽�ƬP232�̽ӵ�COM3�ˣ����ʱ��IIC���ܾ�ʧЧ�������Ҫ����IIC��Ҫ���̽�Ƭ��ԭ����",YELLOW,BLACK);
			

			GUI_Show12Char(200,380,"����",YELLOW,BLACK);
					
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
