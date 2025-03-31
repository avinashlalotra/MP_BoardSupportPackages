.section .text
.global _start

_start:
    # Load values into registers
    li t0, 0x1     # Load 0x1234 into temporary register t0
    li t1, 0x5       # Load 0x5678 into temporary register t1
    li t2, 0x9       # Load 0x9ABC into temporary register t2

    # Perform some operations (optional)
    add t3, t0, t1      # Add t0 and t1, store result in t3
    xor t4, t1, t2      # XOR t1 and t2, store result in t4

    # Infinite loop to prevent program from exiting
1:  j 1b