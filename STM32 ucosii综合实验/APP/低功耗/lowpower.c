#include "public.h"
void standmodeinit()   //待机模式
{	
	NVIC_SystemLPConfig(NVIC_LP_SLEEPDEEP,ENABLE);//选择系统进入低功耗模式的条件	
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_PWR,ENABLE);//使能PWR外设时钟	
	PWR_WakeUpPinCmd(ENABLE);//使能唤醒管脚	使能或者失能唤醒管脚功能
	PWR_EnterSTANDBYMode();//进入待机模式		
}
void low_pros()
{
	while(1)
	{
		if(TOUCH_Scan() == 0)
		{		
			TFT_ClearScreen(BLACK);
			GUI_Show12Char(10,10,"低功耗-待机模式实验",YELLOW,BLACK);	
			GUI_Show12Char(10,30,"K_LEFT: 进入待机模式！",YELLOW,BLACK);
			GUI_Show12Char(10,50,"K_UP: 退出待机模式！",YELLOW,BLACK);
			GUI_Show12Char(10,130,"等待进入待机模式...",YELLOW,BLACK);
			GUI_Show12Char(10,180,"进入待机模式以后按下K_UP键退出返回主界面",YELLOW,BLACK);
			GUI_Show12Char(200,380,"返回",YELLOW,BLACK);		
		}	
		if(k_left==0)
		{
			delay_ms(10);
			if(k_left==0)
			{
				GUI_Show12Char(10,130,"***进入待机模式！***",YELLOW,BLACK);
				standmodeinit();   //待机模式
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
