#include "public.h"

void adc_task(void *pdata)    //任务
{
	float ad;
	u8 dat[6];
	u8 i;
	u16 ad_value;
	pdata=pdata;
	while(1)
	{
		if(TOUCH_Scan() == 0)
		{		
			TFT_ClearScreen(BLACK);
			GUI_Show12Char(10,10,"AD转换实验",YELLOW,BLACK);
			GUI_Show12Char(10,50,"通过调节ADC模块内的电位器可以改变检测电压",YELLOW,BLACK);	
			GUI_Show12Char(10,100,"AD检测值是：",YELLOW,BLACK);
		
			GUI_Show12Char(200,380,"返回",YELLOW,BLACK);	
		}		
		
		ad_value=0;
		for(i=0;i<10;i++)//读取50次的AD数值取其平均数较为准确	
		{
			ADC_SoftwareStartConvCmd(ADC1, ENABLE);
			while(!ADC_GetFlagStatus(ADC1,ADC_FLAG_EOC));//转换结束标志位
			ad_value=ad_value+ADC_GetConversionValue(ADC1);//返回最近一次ADCx规则组的转换结果		
		}
		ad_value=ad_value/10;
		ad=ad_value*3.3/4096;
		ad_value=(u16)(ad*100);
		dat[0]=ad_value/100+0x30;
		dat[1]='.';
		dat[2]=ad_value%100/10+0x30;
		dat[3]=ad_value%100%10+0x30;
		dat[4]='V';
		dat[5]='\0';
		GUI_Show12Char(107,100,dat,YELLOW,BLACK);
		Delay_ms(10);			
		if(TouchData.lcdx>200&&TouchData.lcdx<240&&TouchData.lcdy>380&&TouchData.lcdy<400)	
		{
			GUI_DisplayInit();
			TouchData.lcdx=0;
			TouchData.lcdy=0;
			OSTaskDel(ADC_TASK_PRIO);					
		}
	}
	
}
