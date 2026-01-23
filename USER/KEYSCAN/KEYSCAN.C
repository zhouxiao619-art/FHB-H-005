#include "KEYSCAN.H"
#include 	"../CONFIG/CONFIG.H"
#include 	"../SLEEP/SLEEP.H"
#include 	"../ENCODE/ENCODE.H"
#include 	"../gpc/gpc.H"
#include 	"../led/led.H"

word key_time;
byte Long_click;
byte Long_click_bak;
word key_time2;
word key_time3;
word key_time4;

void KEY_SCAN()
{
	if(KEY1)
	{
		key_time = 0;
		Long_click = 0;
	}

	if(Long_click_bak != Long_click)		//long_click
	{
		if(Power_down_flag)
		{
			if(Long_click == 1)		
			{     
				Led_start(1,750);
				DISGINT;
				send_icnt = 7;
				data = 0xAB5C;				//´ý»úÂë
				do
				{
					RF_Encode();
				}while(send_icnt--);
				ENGINT;
				Power_down_flag = 0;
				Long_click = 0xff;
				key_time = 0;   
			}
		}
		else
		{
			if(Long_click == 1)	
			{
				Measure_GPC_boot();
				Led_start(6,5000);
				Power_down_flag = 1;
				Long_click = 0xff;
				key_time = 0;
			}
		}
		Long_click_bak = Long_click;
	}

	if(KEY2)
	{
		if(key_time2 >= SINGLE_KEY_TIME)
		{
			if(Power_down_flag)
			{
				Led_start(1,750);
				DISGINT;
				send_icnt = 7;
				data = 0xACCA;				//Ôö¼ÓÂë
				do
				{
					RF_Encode();
				}while(send_icnt--);
				ENGINT;
			}
		}
		key_time2 = 0;
	}

	if(KEY3)
	{
		if(key_time3 >= SINGLE_KEY_TIME)
		{
			if(Power_down_flag)
			{
				Led_start(1,750);
				DISGINT;
				send_icnt = 7;
				data = 0xADDA;				//¼õÉÙÂë
				do
				{
					RF_Encode();
				}while(send_icnt--);
				ENGINT;
			}
		}
		key_time3 = 0;
	}

	if(KEY4)
	{
		if(key_time4 >= SINGLE_KEY_TIME)
		{
			if(Power_down_flag)
			{
				Led_start(1,750);
				DISGINT;
				send_icnt = 7;
				data = 0xAEEA;				//ÔÝÍ£Âë
				do
				{
					RF_Encode();
				}while(send_icnt--);
				ENGINT;
			}
		}
		key_time4 = 0;
	}
}











