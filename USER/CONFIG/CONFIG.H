#ifndef CONFIG_H_
#define CONFIG_H_

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

bit charge_full		: pa.7;
bit led1			: pb.7;
bit led2			: pb.4;
bit led3 			: pb.5;
bit led4			: pb.6;
bit key1			: pb.2;
bit key2			: pb.0;
bit key3			: PB.1;
bit key4			: pb.3;
bit charge			: pa.4;
bit rf_data			: pa.0;

#define LED_ON	1
#define	LED_OFF	0

extern byte send_icnt;
extern byte Power_down_flag;
extern word LED_icnt_timer;

void IO_init(void);
void close_hardware();

#endif