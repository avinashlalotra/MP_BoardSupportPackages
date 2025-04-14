#include "timer.h"
static inline uint64_t get_mcycle() {
    uint64_t cycle;
    asm volatile ("rdcycle %0" : "=r" (cycle));
    return cycle;
}

void delay_ms(uint32_t ms) {
    uint64_t start = get_mcycle();
    uint64_t end = start + ((uint64_t)ms * (CPU_FREQ / 1000));

    while (get_mcycle() < end);
}
