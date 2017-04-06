#include "public.h"

void adx345_task(void *pdata)    //任务
{	
	int16_t value;
    uint8_t num = 6;
	int16_t Xval, Yval, Zval, Xang, Yang, Zang;
	uint8_t ShowData[6] = {0, 0, 0, 0, 0, 0};
	pdata=pdata;

	while(ADX345_Init())
    {
        GUI_Show12Char(60, 42, "ADX345 ERROR！", RED, BLACK);
        Delay_ms(100);        
    }
	while(1)
	{
		if(TOUCH_Scan() == 0)
		{			
			TFT_ClearScreen(BLACK);
		    GUI_Show12Char(10, 10, "ADX345加速度传感器实验", RED, BLACK);
		    GUI_Show12Char(0, 84, "X VAL:", RED, BLACK);
		    GUI_Show12Char(0, 105, "Y VAL:", RED, BLACK);
		    GUI_Show12Char(0, 126, "Z VAL:", RED, BLACK);
		    GUI_Show12Char(0, 147, "X ANG:", RED, BLACK);
		    GUI_Show12Char(0, 168, "Y ANG:", RED, BLACK);
		    GUI_Show12Char(0, 189, "Z ANG:", RED, BLACK);
			GUI_Show12Char(200,380,"返回",YELLOW,BLACK);
					
		}
		ADX345_Adjust();

		/* 读取X,Y,Z的加速度值 */
        ADX_GetXYZData(&Xval, &Yval, &Zval);

        /* 将读取到的加速度值转换为角度值 */
        Xang=ADX_GetAngle(Xval, Yval, Zval,1);    
		Yang=ADX_GetAngle(Xval, Yval, Zval,2);   
		Zang=ADX_GetAngle(Xval, Yval, Zval,0);

		while(num)
	    {
	        switch(num)
	        {
	            case(1):
	                value = Zang;
	                break;
	            case(2):
	                value = Yang;
	                break;
	            case(3):
	                value = Xang;
	                break;
	            case(4):
	                value = Zval;
	                break;
	            case(5):
	                value = Yval;
	                break;
	            case(6):
	                value = Xval;
	                break;
	            default:
	               break;
	        }
	        if(value > 0)
	        {
	            ShowData[0] = '+';
	        }
	        else
	        {
	            ShowData[0] = '-';
	            value = abs(value);//求出绝对值
	        }
	        ShowData[1] = (value % 10000 /1000) + '0';
	        ShowData[2] = (value % 1000 /100) + '0';
	        ShowData[3] = (value % 100 /10) + '0';
	        ShowData[4] = (value % 10) + '0';
	        
	        GUI_Show12Char(48, (210 - num*21), ShowData, RED, BLACK);
	        num--;
	    }
		num=6;
		Delay_ms(10);			
		if(TouchData.lcdx>200&&TouchData.lcdx<240&&TouchData.lcdy>380&&TouchData.lcdy<400)	
		{
			GUI_DisplayInit();
			TouchData.lcdx=0;
			TouchData.lcdy=0;
			OSTaskDel(ADX345_TASK_PRIO);					
		}
	}
	
}
