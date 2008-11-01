#ifndef PMU_H
#define PMU_H

#include "openiboot.h"

typedef struct PMURegisterData {
	int bus;
	uint8_t reg;
	uint8_t data;
} PMURegisterData;

typedef enum PowerSupplyType {
	PowerSupplyTypeError,
	PowerSupplyTypeBattery,
	PowerSupplyTypeFirewire,
	PowerSupplyTypeUSBHost,
	PowerSupplyTypeUSBBrick500mA,
	PowerSupplyTypeUSBBrick1000mA
} PowerSupplyType;

#define PMU_IBOOTSTATE 0xF
#define PMU_IBOOTDEBUG 0x0
#define PMU_IBOOTSTAGE 0x1
#define PMU_IBOOTERRORCOUNT 0x2
#define PMU_IBOOTERRORSTAGE 0x3

int pmu_setup();
int pmu_get_gpmem_reg(int bus, int reg, uint8_t* out);
int pmu_get_reg(int bus, int reg);
int pmu_write_reg(int bus, int reg, int data, int verify);
int pmu_write_regs(const PMURegisterData* regs, int num);
int pmu_get_battery_voltage();
PowerSupplyType pmu_get_power_supply();


#endif
