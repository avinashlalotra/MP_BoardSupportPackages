#include "systolic.h"

void systolic_reset() {
    REG_WRITE(SYSTOLIC_BASE, RESET);
}

void systolic_write_inputs(uint16_t a00, uint16_t a01, uint16_t a10, uint16_t a11) {
    REG_WRITE(SYSTOLIC_BASE, WRITE_WEST_0 | a00);
    REG_WRITE(SYSTOLIC_BASE, WRITE_WEST_1 | a01);
    REG_WRITE(SYSTOLIC_BASE, WRITE_NORTH_0 | a10);
    REG_WRITE(SYSTOLIC_BASE, WRITE_NORTH_1 | a11);
}


void systolic_start() {
    REG_WRITE(SYSTOLIC_BASE, START);
}

void systolic_read_results(uint32_t *r00, uint32_t *r01, uint32_t *r10, uint32_t *r11) {
    REG_WRITE(SYSTOLIC_BASE, READ_R00);
    *r00 = REG_READ(SYSTOLIC_BASE);
    REG_WRITE(SYSTOLIC_BASE, READ_R01);
    *r01 = REG_READ(SYSTOLIC_BASE);
    REG_WRITE(SYSTOLIC_BASE, READ_R10);
    *r10 = REG_READ(SYSTOLIC_BASE);
    REG_WRITE(SYSTOLIC_BASE, READ_R11);
    *r11 = REG_READ(SYSTOLIC_BASE);
}



