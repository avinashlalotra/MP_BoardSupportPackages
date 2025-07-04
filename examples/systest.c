#include "utils.h"
#include "led.h"
#include "systolic.h"

void write_to_led(volatile uint32_t matrix[2][2]) {
    volatile uint32_t *led_reg = (volatile uint32_t *)LED_ADDR;
    volatile uint32_t temp;
    delay(100);
    temp = 0xAB ;
    *led_reg = temp;
    delay(100);
    temp = matrix[0][0];
    *led_reg = temp;
    delay(100);
    temp = matrix[0][1];
    *led_reg = temp;
    delay(100);
    temp = matrix[1][0];
    *led_reg = temp;
    delay(100);
    temp = matrix[1][1];
    *led_reg = temp;
    delay(100);
}

int main(){
    // Initialize the control register

    volatile uint32_t matrixA[2][2] = {{1, 2}, {3, 4}};
    volatile uint32_t matrixB[2][2] = {{5, 6}, {7, 8}};
    volatile uint32_t result[2][2] = {{0, 0}, {0, 0}};
    write_register(CONTROL_REG, RESET_WORD);
    write_register(CONTROL_REG, NO_OP_WORD);
    send_matrix(matrixA, matrixB);
    write_register(CONTROL_REG, START_WORD | FLOW_WORD);
    write_register(CONTROL_REG, RESET_WORD);
    write_register(CONTROL_REG, NO_OP_WORD);
    send_matrix(matrixA, matrixB);
    write_register(CONTROL_REG, START_WORD | FLOW_WORD);
    // delay(1000);
    // recv_matrix(result);
    // delay(10);
    // write_register(CONTROL_REG, NO_OP_WORD);
    // write_to_led(result);

    return 0;
};