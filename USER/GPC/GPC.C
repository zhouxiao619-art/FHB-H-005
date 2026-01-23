#include "GPC.H"
#include 	"../CHARGE/CHARGE.H"

word VDD_count;
byte	VDD_Set;
bit boot_mark;		//∆Ù∂Ø≤‚—πÕÍ≥…

void	GPC_Init(void)
{
	$ GPCC Enable,BANDGAP,P_R;
	switch(VDD_Set)
	{
		case 0:
	//		$ GPCS VDD*14/32;//VDD = 2.74285714285714V
	//		$ GPCS VDD*17/40;//VDD = 2.82352941176471V
	//		$ GPCS VDD*10/24;//VDD = 2.88V
	//		$ GPCS VDD*17/40;//VDD = 2.8V
			$ GPCS VDD*16/40;//VDD = 3.0V
		break;

		case 1:
	//		$ GPCS VDD*16/40;//VDD = 3.0V
			$ GPCS VDD*12/32;//VDD = 3.2V
	//		$ GPCS VDD*14/40;//VDD = 3.42857142857143V
	//		$ GPCS VDD*11/32;//VDD = 3.49090909090909V
	//		$ GPCS VDD*8/24;//VDD = 3.6V
	//		$ GPCS VDD*10/32;//VDD = 3.84V
	//		$ GPCS VDD*7/24;//VDD = 4.11428571428571V
		break;
		case 2:
	//		$ GPCS VDD*16/40;//VDD = 3.0V
	//		$ GPCS VDD*12/32;//VDD = 3.2V
	//		$ GPCS VDD*14/40;//VDD = 3.42857142857143V
	//		$ GPCS VDD*11/32;//VDD = 3.49090909090909V
			$ GPCS VDD*8/24;//VDD = 3.6V
	//		$ GPCS VDD*10/32;//VDD = 3.84V
	//		$ GPCS VDD*7/24;//VDD = 4.11428571428571V
		break;
		case 3:
	//		$ GPCS VDD*16/40;//VDD = 3.0V
	//		$ GPCS VDD*12/32;//VDD = 3.2V
	//		$ GPCS VDD*14/40;//VDD = 3.42857142857143V
	//		$ GPCS VDD*11/32;//VDD = 3.49090909090909V
	//		$ GPCS VDD*8/24;//VDD = 3.6V
			$ GPCS VDD*10/32;//VDD = 3.84V
	//		$ GPCS VDD*7/24;//VDD = 4.11428571428571V
		break;
		case 4:
	//		$ GPCS VDD*16/40;//VDD = 3.0V
	//		$ GPCS VDD*12/32;//VDD = 3.2V
	//		$ GPCS VDD*14/40;//VDD = 3.42857142857143V
	//		$ GPCS VDD*11/32;//VDD = 3.49090909090909V
	//		$ GPCS VDD*8/24;//VDD = 3.6V
	//		$ GPCS VDD*10/32;//VDD = 3.84V
			$ GPCS VDD*7/24;//VDD = 4.11428571428571V
		break;
	}
}


void	GPC_Init_charge(void)
{
	$ GPCC Enable,BANDGAP,P_R;
	switch(VDD_Set)
	{
		case 0:
	//		$ GPCS VDD*14/32;//VDD = 2.74285714285714V
	//		$ GPCS VDD*17/40;//VDD = 2.82352941176471V
	//		$ GPCS VDD*10/24;//VDD = 2.88V
	//		$ GPCS VDD*17/40;//VDD = 2.8V
	//		$ GPCS VDD*16/40;//VDD = 3.0V
			$ GPCS VDD*12/32;//VDD = 3.2V
	//		$ GPCS VDD*14/40;//VDD = 3.42857142857143V
		break;

		case 1:
	//		$ GPCS VDD*16/40;//VDD = 3.0V
	//		$ GPCS VDD*12/32;//VDD = 3.2V
	//		$ GPCS VDD*14/40;//VDD = 3.42857142857143V
			$ GPCS VDD*11/32;//VDD = 3.49090909090909V
	//		$ GPCS VDD*8/24;//VDD = 3.6V
	//		$ GPCS VDD*10/32;//VDD = 3.84V
	//		$ GPCS VDD*7/24;//VDD = 4.11428571428571V
		break;
		case 2:
	//		$ GPCS VDD*16/40;//VDD = 3.0V
	//		$ GPCS VDD*12/32;//VDD = 3.2V
	//		$ GPCS VDD*14/40;//VDD = 3.42857142857143V
	//		$ GPCS VDD*11/32;//VDD = 3.49090909090909V
	//		$ GPCS VDD*8/24;//VDD = 3.6V
			$ GPCS VDD*10/32;//VDD = 3.84V
	//		$ GPCS VDD*7/24;//VDD = 4.11428571428571V
		break;
		case 3:
	//		$ GPCS VDD*16/40;//VDD = 3.0V
	//		$ GPCS VDD*12/32;//VDD = 3.2V
	//		$ GPCS VDD*14/40;//VDD = 3.42857142857143V
	//		$ GPCS VDD*11/32;//VDD = 3.49090909090909V
	//		$ GPCS VDD*8/24;//VDD = 3.6V
	//		$ GPCS VDD*10/32;//VDD = 3.84V
			$ GPCS VDD*7/24;//VDD = 4.11428571428571V
		break;
		case 4:
	//		$ GPCS VDD*16/40;//VDD = 3.0V
	//		$ GPCS VDD*12/32;//VDD = 3.2V
	//		$ GPCS VDD*14/40;//VDD = 3.42857142857143V
	//		$ GPCS VDD*11/32;//VDD = 3.49090909090909V
	//		$ GPCS VDD*8/24;//VDD = 3.6V
	//		$ GPCS VDD*10/32;//VDD = 3.84V
	//		$ GPCS VDD*7/24;//VDD = 4.11428571428571V
			$ GPCS VDD*9/32;//VDD = 4.26666666666667V
	//		$ GPCS VDD*11/40;//VDD = 4.36363636363636V
		break;
	}
}

void	Measure_GPC_boot(void)
{
	LED_icnt_timer = 0;
	while(LED_icnt_timer < 5000)
	{
		if(VDD_set == 4)
		{
			GPC_Init();
			if(GPC_out)
			{
				VDD_count = 0;			//4.1+
			}
			else
			{
				if(VDD_count > 1000)
				{
					VDD_set = 3;
					VDD_count = 0;
				}
			}
		}
		else if(VDD_set == 3)
		{
			GPC_Init();
			if(GPC_out)
			{
				VDD_count = 0;		//3.84+
			}
			else
			{
				if(VDD_count > 1000)
				{
					VDD_set = 2;
					VDD_count = 0;
				}
			}
		}
		else if(VDD_set == 2)
		{
			GPC_Init();
			if(GPC_out)
			{
				VDD_count = 0;			//3.6+
			}
			else
			{
				if(VDD_count > 1000)
				{
					VDD_set = 1;
					VDD_count = 0;
				}
			}
		}
		else if(VDD_set == 1)
		{
			GPC_Init();
			if(GPC_out)
			{
				VDD_count = 0;			//3.3+
			}
			else
			{
				if(VDD_count > 1000)
				{
					VDD_set = 0;
					VDD_count = 0;		//3+
				}
			}
		}
		else if(VDD_set == 0)
		{
			GPC_Init();
			if(GPC_out)
			{
				VDD_count = 0;			//3+
			}
			else
			{
				VDD_count = 0;			//3-
			}
		}
	}
	boot_mark = 1;
}