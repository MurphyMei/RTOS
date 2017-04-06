#include "public.h"
void dac_init()
{
	GPIO_InitTypeDef GPIO_InitStructure;
	DAC_InitTypeDef DAC_InitStructure;

	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA|RCC_APB2Periph_AFIO,ENABLE);
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_DAC,ENABLE);

	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_4;//DAC_1
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_AIN;//模拟量输入
	GPIO_Init(GPIOA,&GPIO_InitStructure);
	GPIO_SetBits(GPIOA,GPIO_Pin_4);//输出高
	

	DAC_InitStructure.DAC_Trigger=DAC_Trigger_None;//不使用触发功能
    DAC_InitStructure.DAC_WaveGeneration=DAC_WaveGeneration_None;//不使用三角波
   //屏蔽 幅值设置
    DAC_InitStructure.DAC_LFSRUnmask_TriangleAmplitude=DAC_LFSRUnmask_Bit0;
   //关闭缓存
    DAC_InitStructure.DAC_OutputBuffer=DAC_OutputBuffer_Disable;
    DAC_Init(DAC_Channel_1,&DAC_InitStructure);//初始化DAC通道1
    DAC_Cmd(DAC_Channel_1,ENABLE);//使能DAC1
    DAC_SetChannel1Data(DAC_Align_12b_R,0);//12位 右对齐 写0数据
}
void DAC_pros()
{
	u16 value;
	float da;
	u8 i=0,dat[7];
	while(1)
	{
		if(TOUCH_Scan() == 0)
		{		
			TFT_ClearScreen(BLACK);		
			GUI_Show12Char(10,10,"This is a DAC-Channel1-PWM Check!",YELLOW,BLACK);
			GUI_Show12Char(10,100,"The Output Vologe is:",YELLOW,BLACK);
			GUI_Show12Char(200,380,"返回",YELLOW,BLACK);		
		}

		value=0;
		for(i=0;i<=10;i++)	
		{
			value=i*400;
			DAC_SetChannel1Data(DAC_Align_12b_R,value);//12位 右对齐 PA4 端口输出	
			da=3.3*value/4095;
			value=da*100;
			dat[0]=value/100+0x30;
			dat[1]='.';
			dat[2]=value%100/10+0x30;
			dat[3]=value%100%10+0x30;
			dat[4]='V';
			dat[5]='\0';
			GUI_Show12Char(180,100,dat,YELLOW,BLACK);
			if(TouchData.lcdx>200&&TouchData.lcdx<240&&TouchData.lcdy>380&&TouchData.lcdy<400)	
			{
				break;					
			}
			TOUCH_Scan();
			delay_ms(500);	
		}

		if(TouchData.lcdx>200&&TouchData.lcdx<240&&TouchData.lcdy>380&&TouchData.lcdy<400)	
		{
			GUI_DisplayInit();
			break;					
		}
		TOUCH_Scan();
	}	
} 
 


