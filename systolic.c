#include "systolic.h"

void write_register(uint32_t offset, uint32_t value) {
    volatile uint32_t *reg = (volatile uint32_t *)(BASE_ADDRESS + offset);
    *reg = value;
}
uint32_t read_register(uint32_t offset) {
    volatile uint32_t *reg = (volatile uint32_t *)(BASE_ADDRESS + offset);
    return *reg;
}


void send_matrix(uint32_t matrixA[2][2],uint32_t matrixB[2][2]){
    write_register(NORTH_0, matrixB[1][0]);
    write_register(NORTH_1,0);
    write_register(WEST_0, matrixA[0][1]);
    write_register(WEST_1, 0);

    write_register(CONTROL_REG, SHIFT_WORD);
    write_register(CONTROL_REG, NO_OP_WORD);

    write_register(NORTH_0, matrixB[0][0]);
    write_register(NORTH_1, matrixB[1][1]);
    write_register(WEST_0,  matrixA[0][0]);
    write_register(WEST_1, matrixA[1][1]);
    
    write_register(CONTROL_REG, SHIFT_WORD);
    write_register(CONTROL_REG, NO_OP_WORD);

    write_register(NORTH_0, 0);
    write_register(NORTH_1,matrixB[0][1]);
    write_register(WEST_0, 0);
    write_register(WEST_1, matrixA[1][0]);

    write_register(CONTROL_REG, SHIFT_WORD);
    write_register(CONTROL_REG, NO_OP_WORD);

    write_register(NORTH_0, 0);
    write_register(NORTH_1,0);
    write_register(WEST_0, 0);
    write_register(WEST_1, 0);
    write_register(CONTROL_REG, SHIFT_WORD);
    write_register(CONTROL_REG, NO_OP_WORD);
}
void recv_matrix(uint32_t result[2][2]){
    result[0][0] = read_register(RESULT_00);
    result[0][1] = read_register(RESULT_01);
    result[1][0] = read_register(RESULT_10);
    result[1][1] = read_register(RESULT_11);
}
