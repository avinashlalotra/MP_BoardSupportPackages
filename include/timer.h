#include <stdint.h>

#define CPU_FREQ 50000000  // Set your CPU frequency (e.g., 50 MHz)

static inline uint64_t get_mcycle() ;

void delay_ms(uint32_t ms);
