#include "public.h"

/*******************************************************************************
* 函 数 名         : ds18b20_init
* 函数功能		   : IO端口时钟初始化函数	   
* 输    入         : 无
* 输    出         : 无
*******************************************************************************/
void ds18b20_init()
{
	GPIO_InitTypeDef GPIO_InitStructure;

	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOG,ENABLE);

	GPIO_InitStructure.GPIO_Pin=dq;
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Init(GPIO_ds18b20,&GPIO_InitStructure);
}

/*******************************************************************************
* 函 数 名         : DQININT
* 函数功能		   : 输入配置	   
* 输    入         : 无
* 输    出         : 无
*******************************************************************************/
void DQININT()	 //输入配置
{
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Pin=dq;
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_IN_FLOATING;
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Init(GPIO_ds18b20,&GPIO_InitStructure);	
}

/*******************************************************************************
* 函 数 名         : DQOUTINT
* 函数功能		   : 输出配置	   
* 输    入         : 无
* 输    出         : 无
*******************************************************************************/
void DQOUTINT()	 //输出配置
{
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Pin=dq;
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Init(GPIO_ds18b20,&GPIO_InitStructure);	
}

/*******************************************************************************
* 函 数 名         : ds18b20init
* 函数功能		   : DS18B20初始化时序	   
* 输    入         : 无
* 输    出         : 无
*******************************************************************************/
void ds18b20init()
{
	DQOUTINT();//输出
	ds18b20_dq_L;
	Delay_us(480);//延时480微妙	
	ds18b20_dq_H;
	Delay_us(480);//延时480微妙
}

/*******************************************************************************
* 函 数 名         : ds18b20wr
* 函数功能		   : DS18B20写数据时序	   
* 输    入         : dat
* 输    出         : 无
*******************************************************************************/
void ds18b20wr(u8 dat)
{
	u8 i=0;
	DQOUTINT();//输出

	for(i=0;i<8;i++)
	{
		ds18b20_dq_L;	 //拉低
		Delay_us(15);//延时15微妙
		
		if((dat&0x01)==1)
		{
			ds18b20_dq_H;
		}
		else
		{
			ds18b20_dq_L;
		}
		Delay_us(60);//延时60微妙
		ds18b20_dq_H;
		
		dat>>=1;//准备下一位数据的发送	
	}
}

/*******************************************************************************
* 函 数 名         : DS18b20rd
* 函数功能		   : DS18B20读数据时序	   
* 输    入         : 无
* 输    出         : value
*******************************************************************************/
u8 DS18b20rd()
{
	u8 i=0,value=0;

	for(i=0;i<8;i++)
	{
		value>>=1;
		DQOUTINT();//输出
		ds18b20_dq_L;	 //拉低
		Delay_us(4);//延时4微妙
		ds18b20_dq_H;
		Delay_us(10);//延时10微妙
		DQININT();	 //输入配置

		if(GPIO_ReadInputDataBit(GPIO_ds18b20,dq)==1)
		{
		   value|=0x80;//读数据 从低位开始
		}

		Delay_us(45);//延时45微妙
	}

	return value;	
}

/*******************************************************************************
* 函 数 名         : readtemp
* 函数功能		   : DS18B2温度寄存器配置，温度读取	   
* 输    入         : 无
* 输    出         : value
*******************************************************************************/
double readtemp()			  //读取温度内需要复位的
{
	u16 temp;
	u8 a,b;
	double value;
	ds18b20init();		//初始化
	ds18b20wr(0xcc);   //发送忽略ROM指令
	ds18b20wr(0x44);   //发送温度转换指令
	Delay_ms(10);	 
	ds18b20init();	   //初始化
	ds18b20wr(0xcc);   //发送忽略ROM指令
	ds18b20wr(0xbe);   //发读暂存器指令
	a=DS18b20rd();	 //温度的低八位
	b=DS18b20rd();	 //温度的高八位
	temp=b;
	temp=(temp<<8)+a;
	if((temp&0xf800)==0xf800)
	{
		temp=(~temp)+1;
		value=temp*(-0.0625);
	}
	else
	{
		value=temp*0.0625;	
	}
	return value;
}
void DS18B20_pros()
{
	double temp;
	u16 tem_dat;
	u8 dat[8];
	while(1)
	{
	//	if(TouchData.lcdx>170&&TouchData.lcdx<230&&TouchData.lcdy>60&&TouchData.lcdy<100)	
//		{
			if(TOUCH_Scan() == 0)
			{		
				TFT_ClearScreen(BLACK);	
				GUI_Show12Char(10,10,"DS18B20温度检测：",YELLOW,BLACK);
				GUI_Show12Char(200,380,"返回",YELLOW,BLACK);	
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
//		}
		if(TouchData.lcdx>200&&TouchData.lcdx<240&&TouchData.lcdy>380&&TouchData.lcdy<400)	
		{
			GUI_DisplayInit();
			break;					
		}
		TOUCH_Scan();	
	}
			
}

