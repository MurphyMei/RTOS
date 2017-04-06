#include "public.h"

void sd_task(void *pdata)    //����
{	
	u32 sdCapacity;
    uint8_t num[6] = {0, 0, 0, 0, 0, 0};
	pdata=pdata;
	
	while(1)
	{
		if(TOUCH_Scan() == 0)
		{			
			TFT_ClearScreen(BLACK);
			GUI_Show12Char(10,10,"SD������ʵ��",YELLOW,BLACK);	
			GUI_Show12Char(10,30,"�ɼ���SD�����ͺ�����",YELLOW,BLACK);

			GUI_Show12Char(200,380,"����",YELLOW,BLACK);
					
		}
		while(SD_Init())
		{
			GUI_Show12Char(0, 84, "SD card initialize error!", RED, BLACK);
			break;
		}
		GUI_Show12Char(0, 84, "SD card initialize OK!   ", RED, BLACK);
	

		SD_ReadCapacity(&sdCapacity);
		sdCapacity >>= 11; //��KBתΪMB
	 
		/* ��ʾSD������ */
	    if(SD_TYPE == 0x06)
		{
			GUI_Show12Char(0, 105, "SDV2HC OK!", RED, BLACK);
		}
		else if(SD_TYPE == 0x04)
		{
			GUI_Show12Char(0, 105, "SDV2 OK!", RED, BLACK);
		}
		else if(SD_TYPE == 0x02)
		{
			GUI_Show12Char(0, 105, "SDV1 OK!", RED, BLACK);
		}
		else if(SD_TYPE == 0x01)
		{
			GUI_Show12Char(0, 105, "MMC OK!", RED, BLACK);
		}
	
	    /* ��ʾSD������ */
		num[0] = (sdCapacity /10000 % 10) + '0';
		num[1] = (sdCapacity /1000 % 10) + '0';
		num[2] = (sdCapacity /100 % 10) + '0';
		num[3] = (sdCapacity /10 % 10) + '0';
		num[4] = (sdCapacity % 10) + '0';
		GUI_Show12Char(0, 126, "SD size:      MB", RED, BLACK);
	    GUI_Show12Char(64, 126, num, RED, BLACK);

		Delay_ms(100);			
		if(TouchData.lcdx>200&&TouchData.lcdx<240&&TouchData.lcdy>380&&TouchData.lcdy<400)	
		{
			GUI_DisplayInit();
			TouchData.lcdx=0;
			TouchData.lcdy=0;
			OSTaskDel(SD_TASK_PRIO);					
		}
	}
	
}
