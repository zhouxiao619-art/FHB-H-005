#ifndef GPC_H_
#define	GPC_H_
#include 	"../CONFIG/CONFIG.h"

extern word VDD_count;
void	GPC_Init(void);
void	Measure_GPC_boot(void);
extern bit boot_mark;
extern byte vdd_set;
void	GPC_Init_charge(void);

#endif