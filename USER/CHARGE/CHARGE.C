#include "CHARGE.H"
#include 	"../CONFIG/CONFIG.H"
#include  	"../KEYSCAN/KEYSCAN.H"
#include  	"../gpc/gpc.H"

Byte CHARGE_STEP;
word LED_icnt_timer_x;
word charge_timer;

void CHARGE_MOD(void)
{
	if(CHARGE_STEP == 0) //充电检测
	{
		.delay 10000;
		if(CHARGE)
		{
			Power_down_flag = 0;	//充电玩成进入 省电模式
			CHARGE_STEP = 1;
			VDD_count = 0;
			LED1 = 0;
			LED2 = 0;
			led3 = 0;
			led4 = 0;
			Long_click = 0xFF;
			key_time = 0;
			vdd_set = 0;
		}
	}

	if(CHARGE_STEP == 1)	//充电闪烁
	{
		if(charge_full)
		{
			if(charge_timer >= 3000)CHARGE_STEP = 2;
		}
		else charge_timer = 0;
	
		if(VDD_set == 0)
		{
			GPC_Init_charge();
			if(GPC_out)
			{
				if(VDD_count > 5)
				{
					VDD_set = 1;
					VDD_count = 0;		//3+
				}
			}
			else
			{
				VDD_count = 0;			//3-
			}
			if(LED_icnt_timer_x > 5000)
			{
				LED_icnt_timer_x = 0;
				$ led1 toggle;
			}
			led2 = 0;
			led3 = 0;
			led4 = 0;
		}
		else if(VDD_set == 1)
		{
			GPC_Init_charge();
			if(GPC_out)
			{
				if(VDD_count > 5)
				{
					VDD_set = 2;
					VDD_count = 0;		//3.3+
				}
				
				if(LED_icnt_timer_x > 5000)
				{
					LED_icnt_timer_x = 0;
					$ led2 toggle;
				}
				led1 = 1;
				led3 = 0;
				led4 = 0;
			}
			else
			{
				VDD_count = 0;			//3+
				if(LED_icnt_timer_x > 5000)
				{
					LED_icnt_timer_x = 0;
					$ led1 toggle;
				}
				led2 = 0;
				led3 = 0;
				led4 = 0;
			}
		}
		else if(VDD_set == 2)
		{
			GPC_Init_charge();
			if(GPC_out)
			{
				if(VDD_count > 5)		//3.6+
				{
					VDD_set = 3;
					VDD_count = 0;
				}
				if(LED_icnt_timer_x > 5000)
				{
					LED_icnt_timer_x = 0;
					$ led3 toggle;
				}
				led1 = 1;
				led2 = 1;
				led4 = 0;
			}
			else
			{
				VDD_count = 0;			//3.3+
				if(LED_icnt_timer_x > 5000)
				{
					LED_icnt_timer_x = 0;
					$ led2 toggle;
				}
				led1 = 1;
				led3 = 0;
				led4 = 0;
			}
		}
		else if(VDD_set == 3)
		{
			GPC_Init_charge();
			if(GPC_out)
			{
				if(VDD_count > 5)		//3.84+
				{
					VDD_set = 4;
					VDD_count = 0;
				}
				if(LED_icnt_timer_x > 5000)
				{
					LED_icnt_timer_x = 0;
					$ led4 toggle;
				}
				led1 = 1;
				led2 = 1;
				led3 = 1;
			}
			else
			{
				VDD_count = 0;		//3.6+
				if(LED_icnt_timer_x > 5000)
				{
					LED_icnt_timer_x = 0;
					$ led3 toggle;
				}
				led1 = 1;
				led2 = 1;
				led4 = 0;
			}
		}
		else if(VDD_set == 4)
		{
			GPC_Init_charge();
			if(GPC_out)
			{
				VDD_count = 0;		//4.1+
				if(LED_icnt_timer_x > 5000)
				{
					LED_icnt_timer_x = 0;
					$ led4 toggle;
				}
				led1 = 1;
				led2 = 1;
				led3 = 1;
			}
			else
			{
				VDD_count = 0;			//3.84+
				if(LED_icnt_timer_x > 5000)
				{
					LED_icnt_timer_x = 0;
					$ led4 toggle;
				}
				led1 = 1;
				led2 = 1;
				led3 = 1;
			}
		}
	}

	if(CHARGE_STEP == 2)	//充满常亮
	{
		led1 = 1;
		led2 = 1;
		led3 = 1;
		led4 = 1;
	}
}