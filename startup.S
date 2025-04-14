.section .text
.global _start

_start:
    # Load stack pointer (Set SP to top of RAM)
    la sp, _stack_top

    # Call main function
    call main

    # If main returns, enter infinite loop
1:  j 1b

