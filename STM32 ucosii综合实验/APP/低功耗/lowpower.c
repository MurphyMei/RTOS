#include "public.h"
void standmodeinit()   //����ģʽ
{	
	NVIC_SystemLPConfig(NVIC_LP_SLEEPDEEP,ENABLE);//ѡ��ϵͳ����͹���ģʽ������	
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_PWR,ENABLE);//ʹ��PWR����ʱ��	
	PWR_WakeUpPinCmd(ENABLE);//ʹ�ܻ��ѹܽ�	ʹ�ܻ���ʧ�ܻ��ѹܽŹ���
	PWR_EnterSTANDBYMode();//�������ģʽ		
}
void low_pros()
{
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
			delay_ms(10);
			if(k_left==0)
			{
				GUI_Show12Char(10,130,"***�������ģʽ��***",YELLOW,BLACK);
				standmodeinit();   //����ģʽ
			}
		}		

		if(TouchData.lcdx>200&&TouchData.lcdx<240&&TouchData.lcdy>380&&TouchData.lcdy<400)	
		{
			GUI_DisplayInit();
			break;					
		}
		TOUCH_Scan();
	}	
}
