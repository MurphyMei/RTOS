#include "public.h"

void iwdg_task(void *pdata)    //����
{	
	pdata=pdata;
	iwdg_init();   //�������Ź���ʼ������
	while(1)
	{
		if(TOUCH_Scan() == 0)
		{			
			TFT_ClearScreen(BLACK);	
			GUI_Show12Char(10,10,"�������Ź�ʵ��",YELLOW,BLACK);
			GUI_Show12Char(10,40,"ι��ʱ����1.28�룬���ι��ʱ�䳬��1.28�뽫ʹϵͳ��λ����",YELLOW,BLACK);
			GUI_Show12Char(200,380,"����",YELLOW,BLACK);	
		}
		IWDG_ReloadCounter();	   //ι����ʱ����1.28s
		GUI_Show12Char(10,100,"����ι��...",YELLOW,BLACK);
		//ֻҪ��ι��ʱ����ι���Ͳ�����ϵͳ��Ϊ�������븴λ״̬
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
