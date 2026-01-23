#include "extern.h"
#include "./USER/CONFIG/CONFIG.H"
#include "./USER/SLEEP/SLEEP.H"
#include "./USER/ISR/ISR.H"
#include "./USER/KEYSCAN/KEYSCAN.H"
#include "./USER/ENCODE/ENCODE.H"
#include "./USER/CHARGE/CHARGE.H"
#include "./USER/led/led.H"
#include "./USER/gpc/gpc.H"

void FPPA0 (void)
{
	.ADJUST_IC	SYSCLK=IHRC/16,Init_RAM;
	IO_init();
	nop;
	Timer16_Init();
	vdd_set = 4;
	while (1)
	{
		if(!CHARGE)
		{
			KEY_SCAN();
			CHARGE_STEP = 0;
			Func_LED();
			if((Sleep_delay == 0) && (key_time == 0)&& (key_time2 == 0)&& (key_time3 == 0)&& (key_time4 == 0) && !LED_icnt)
			{
				close_hardware();
				Power_down();
			}
		}
		else CHARGE_MOD();			
	}
}

void Interrupt(void)
{
	pushaf;
	if(Intrq.T16)
	{	
		STT16	Reload_T16;
		Intrq.T16 = 0;
		if(!charge)
		{
			if(!KEY1 && !Long_click)
			{
				key_time++;
				if(Power_down_flag == 0)
				{
					if(key_time >= 15000 )Long_click = 1;
					Sleep_Delay = 200;
				}
				else
				{
					if(key_time >= 20000 )Long_click = 1;
				}
			}
			if(!KEY2)
			{
				key_time2++;
			}
			if(!KEY3)
			{
				key_time3++;
			}
			if(!KEY4)
			{
				key_time4++;
			}
		}
		
		if(Sleep_delay)Sleep_delay--;
		LED_icnt_timer++;
		VDD_count++;
		charge_timer++;
		LED_icnt_timer_x++;
	}
	popaf;
}