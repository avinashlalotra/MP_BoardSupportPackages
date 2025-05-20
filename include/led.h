#ifndef LED_H
#define LED_H
#include <stdint.h>
#define LED_ADDR 0x02000000

void led_write(uint32_t) ;

#endif
