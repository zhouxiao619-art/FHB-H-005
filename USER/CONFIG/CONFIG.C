#include "CONFIG.H"
#include 	"../KEYSCAN/KEYSCAN.H"
#include 	"../SLEEP/SLEEP.H"
#include 	"../gpc/gpc.H"

/*============================================================================
							 PFS122-sop16
						VDD-----------------GND
	CHARGE_FULL			PA7-----------------PA0			rf_data		
						PA6-----------------PA4			charge
						PA5-----------------PA3			
		led1			PB7-----------------PB3			key4
		led2			PB4-----------------PB1			key3
		led3			PB5-----------------PB0			key2
	    led4			PB6-----------------PB2			key1
==============================================================================*/

byte Power_down_flag;
word LED_icnt_timer;
byte send_icnt;

void IO_init(void)
{
	PAPH 	= 0b1000_0000;
	PAC 	= 0b0000_0001;
	PA 		= 0b1000_0000;
	PADIER 	= 0b1001_0001;

	PBPH 	= 0b0000_1111;
	PBC 	= 0b1111_0000;
	PB 		= 0b0000_1111;
	PBDIER 	= 0b1111_1111;
}

void close_hardware()
{
	led1 = 0;
	led2 = 0;
	led3 = 0;
	led4 = 0;
	long_click = 0;
	vdd_set = 4;
}	