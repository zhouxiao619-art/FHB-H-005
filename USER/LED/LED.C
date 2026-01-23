#include "LED.H"
#include 	"../CONFIG/CONFIG.H"
#include 	"../keyscan/keyscan.H"		
#include 	"../gpc/gpc.H"	

BYTE LED_icnt;
word flash_time;

void Led_start(byte count,word time)
{
	LED_icnt = count;
	flash_time = time;
	if(boot_mark)
	{
		if(vdd_set==4)
		{
			led1 = 1;
			led2 = 1;
			led3 = 1;
			led4 = 1;
		}
		else if(vdd_set==3) 
		{
			led1 = 1;
			led2 = 1;
			led3 = 1;
			led4 = 1;
		}
		else if(vdd_set==2)
		{
			led1 = 1;
			led2 = 1;
			led3 = 1;
		}
		else if(vdd_set==1)
		{
			led1 = 1;
			led2 = 1;
		}
		else if(vdd_set == 0) 
		{
			led1 = 1;
		}
	}
	else
	{
		led1 = 1;
		led2 = 1;
		led3 = 1;
		led4 = 1;
	}
	LED_icnt_timer = 0;
}

void Func_LED()
{
	if(LED_icnt)
	{
		if(LED_icnt_timer > flash_time)
		{
			LED_icnt_timer = 0;
			LED_icnt--;
			if(boot_mark)
			{
				if(!led_icnt)	boot_mark = 0;
				if(vdd_set==4)
				{
					
				}
				else if(vdd_set==3)
				{
					$ led4 toggle;	
				}
				else if(vdd_set==2)
				{
					$ led3 toggle;
				}
				else if(vdd_set==1)
				{
					$ led2 toggle;
				}
				else if(vdd_set == 0)
				{
					$ led1 toggle;	
				}
			}
			else
			{
				$ led1 toggle;
				$ led2 toggle;
				$ led3 toggle;
				$ led4 toggle;
			}
		}
	}
}