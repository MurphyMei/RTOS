#include "public.h"
void BEEP_Init()	  //¶Ë¿Ú³õÊ¼»¯
{
	GPIO_InitTypeDef GPIO_InitStructure;

//	SystemInit();
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);

	GPIO_InitStructure.GPIO_Pin=BZ;
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Init(GPIOB,&GPIO_InitStructure); 	
}


