#include <stdint.h>

#define DIM 2  // A 2*2 Systolic Array
#define BASE_ADDRESS 0x03000000

// Register Addresses
#define CONTROL_REG  0x00
#define STATUS_REG   0x04
#define NORTH_0      0x08
#define NORTH_1      0x0C
#define WEST_0       0x10
#define WEST_1       0x14
#define RESULT_00    0x18
#define RESULT_01    0x1C
#define RESULT_10    0x20
#define RESULT_11    0x24

// Control Words
#define RESET_WORD   0x000000FF
#define START_WORD   0x0000FF00
#define NO_OP_WORD   0x00000000
#define SHIFT_WORD   0x000F0000
#define FLOW_WORD    0x00F00000

void write_register(uint32_t offset , uint32_t value);
uint32_t read_register(uint32_t offset ) ;

void send_matrix(uint32_t matrixA[DIM][DIM], uint32_t matrixB[DIM][DIM]);
void recv_matrix(uint32_t matrixR[DIM][DIM]);





