
#ifndef UART_H
#define UART_H
#include <stdint.h>
#define UART_DIV ((volatile uint32_t *) 0x02000004)
#define UART_DATA ((volatile uint32_t *) 0x02000008)
void uart_set_div(unsigned int div);
void uart_putchar(char ch);
void putstr(const char *str);

#endif