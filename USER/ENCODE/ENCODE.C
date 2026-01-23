#include "ENCODE.H"
#include 	"../CONFIG/CONFIG.H"

word data;

void RF_end()
{
	RF_data = 1;
	.delay 364;
	RF_data = 0;
	.delay 5180;
}

void RF_Encode()
{
	byte data_icnt = 16;
	word data_temp;
	data_temp = data;
	do
	{
		if(data_temp & 0x8000)	//bit 1
		{
			RF_data = 1;		
			.delay 1000;
			RF_data = 0;
			.delay 360;
		}
		else					//bit0
		{
			RF_data = 1;
			.delay 360;
			RF_data = 0;
			.delay 1000;
		}
		data_temp <<= 1;
	}while(--data_icnt);
	RF_end();
}