MEMORY {
    RAM (xrw) : ORIGIN = 0x00000000, LENGTH = 32K
}

SECTIONS {
    /* Code (text section) */
    .text :
    {
        . = ALIGN(4);
        *(.text*)
        . = ALIGN(4);
        _etext = .;
    } >RAM

    /* Read-only data section */
    .rodata : AT(_etext)
    {
        . = ALIGN(4);
        *(.rodata*)
        . = ALIGN(4);
        _erodata = .;
    } >RAM
    /* Initialized data section */
    .data : AT(_etext)
    {
        . = ALIGN(4);
        _sdata = .;
        *(.data*)
        . = ALIGN(4);
        _edata = .;
    } >RAM

    /* Uninitialized data section */
    .bss :
    {
        . = ALIGN(4);
        _sbss = .;
        *(.bss*)
        . = ALIGN(4);
        _ebss = .;
    } >RAM

    /* Stack at the top of RAM */
    _stack_top = ORIGIN(RAM) + LENGTH(RAM);
}