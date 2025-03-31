#include "uart.h"
#include <stdint.h>
#define UART_DIV ((volatile uint32_t *) 0x02000004)
#define UART_DATA ((volatile uint32_t *) 0x02000008)
#define MAPPEDADDR 0x02000000
void delay_(int x){
    for (int delay = 0; delay < x; delay++) {}
}
void count(int x,uint32_t *ptr){
    for(int i=1; i<x; i++){
        *ptr = i;
        delay_(10);
    }
}

void delay( int );
void uart_set_div(unsigned int div)
{
  volatile int delay;

  *UART_DIV = div;

  /* Need to delay a little */
  for (delay = 0; delay < 200; delay++) {}
}

void uart_putchar(char ch){
    *UART_DATA = ch ;
}


int main(){

    uart_set_div(868); // 115200 baud
    uart_putchar('A');
    count(10,(uint32_t *)MAPPEDADDR);
    uart_putchar('B');
    uart_putchar('C');
    
    return 0;
}

