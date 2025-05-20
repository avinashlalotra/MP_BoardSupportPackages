#include "led.h"
#include "timer.h"


int main(){

    for (int i=0;i<16;i++){
        led_write(i);
        delay_ms(1000);
    }

}
