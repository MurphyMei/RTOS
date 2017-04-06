#include "public.h"

void RCC_Init(void)
{
	SystemInit();	
}
void GUI_DisplayInit(void)
{
    TFT_ClearScreen(CYAN);
    GUI_Box(10, 0, 70,40, YELLOW);
	GUI_Show12Char(20,10,"LED灯",BLACK,YELLOW);
		
	GUI_Box(90, 0, 150,40, BLUE);
	GUI_Show12Char(95,10,"蜂鸣器",BLACK,YELLOW);

	GUI_Box(170, 0, 230,40, RED);
	GUI_Show12Char(175,10,"数码管",BLACK,YELLOW);

	GUI_Box(10, 60, 70,100, YELLOW);
	GUI_Show12Char(15,70,"AD转换",BLACK,YELLOW);
		
	GUI_Box(90, 60, 150,100, BLUE);
	GUI_Show12Char(103,70,"按键",BLACK,YELLOW);

	GUI_Box(170, 60, 230,100, RED);
	GUI_Show12Char(172,70,"DS18B20",BLACK,YELLOW);

	GUI_Box(10, 120, 70,160, YELLOW);
	GUI_Show12Char(15,130,"EEPROM",BLACK,YELLOW);
		
	GUI_Box(90, 120, 150,160, BLUE);
	GUI_Show12Char(93,130,"RTC时钟",BLACK,YELLOW);

	GUI_Box(170, 120, 230,160, RED);
	GUI_Show12Char(183,130,"红外",BLACK,YELLOW);

	GUI_Box(10, 180, 110,220, YELLOW);
	GUI_Show12Char(20,190,"独立看门狗",BLACK,YELLOW);
		
	GUI_Box(130, 180, 230,220, RED);
	GUI_Show12Char(148,190,"字库更新",BLACK,YELLOW);

	GUI_Box(10, 240, 70,280, YELLOW);
	GUI_Show12Char(15,250,"低功耗",BLACK,YELLOW);
		
	GUI_Box(90, 240, 150,280, BLUE);
	GUI_Show12Char(100,250,"FLASH",BLACK,YELLOW);

	GUI_Box(170, 240, 230,280, RED);
	GUI_Show12Char(182,250,"SD卡",BLACK,YELLOW);

	GUI_Box(10, 300, 70,340, YELLOW);
	GUI_Show12Char(15,310,"ADX345",BLACK,YELLOW);
	
	GUI_Box(90, 300, 150,340, BLUE);
	GUI_Show12Char(105,310,"SRAM",BLACK,YELLOW);	
	
	GUI_Box(170, 300, 230,340, RED);
	GUI_Show12Char(174,310,"DA转换",BLACK,YELLOW);
  
	GUI_Box(0, 360, 60,399, YELLOW);
	GUI_Show12Char(2,370,"COM通信",BLACK,YELLOW);

	GUI_Box(70, 360, 130,399, BLUE);
	GUI_Show12Char(72,370,"485通信",BLACK,YELLOW);

	GUI_Box(140, 360, 200,399, RED);
	GUI_Show12Char(142,370,"CAN通信",BLACK,YELLOW);
}
int main()
{
	Delay_Init();
	RCC_Init();
	TFT_Init();	 //TFT彩屏初始化	
	FLASH_Init();
	TOUCH_Init();
	GUI_DisplayInit();

	LED_Init();	  //端口初始化
	BEEP_Init();	  //端口初始化
	smg_init();
	adc_init();
	key_init();
	ds18b20_init();
	I2C_INIT();
	rtc_init();
	clockinit_RTC();
	hwjs_init();   //红外接口初始化
	SRAM_Config();
	dac_init();	   //dac配置初始化


	OSInit();  //初始化UCOS操作系统	
	OSTaskCreate(start_task,(void *)0,(OS_STK *)&START_TASK_STK[START_STK_SIZE-1]
	,START_TASK_PRIO);  //创建起始任务
	OSStart();   //启动ucos操作系统			
}
