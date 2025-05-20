#include "uart.h"
#include "timer.h"
#include "led.h"
#include "secret.h"



int main(){
    uart_set_div(434);

// putstr("\r\n");
// putstr("  ███╗   ██╗ ██████╗ ████████╗\r\n");
// putstr("  ████╗  ██║██╔═══██╗╚══██╔══╝\r\n");
// putstr("  ██╔██╗ ██║██║   ██║   ██║   \r\n");
// putstr("  ██║╚██╗██║██║   ██║   ██║   \r\n");
// putstr("  ██║ ╚████║╚██████╔╝   ██║   \r\n");
// putstr("  ╚═╝  ╚═══╝ ╚═════╝    ╚═╝   \r\n");
// putstr("   Embedded System Console    \r\n");
// putstr("\r\n");

// putstr("Hello world!\r\n");   
// putstr("This is a test.\r\n");
// putstr("UART communication is working.\r\n");
// putstr("Goodbye!\r\n");

// love();

putstr("\r\n");
putstr("  ██╗      ██████╗ ██████╗  █████╗  \r\n");
putstr("  ██║     ██╔═══██╗██╔══██╗██╔══██╗ \r\n");
putstr("  ██║     ██║   ██║██║  ██║███████║ \r\n");
putstr("  ██║     ██║   ██║██║  ██║██╔══██║ \r\n");
putstr("  ██████╗ ╚██████╔╝██████╔╝██║  ██║ \r\n");
putstr("  ╚═════╝  ╚═════╝ ╚═════╝ ╚═╝  ╚═╝ \r\n");
putstr("\r\n");
putstr("  ██████╗ ███████╗ ██████╗██╗  ██╗ ██████╗ \r\n");
putstr("  ██╔══██╗██╔════╝██╔════╝██║  ██║██╔═══██╗\r\n");
putstr("  ██████╔╝█████╗  ██║     ███████║██║   ██║\r\n");
putstr("  ██╔══██╗██╔══╝  ██║     ██╔══██║██║   ██║\r\n");
putstr("  ██████╔╝███████╗╚██████╗██║  ██║╚██████╔╝\r\n");
putstr("  ╚═════╝ ╚══════╝ ╚═════╝╚═╝  ╚═╝ ╚═════╝ \r\n");


return 0;
}   