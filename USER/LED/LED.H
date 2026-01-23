#ifndef _LED_H_
#define _LED_H_

void Func_LED();

extern BYTE LED_icnt;
extern word flash_time;

void Led_start(byte count,word time);

#endif