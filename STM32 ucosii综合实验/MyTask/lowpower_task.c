#include "public.h"

void low_task(void *pdata)    //����
{	
	pdata=pdata;
	while(1)
	{
		if(TOUCH_Scan() == 0)
		{			
			TFT_ClearScreen(BLACK);
			GUI_Show12Char(10,10,"�͹���-����ģʽʵ��",YELLOW,BLACK);	
			GUI_Show12Char(10,30,"K_LEFT: �������ģʽ��",YELLOW,BLACK);
			GUI_Show12Char(10,50,"K_UP: �˳�����ģʽ��",YELLOW,BLACK);
			GUI_Show12Char(10,130,"�ȴ��������ģʽ...",YELLOW,BLACK);
			GUI_Show12Char(10,180,"�������ģʽ�Ժ���K_UP���˳�����������",YELLOW,BLACK);
			GUI_Show12Char(200,380,"����",YELLOW,BLACK);	
		}
		if(k_left==0)
		{
			Delay_ms(10);
			if(k_left==0)
			{
				GUI_Show12Char(10,130,"***�������ģʽ��***",YELLOW,BLACK);
				standmodeinit();   //����ģʽ
			}
		}		
		Delay_ms(10);			
		if(TouchData.lcdx>200&&TouchData.lcdx<240&&TouchData.lcdy>380&&TouchData.lcdy<400)	
		{
			GUI_DisplayInit();
			TouchData.lcdx=0;
			TouchData.lcdy=0;
			OSTaskDel(LOW_TASK_PRIO);					
		}
	}
	
}
