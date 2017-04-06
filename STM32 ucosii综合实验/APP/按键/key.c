#include "public.h"
void key_init()
{
	GPIO_InitTypeDef GPIO_InitStructure;

//	SystemInit();
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA|RCC_APB2Periph_GPIOE,ENABLE);

	GPIO_InitStructure.GPIO_Pin=K_UP;
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_IPD;//下拉输入  //不能选择浮空输入否则会出错
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Init(GPIOA,&GPIO_InitStructure);
	
	GPIO_InitStructure.GPIO_Pin=K_DOWN|K_LEFT|K_RIGHT;
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_IPU;	//上拉输入
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Init(GPIOE,&GPIO_InitStructure);
				
	GPIO_ResetBits(GPIOA,K_UP);	//对K_UP初始化输出0
}

void key_pros()	  //按键处理函数
{
	while(1)
	{
		//if(TouchData.lcdx>90&&TouchData.lcdx<150&&TouchData.lcdy>60&&TouchData.lcdy<100)	
		//{
			if(TOUCH_Scan() == 0)
			{		
				TFT_ClearScreen(BLACK);	
				GUI_Show12Char(100,10,"按键测试",YELLOW,BLACK);
				GUI_Show12Char(200,380,"返回",YELLOW,BLACK);
				GUI_Box(10, 180, 70,220, YELLOW);	
				GUI_Box(90, 180, 150,220, YELLOW);
				GUI_Box(10, 240, 70,280, YELLOW);	
				GUI_Box(90, 240, 150,280, YELLOW);
				
			}
			if(k_up==1)	  //判断按键k_up是否按下
			{
				delay_ms(10); //消抖处理
				if(k_up==1)	 //再次判断按键k_up是否按下
				{
					GUI_Box(10, 180, 70,220, BLUE);					
				}
				while(k_up); //等待按键松开
			}
			if(k_down==0)
			{
				delay_ms(10);
				if(k_down==0)
				{
					GUI_Box(90, 180, 150,220, BLUE);			
				}
				while(!k_down);
			}
			if(k_left==0)
			{
				delay_ms(10);
				if(k_left==0)
				{
					GUI_Box(10, 240, 70,280, BLUE);			
				}
				while(!k_left);
			}
			if(k_right==0)
			{
				delay_ms(10);
				if(k_right==0)
				{
					GUI_Box(90, 240, 150,280, BLUE);			
				}
				while(!k_right);
			}			
	//	}
		if(TouchData.lcdx>200&&TouchData.lcdx<240&&TouchData.lcdy>380&&TouchData.lcdy<400)	
		{
			GUI_DisplayInit();
			break;					
		}
		TOUCH_Scan();
	}
	
}

