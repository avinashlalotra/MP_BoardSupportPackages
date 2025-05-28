#include "led.h"
void led_write(uint32_t value){
    volatile uint32_t *led = (volatile uint32_t *)LED_ADDR;
    *led = value ;
}