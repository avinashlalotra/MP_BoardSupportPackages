#ifndef SYSTOLIC_ARRAY_H
#define SYSTOLIC_ARRAY_H

#include <stdint.h>

#define SYSTOLIC_BASE 0x03000000 // Base address of the SYSTOLIC module
#define REG_WRITE(addr, val) (*(volatile uint32_t *)(addr) = (val))
#define REG_READ(addr) (*(volatile uint32_t *)(addr))

// Instruction encodings
#define RESET           0x00010000
#define WRITE_WEST_0    0x00020000
#define WRITE_WEST_1    0x00030000
#define WRITE_NORTH_0   0x00040000
#define WRITE_NORTH_1   0x00050000
#define STATUS          0x00060000
#define READ_R00        0x00070000
#define READ_R01        0x00080000
#define READ_R10        0x00090000
#define READ_R11        0x000A0000
#define START           0x000B0000

void systolic_reset(void);

void systolic_write_inputs(uint16_t a00, uint16_t a01, uint16_t a10, uint16_t a11) ;

void systolic_start(void);

void systolic_read_results(uint32_t *r00, uint32_t *r01, uint32_t *r10, uint32_t *r11);

uint8_t systolic_status(void);

#endif // SYSTOLIC_ARRAY_H
