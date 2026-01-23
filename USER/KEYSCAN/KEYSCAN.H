#ifndef KEYSCAN_H_
#define	KEYSCAN_H_

#define SINGLE_KEY_TIME     100       // SINGLE_KEY_TIME*10us = 10MS

extern byte Long_click;
extern byte Long_click_bak;
extern word key_time;
void KEY_SCAN();
extern word key_time2;
extern word key_time3;
extern word key_time4;

#endif