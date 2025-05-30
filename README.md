# MP Board Support Packages

This repository contains the Board Support Package (BSP) for a RISC-V-based AI embedded system. It provides essential components such as low-level drivers, utility functions, and example applications to help developers build and test their embedded projects.

# Directory Structure
```
MP_BoardSupportPackages/
├── boot/                  # Bootloader and startup code
│   └── startup.S          # Assembly code for system initialization
├── examples/              # Example applications
│   ├── led_blink.c        # LED blinking example
│   ├── uart_h.c           # UART communication example
│   ├── utils.c            # Matrix operation utilities
│   └── utils.h            # Header for utility functions
├── include/               # Public driver and utility headers
│   ├── led.h              # LED driver interface
│   ├── systolic.h         # Systolic accelerator interface
│   ├── timer.h            # Timer utility interface
│   └── uart.h             # UART driver interface
├── lib/                   # External libraries or third-party code
│   └── ...
├── linker/                # Linker scripts
│   └── linker.ld          # Memory layout and section mappings
├── src_bsp/               # BSP source code
│   ├── led.c              # LED control logic
│   ├── systolic.c         # Systolic hardware helpers
│   ├── timer.c            # Timer functionality
│   └── uart.c             # UART (polling-based) communication
├── src_user/              # User application code
│   └── main.c             # Main application entry point
├── artifacts/             # Build artifacts (created after build)
│   ├── firmware           # Executable binary for simulators
│   ├── firmware.mem       # HEX file for memory initialization
│   ├── firmware_dissasm.log # Disassembly of firmware
│   └── log                # Firmware size and build info
├── LICENSE                # License file (GNU GPL v3)
├── Makefile               # Project build system
└── .gitignore             # Git ignore rules
```

# Features

- LED Driver: Control LEDs using memory-mapped I/O
- UART Driver: Send and receive data over UART
- Systolic Array Accelerator: Perform matrix operations using  hardware acceleration
- Timer Utility: Delay and timing functions
- Examples: LED blinking, UART communication, matrix operations


# Getting Started

## Prerequisites

- RISC-V GCC Toolchain (riscv32-unknown-elf-gcc)
- RISC-V ELF to HEX converter (riscv32-unknown-elf-elf2hex)
- RISC-V Object Dump (riscv32-unknown-elf-objdump)


## Building the Project

1. Clone the repository:
```bash
   git clone https://github.com/avinashlalotra/MP_BoardSupportPackages.git
   cd MP_BoardSupportPackages
```
2. Build the BSP:
```bash
   make src_bsp
```
3. Generate firmware:
```bash
   make FILE=main.c
   # Note: The file main.c must be present in the src_user folder.
```
   This generates the following files in the artifacts/ directory:
   - firmware               → Executable binary for RISC-V simulators
   - firmware_dissasm.log   → Disassembly of the firmware
   - firmware.mem           → Hexadecimal format for memory load
   - log                    → Build information and firmware size

4. Clean the build:
```bash
  make clean
```

# STEPS TO RUN THESE PROGRAMS ON AN FPGA BOARD

All the programs can be ported to any FPGA board . 

You should follow the following steps:
   1) Go to this repostry : Setup this Vivado project 
   2) Add the "firmware.mem" file to your project
   3) Generate the bitstream and upload it to your board
   4) Open the serial terminal and reset the SOC. 

You can see the magic.


## Running Examples

Lets write a led blinking programme

```C
#include "led.h"    //This contains routines for led device
#include "timer.h"   // This is for exact timing

int main(){
   // Lets blink the led every 1s
   uint32_t status=0; // 0 for off and 1 for on
   for (int i=0; i<10; i++){
      led_write(status);
      delay_ms(1000);// delay for 1s
      status = ~status;
   };

   led_write(0); // turn it off
   return 0;
}
```
You can visually verify the LED is blinking on FPGA.


Now let's write the first ever programme that everyone wrote at some point — "A hello World programme".
Before writing code we must know how any message prints on screen.

A display screen can be connected to a CPU via different protocols and the simplest one is UART. Connect a display device via UART and send characters via it.

For testing we can use our computer.
Connect your FPGA with the computer. The programming cable is enough for it, you don't need any extra cable.

First upload the generated bitstream to FPGA. The programme is also synthesised with it.
Open a Serial shell on your computer, select the device name and baud rate that you have selected in the programme.

Now reset the SOC via reset button. And hurray — see the magic!
It prints "Hello World".

```C
#include "uart.h"

int main(){

   // First we have to set baud rate
   uart_set_div(434); // for BAUD RATE = 115200
   // Now here's the magic
   putstr("Hello World!");

   return 0;
}
```
Now you will be thinking what is happening in uart.h and led.h. How they provide access to specific hardware on our SOC.

For that you have to go through this repository which contains all the HDL code used for the SOC.


## Memory Layout

The memory layout is defined in linker/linker.ld. RAM is configured as 32 KB. Sections such as .text, .rodata, .data, and .bss are mapped appropriately.


## License

This project is licensed under the GNU General Public License v3.0. See the LICENSE file for details.


## Contributing

Contributions are welcome! Please fork the repository and submit a pull request with your changes.


## Contact

For questions or support, please contact the repository maintainer.
