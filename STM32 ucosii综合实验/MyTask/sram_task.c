#include "public.h"

void sram_task(void *pdata)    //����
{	
	uint8_t showData[5]={0,0,0,0,0};
	u16 cap;
	u8 sbuf[15]="www.prechin.com";
	pdata=pdata;

	while(1)
	{
		if(TOUCH_Scan() == 0)
		{			
			TFT_ClearScreen(BLACK);	
			GUI_Show12Char(10, 0, "SRAM ����...", RED, BLACK);
			GUI_Show12Char(10, 18, "����K_up д����", RED, BLACK);
			GUI_Show12Char(10, 36, "����K_down ������", RED, BLACK);
			GUI_Show12Char(10, 64, "SRAM Cap:     KB", RED, BLACK);
			GUI_Show12Char(200,380,"����",YELLOW,BLACK);
					
		}
		cap=SRAM_Test();
		/* ��ʾ��ȡ�������� */
	    showData[0] = (cap % 10000 /1000) + '0';
	    showData[1] = (cap % 1000 /100) + '0';
	    showData[2] = (cap % 100 /10) + '0';
	    showData[3] = (cap % 10) + '0';
	    GUI_Show12Char(83, 64, showData, RED, BLACK);

		if(k_up==1)
		{
			Delay_ms(10);
			if(k_up==1)	
			{	
				SRAM_WriteBuffer((uint16_t *)sbuf, 2, 15);
				GUI_Show12Char(10, 86, "Write OK!", RED, BLACK);		
			}
			while(k_up);
		}
		
		if(k_down==0)
		{
			Delay_ms(10);
			if(k_down==0)
			{
				GUI_Show12Char(10, 106, "Read OK!", RED, BLACK);
				SRAM_ReadBuffer((uint16_t *)sbuf, 2, 15);
				GUI_Show12Char(10, 126, sbuf, RED, BLACK);
			}
			while(!k_down);			
		}

		Delay_ms(10);			
		if(TouchData.lcdx>200&&TouchData.lcdx<240&&TouchData.lcdy>380&&TouchData.lcdy<400)	
		{
			GUI_DisplayInit();
			TouchData.lcdx=0;
			TouchData.lcdy=0;
			OSTaskDel(SRAM_TASK_PRIO);					
		}
	}
	
}
