#include "public.h"

void eeprom_task(void *pdata)    //任务
{	
	u8 wdata=0,value;
	u8 dat[6],dat1[6];
	pdata=pdata;
	while(1)
	{
		if(TOUCH_Scan() == 0)
		{			
			TFT_ClearScreen(BLACK);	
			GUI_Show12Char(10,10,"AT24C02存储器读写实验",YELLOW,BLACK);
			GUI_Show12Char(10,27,"PB10 PB11 是IIC接口",YELLOW,BLACK);
			GUI_Show12Char(10,44,"按K_UP键:对AT24C02写数据",YELLOW,BLACK);
			GUI_Show12Char(10,61,"按K_DOWM键:对AT24C02读数据",YELLOW,BLACK);
			GUI_Show12Char(10,100,"写数据的范围是: 0-255",YELLOW,BLACK);
			GUI_Show12Char(10,150,"Write data is:",YELLOW,BLACK);
			GUI_Show12Char(10,167,"Read data is:",YELLOW,BLACK);
			GUI_Show12Char(200,380,"返回",YELLOW,BLACK);	
		}
		if(k_up==1)		   //按键k_up按下写入数据
		{
			Delay_ms(10);
			if(k_up==1)
			{	
				AT24Cxx_WriteOneByte(0,++wdata);//写入的是单字节，0-255取值范围
				dat[0]=wdata/100+0x30;
				dat[1]=wdata%100/10+0x30;
				dat[2]=wdata%100%10+0x30;
				dat[3]='\0';
				GUI_Show12Char(160,150,dat,YELLOW,BLACK);	
			}
			while(k_up);
		}
		if(k_down==0)	   //读取数据
		{
			Delay_ms(10);
			if(k_down==0)
			{
				value=AT24Cxx_ReadOneByte(0);
				dat1[0]=value/100+0x30;
				dat1[1]=value%100/10+0x30;
				dat1[2]=value%100%10+0x30;
				dat1[3]='\0';
				GUI_Show12Char(160,167,dat1,YELLOW,BLACK);
			}
			while(!k_down);	
		}	
	
		Delay_ms(10);			
		if(TouchData.lcdx>200&&TouchData.lcdx<240&&TouchData.lcdy>380&&TouchData.lcdy<400)	
		{
			GUI_DisplayInit();
			TouchData.lcdx=0;
			TouchData.lcdy=0;
			OSTaskDel(EEPROM_TASK_PRIO);					
		}
	}
	
}
