#include "public.h"
void rs485_init()
{
	GPIO_InitTypeDef GPIO_InitStructure;

	USART_InitTypeDef USART_InitStructure;

	NVIC_InitTypeDef NVIC_InitStructure;

	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOG|RCC_APB2Periph_GPIOA|RCC_APB2Periph_AFIO,ENABLE);
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_USART2,ENABLE);

	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_2;	//TX-485
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_AF_PP;
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Init(GPIOA,&GPIO_InitStructure);
	
	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_3;	//CS-485
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Init(GPIOG,&GPIO_InitStructure);

	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_3;	//RX-485
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_IN_FLOATING;
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Init(GPIOA,&GPIO_InitStructure);


	USART_InitStructure.USART_BaudRate = 9600;
	USART_InitStructure.USART_WordLength = USART_WordLength_8b;
	USART_InitStructure.USART_StopBits = USART_StopBits_1;
	USART_InitStructure.USART_Parity = USART_Parity_No;
	USART_InitStructure.USART_HardwareFlowControl =USART_HardwareFlowControl_None;
	USART_InitStructure.USART_Mode = USART_Mode_Tx | USART_Mode_Rx;
	USART_Init(USART2, &USART_InitStructure);	
	USART_Cmd(USART2,ENABLE);	
	USART_ITConfig(USART2,USART_IT_RXNE,ENABLE);
	USART_ClearFlag(USART2,USART_FLAG_TC);


	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_1);
	NVIC_InitStructure.NVIC_IRQChannel = USART2_IRQn; 
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1; 
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE; 
	NVIC_Init(&NVIC_InitStructure);
}
void RS485_pros()
{
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
			break;					
		}
		TOUCH_Scan();		
	}	
}

