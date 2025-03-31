.global _start
.section .text
_start:
    lui t0, 0x20000      # Load device base address (0x20000000) into t0
    li t3, 40   # Delay loop count
    sw t3, 0(t0)         # Initially store delay count to device
    li t4, 2    # Counter limit
    li t5, 0             # Initialize counter to 0

count:
    beq t4,t5, halt     # Branch to halt when counter reaches limit
    nop
    nop
    nop
    sw  t5, 0(t0)         # Store current counter value to device
    nop
    nop
    nop
    addi t5, t5, 1       # Increment counter
    j delay              # Jump to delay routine

halt:
    j halt               # Infinite loop to halt the program

delay:
    li t1, 0             # Initialize delay counter
delay_loop:
    beq t3, t1, delay_done  # Check if delay is complete
    addi t1, t1, 1       # Increment delay counter
    j delay_loop         # Continue delay loop
delay_done:     
    j count              # Return to counter loop