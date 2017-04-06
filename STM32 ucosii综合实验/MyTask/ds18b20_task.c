#include "public.h"

void ds18b20_task(void *pdata)    //����
{	

	double temp;
	u16 tem_dat;
	u8 dat[8];
	pdata=pdata;
	while(1)
	{
		if(TOUCH_Scan() == 0)
		{			
			TFT_ClearScreen(BLACK);	
			GUI_Show12Char(10,10,"DS18B20�¶ȼ�⣺",YELLOW,BLACK);
			GUI_Show12Char(10,40,"���¶ȴ�������������ӿ��ϣ�ע���¶ȴ������ķ��򣬰������ж�Ӧ��˿ӡָʾ",YELLOW,BLACK);
			GUI_Show12Char(200,380,"����",YELLOW,BLACK);	
		}
			
		temp=readtemp();
		tem_dat=temp*100;
		dat[0]=tem_dat/1000+0x30;
		dat[1]=tem_dat%1000/100+0x30;
		dat[2]='.';
		dat[3]=tem_dat%1000%100/10+0x30;
		dat[4]=tem_dat%1000%100%10+0x30;
		dat[5]='C';
		dat[6]='\0';
		GUI_Show12Char(150,10,dat,YELLOW,BLACK);

		Delay_ms(10);			
		if(TouchData.lcdx>200&&TouchData.lcdx<240&&TouchData.lcdy>380&&TouchData.lcdy<400)	
		{
			GUI_DisplayInit();
			TouchData.lcdx=0;
			TouchData.lcdy=0;
			OSTaskDel(TEMP_TASK_PRIO);					
		}
	}
	
}
