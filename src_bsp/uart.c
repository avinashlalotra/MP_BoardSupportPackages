#include "uart.h"

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
void putstr(const char *str) {
  while (*str) {
      uart_putchar(*str++);
  }
}




