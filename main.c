#include <stdint.h>
#include "led.h"
#include "systolic.h"
#include "uart.h"
#include "utils.h"


int main() {
    led_write(0x4); // idle
    uint16_t weights[4][4] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}};
    uint16_t inputs[4][4] = {{16, 15, 14, 13}, {12, 11, 10, 9}, {8, 7, 6, 5}, {4, 3, 2, 1}};
    uint16_t bias = 1;

    led_write(0x1); // started
    uint32_t res_accel = single_neuron_classification_model_with_accelerator_4_4(weights, bias, inputs);
    led_write(0x2); // done
    led_write(0x4); // idle
    led_write(0x1); // started
    uint32_t res_soft = single_neuron_classification_model_without_accelerator_4_4(weights, bias, inputs);
    led_write(0x2); // done
    led_write(0x4); // idle



    // led_write(0x4); // idle
    // uint16_t wiights[2][2] = {{1, 2}, {3, 4}};
    // uint16_t bias = 1;
    // uint16_t inputs[2][2] = {{5, 6}, {7, 8}};
    // led_write(0x1); // started
    // uint32_t res_accel = single_neuron_classification_model_with_accelerator(wiights, bias, inputs);
    // led_write(0x2); // done
    // led_write(0x4); // idle
    // led_write(0x1); // started
    // uint32_t res_soft = single_neuron_classification_model_without_accelerator(wiights, bias, inputs);
    // led_write(0x2); // done
    // led_write(0x4); // idle
    return 0;
}