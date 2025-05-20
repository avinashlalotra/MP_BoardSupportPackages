# MP Board Support Packages

This repository contains the Board Support Package (BSP) for a RISC-V-based embedded system. It includes essential components such as drivers, utilities, and example applications to help developers build and test their embedded projects.

## Directory Structure
## Directory Structure

```plaintext
MP_BoardSupportPackages/
├── boot/                  # Bootloader and startup code
│   └── startup.S          # Assembly code for system initialization
├── examples/              # Example applications
│   ├── led_blink.c        # Example for LED blinking
│   ├── uart_h.c           # Example for UART communication
│   ├── utils.c            # Utility functions for matrix operations
│   └── utils.h            # Header file for utility functions
├── include/               # Header files for drivers and utilities
│   ├── led.h              # LED driver interface
│   ├── systolic.h         # Systolic array accelerator interface
│   ├── timer.h            # Timer utility interface
│   └── uart.h             # UART driver interface
├── linker/                # Linker scripts
│   └── linker.ld          # Linker script for memory layout
├── src_user/              # User application source code
│   └── main.c             # Main application entry point
├── src_bsp/              # BSP source code
│   └── led.c             # Led control Logic
|   └── systolic.c        # Systolic Hardware helpers
|   └── timer.c           # timer functions
|   └── uart.c            # Uart communication function ( no interrupts )
├── LICENSE               # License information (GNU GPL v3)
├── Makefile              # Build system for the project
└── .gitignore            # Git ignore rules
```

## Features

- LED Driver : Control LEDs using memory-mapped I/O.
- UART Driver : Send  data over UART.
- Systolic Array Accelerator : Perform matrix operations using hardware acceleration.
- Timer Utility : Delay functions for timing operations.
- Examples :  Demonstrations of LED blinking, UART communication, and matrix operations.

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

2. Build the project:
```bash
   make file=<filename>
```
3. Generate HEX and disassembly files:
```bash
   make elf2hex
   make elf2dissasm
```

4. Clean the build:
```bash  
   make clean
```
## Running Examples

To run an example, set the file variable to the desired example file (without the .c extension). For example:
make file=led_blink

# Memory Layout

The memory layout is defined in the linker script (linker/linker.ld). The RAM is configured with a size of 32 KB, and sections such as .text, .rodata, .data, and .bss are mapped accordingly.

# License

This project is licensed under the GNU General Public License v3.0. See the LICENSE file for details.

# Contributing

Contributions are welcome! Please fork the repository and submit a pull request with your changes.

# Contact

For questions or support, please contact the repository maintainer.