#ifndef UTILS_H
#define UTILS_H
#include <stdint.h>
void delay(int duration);

void with_accelerator_2_2(uint16_t a[2][2], uint16_t b[2][2], uint32_t c[2][2]);

void with_accelerator_4_4_optimized(uint16_t A[4][4],uint16_t B[4][4] , uint32_t C[4][4]);

void without_accerlator_2_2 (uint16_t a[2][2], uint16_t b[2][2], uint32_t c[2][2]);

void without_accelerator_4_4(uint16_t a[4][4], uint16_t b[4][4], uint32_t c[4][4]);

uint16_t single_neuron_classification_model_without_accelerator(uint16_t weights [2][2],uint16_t bias, uint16_t inputs[2][2]);

uint16_t single_neuron_classification_model_with_accelerator(uint16_t weights [2][2],uint16_t bias, uint16_t inputs[2][2]);

uint16_t single_neuron_classification_model_without_accelerator_4_4(uint16_t weights[4][4], uint16_t bias, uint16_t inputs[4][4]) ;
uint16_t single_neuron_classification_model_with_accelerator_4_4(uint16_t weights[4][4], uint16_t bias, uint16_t inputs[4][4]);

#endif
