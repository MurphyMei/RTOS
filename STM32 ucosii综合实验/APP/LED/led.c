#include "public.h"
void LED_Init()	  //¶Ë¿Ú³õÊ¼»¯
{
	GPIO_InitTypeDef GPIO_InitStructure;

//	SystemInit();
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC,ENABLE);

	GPIO_InitStructure.GPIO_Pin=LED;
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Init(GPIOC,&GPIO_InitStructure);
	GPIO_Write(GPIOC,(u16)(0xff)); 	
}

