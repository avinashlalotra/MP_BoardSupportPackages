#include <stdint.h>
#include "led.h"
#define SYSTOLIC_BASE 0x03000000 // Base address of the SYSTOLIC module

#define REG_WRITE(addr, val) (*(volatile uint32_t *)(addr) = (val))
#define REG_READ(addr) (*(volatile uint32_t *)(addr))

// Instruction encodings
#define RESET       0x00010000
#define WRITE_WEST_0   0x00020000
#define WRITE_WEST_1   0x00030000
#define WRITE_NORTH_0   0x00040000
#define WRITE_NORTH_1   0x00050000
#define STATUS      0x00060000
#define READ_R00    0x00070000
#define READ_R01    0x00080000
#define READ_R10    0x00090000
#define READ_R11    0x000A0000
#define START       0x000B0000

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

// uint8_t systolic_status() {
//     return (uint8_t)(REG_READ(SYSTOLIC_BASE | STATUS) & 0x1);
// }

// void systolic_read_results(uint32_t *r00, uint32_t *r01, uint32_t *r10, uint32_t *r11) {
//     *r00 = (uint32_t)REG_READ(SYSTOLIC_BASE | READ_R00);
//     *r01 = (uint32_t)REG_READ(SYSTOLIC_BASE | READ_R01);
//     *r10 = (uint32_t)REG_READ(SYSTOLIC_BASE | READ_R10);
//     *r11 = (uint32_t)REG_READ(SYSTOLIC_BASE | READ_R11);
// }

int main() {
    uint32_t r00, r01, r10, r11;
    // uint32_t matrixA[2][2] = {{1, 2},
    //                           {3, 4}};
    // uint32_t matrixB[2][2] = {{5, 6},
    //                           {7, 8}};
    
    systolic_reset();
    systolic_write_inputs(2, 0, 7, 0);
    systolic_start();
    
    systolic_write_inputs(1, 4, 5, 8);
    systolic_start();

    systolic_write_inputs(0, 3, 0, 6);
    systolic_start();

    systolic_write_inputs(0, 0, 0, 0);
    systolic_start();

    // while (!systolic_status()); // Wait for computation to complete
    REG_WRITE(SYSTOLIC_BASE, READ_R00);
    r00 = REG_READ(SYSTOLIC_BASE);
    REG_WRITE(SYSTOLIC_BASE, READ_R01);
    r01 = REG_READ(SYSTOLIC_BASE);
    REG_WRITE(SYSTOLIC_BASE, READ_R10);
    r10 = REG_READ(SYSTOLIC_BASE);
    REG_WRITE(SYSTOLIC_BASE, READ_R11);
    r11 = REG_READ(SYSTOLIC_BASE);
    // systolic_read_results(&r00, &r01, &r10, &r11);
    REG_WRITE(LED_ADDR, r00);
    REG_WRITE(LED_ADDR, r01);
    REG_WRITE(LED_ADDR, r10);
    REG_WRITE(LED_ADDR, r11);
    
    return 0;
}
