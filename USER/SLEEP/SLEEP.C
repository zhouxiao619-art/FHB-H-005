#include "SLEEP.H"
#include 	"../CONFIG/CONFIG.H"

byte Sleep_delay;
byte CLKMD_BK;
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
//=======掉电模式=========
void Power_down(void)
{
	//===User can add code=====
	//进入省电模式前动作
	//=========================

	PADIER  = 0b0001_0000;				//将PA0、PA3、PA6 设置为数字模式		//设置   唤醒IO
	PBDIER 	= 0b0000_1111;
	CLKMD_BK = CLKMD;
	//休眠前需要切换低频ILRC用来防止唤醒失败
	$ CLKMD ILRC/1,En_IHRC,En_ILRC;		//系统时钟选择，是否启用IHRC，是否启用ILRC，（En_IHRC和En_ILRC不写为停用，写为启用）
										//系统时钟可选择IHRC/4, IHRC/16, IHRC/2, IHRC/8, ILRC/16, IHRC/32, IHRC/64, ILRC/4, ILRC/1
										//选择系统时钟为ILRC/1，启用IHLC和IHRC；（注：两个RC振荡器至少有一个开启，否则会出现宕机）
	CLKMD.En_IHRC = 0;					//关闭高频IHRC，若上条语句没使用低频时钟，此句必须去掉

	while(1)
	{
		nop;
		stopsys;						//进入断电模式
		if((!KEY1)||charge||(!key2)||(!key3)||(!key4))break;
	}

	$ CLKMD ILRC/1,EN_IHRC,EN_ILRC;		//打开高频使能，准备切换回系统时钟
	nop;

	PADIER 	= 0b1001_0001;
	PBDIER 	= 0b1111_1111;			// 设置数字模式
	CLKMD = CLKMD_BK;						//恢复休眠前的时钟
	Sleep_delay = 200;
}





































