#include "utils.h"
#include "systolic.h"
void delay(int duration){
    for(int i=0;i<duration;i++){}
}

void with_accelerator_4_4_optimized(uint16_t A[4][4],uint16_t B[4][4] , uint32_t C[4][4]){

    // A - A11 A12 A21 A22
    // B - B11 B12 B21 B22
    // C - C11 C12 C21 C22
    // temp var to store rrsults
    uint32_t tmp[2][2];
    // C11 = A11 * B11 + A12 * B21
    // C12 = A11 * B12 + A12 * B22
    // C21 = A21 * B11 + A22 * B21
    // C22 = A21 * B12 + A22 * B22

    ////////////////////////////////////////////////////////////////////////
    // Lets start with C11
    // C11 = A11 * B11 + A12 * B21
    systolic_reset();
    systolic_write_inputs(A[0][1],     0,  B[1][0], 0);
    systolic_start();
    systolic_write_inputs(A[0][0], A[1][1], B[0][0], B[1][1]);
    systolic_start();
    systolic_write_inputs(       0, A[1][0],      0, B[0][1]);
    systolic_start();
    systolic_write_inputs(0, 0, 0,0);
    systolic_start();
    systolic_read_results(&C[0][0], &C[0][1], &C[1][0], &C[1][1]);

    systolic_reset();
    systolic_write_inputs(A[0][3],       0, B[3][0], 0);
    systolic_start();
    systolic_write_inputs(A[0][2], A[1][3], B[2][0], B[3][1]);
    systolic_start();
    systolic_write_inputs(      0, A[1][2],       0, B[2][1]);
    systolic_start();
    systolic_write_inputs(0, 0, 0,0);
    systolic_start();
    systolic_read_results(&tmp[0][0], &tmp[0][1], &tmp[1][0], &tmp[1][1]);

    C[0][0] += tmp[0][0];
    C[0][1] += tmp[0][1];
    C[1][0] += tmp[1][0];
    C[1][1] += tmp[1][1];

    ////////////////////////////

    ////////////////////////////////////////////////////////////////////////
    //  C12
     // C12 = A11 * B12 + A12 * B22
    systolic_reset();
    systolic_write_inputs(A[0][1],   0    , B[1][2], 0);
    systolic_start();
    systolic_write_inputs(A[0][0], A[1][1], B[0][2], B[1][3]);
    systolic_start();
    systolic_write_inputs(      0, A[1][0], 0,        B[0][3]);
    systolic_start();
    systolic_write_inputs(0, 0, 0,0);
    systolic_start();
    systolic_read_results(&C[0][2], &C[0][3], &C[1][2], &C[1][3]);

    systolic_reset();
    systolic_write_inputs(A[0][3],      0,  B[3][2], 0);
    systolic_start();
    systolic_write_inputs(A[0][2], A[1][3], B[2][2], B[3][3]);
    systolic_start();
    systolic_write_inputs(      0, A[1][2],       0, B[2][3]);
    systolic_start();
    systolic_write_inputs(0, 0, 0,0);
    systolic_start();
    systolic_read_results(&tmp[0][0], &tmp[0][1], &tmp[1][0], &tmp[1][1]);

    C[0][2] += tmp[0][0];
    C[0][3] += tmp[0][1];
    C[1][2] += tmp[1][0];
    C[1][3] += tmp[1][1];

    ////////////////////////////

      ////////////////////////////////////////////////////////////////////////
    //  C21
    // C21 = A21 * B11 + A22 * B21
     systolic_reset();
     systolic_write_inputs(A[2][1],   0    , B[1][0], 0);
     systolic_start();
     systolic_write_inputs(A[2][0], A[3][1], B[0][0], B[1][1]);
     systolic_start();
     systolic_write_inputs(      0, A[3][0], 0,        B[0][1]);
     systolic_start();
     systolic_write_inputs(0, 0, 0,0);
     systolic_start();
     systolic_read_results(&C[2][0], &C[2][1], &C[3][0], &C[3][1]);
 
     systolic_reset();
     systolic_write_inputs(A[2][3],      0,  B[3][0], 0);
     systolic_start();
     systolic_write_inputs(A[2][2], A[3][3], B[2][0], B[3][1]);
     systolic_start();
     systolic_write_inputs(      0, A[3][2],       0, B[2][1]);
     systolic_start();
     systolic_write_inputs(0, 0, 0,0);
     systolic_start();
     systolic_read_results(&tmp[0][0], &tmp[0][1], &tmp[1][0], &tmp[1][1]);
 
     C[2][0] += tmp[0][0];
     C[2][1] += tmp[0][1];
     C[3][0] += tmp[1][0];
     C[3][1] += tmp[1][1];
 
     ////////////////////////////

    ////////////////////////////////////////////////////////////////////////
    //  C22
    // C22 = A21 * B12 + A22 * B22
    systolic_reset();
    systolic_write_inputs(A[2][1],   0    , B[1][2], 0);
    systolic_start();
    systolic_write_inputs(A[2][0], A[3][1], B[0][2], B[1][3]);
    systolic_start();
    systolic_write_inputs(      0, A[3][0], 0,        B[0][3]);
    systolic_start();
    systolic_write_inputs(0, 0, 0,0);
    systolic_start();
    systolic_read_results(&C[2][2], &C[2][3], &C[3][2], &C[3][3]);

    systolic_reset();
    systolic_write_inputs(A[2][3],      0,  B[3][2], 0);
    systolic_start();
    systolic_write_inputs(A[2][2], A[3][3], B[2][2], B[3][3]);
    systolic_start();
    systolic_write_inputs(      0, A[3][2],       0, B[2][3]);
    systolic_start();
    systolic_write_inputs(0, 0, 0,0);
    systolic_start();
    systolic_read_results(&tmp[0][0], &tmp[0][1], &tmp[1][0], &tmp[1][1]);

    C[2][2] += tmp[0][0];
    C[2][3] += tmp[0][1];
    C[3][2] += tmp[1][0];
    C[3][3] += tmp[1][1];

    ////////////////////////////
}


void without_accerlator_2_2 (uint16_t a[2][2], uint16_t b[2][2], uint32_t c[2][2]){
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            c[i][j] = 0;
            for (int k = 0; k < 2; k++) {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }
   
}
void with_accelerator_2_2 (uint16_t a[2][2], uint16_t b[2][2], uint32_t c[2][2]){
    systolic_reset();
    systolic_write_inputs(a[0][1], 0, b[1][0], 0);
    systolic_start();
    systolic_write_inputs(a[0][0], a[1][1], b[0][0], b[1][1]);
    systolic_start();
    systolic_write_inputs(0, a[1][0], 0, b[0][1]);
    systolic_start();
    systolic_write_inputs(0, 0, 0,0);
    systolic_start();
    systolic_read_results(&c[0][0], &c[0][1], &c[1][0], &c[1][1]);
}

void without_accelerator_4_4(uint16_t a[4][4], uint16_t b[4][4], uint32_t c[4][4]) {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            c[i][j] = 0;
            for (int k = 0; k < 4; k++) {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }
}

uint16_t fixed_sigmoid(int32_t x) {
    int32_t abs_x = (x < 0) ? -x : x;
    return (uint16_t)((x * 1024) / (1024 + abs_x)); // Scale to 0-1 range
}

uint16_t single_neuron_classification_model_without_accelerator(uint16_t weights [2][2], uint16_t bias, uint16_t inputs[2][2]){
        uint32_t output[2][2] = {0};
        uint32_t sum = 0;

        // Perform matrix multiplication of weights and inputs
        without_accerlator_2_2(weights, inputs, output);

        // Add bias to the result
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                output[i][j] += bias;
            }
        }

        // Apply ReLU activation
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                output[i][j] = (output[i][j] > 0) ? output[i][j] : 0;
            }
        }

        // Sum all elements for sigmoid input
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                sum += output[i][j];
            }
        }

        // Apply fixed-point sigmoid activation
        uint16_t sigmoid_output = fixed_sigmoid(sum);

        return (sigmoid_output >= 512) ? 1 : 0; // 512 = 0.5 in Q10 format
    
}

uint16_t single_neuron_classification_model_with_accelerator(uint16_t weights [2][2], uint16_t bias, uint16_t inputs[2][2]){
        uint32_t output[2][2] = {0};
        uint32_t sum = 0;

        // Perform matrix multiplication of weights and inputs
        with_accelerator_2_2(weights, inputs, output);

        // Add bias to the result
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                output[i][j] += bias;
            }
        }

        // Apply ReLU activation
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                output[i][j] = (output[i][j] > 0) ? output[i][j] : 0;
            }
        }

        // Sum all elements for sigmoid input
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                sum += output[i][j];
            }
        }

       // Apply fixed-point sigmoid activation
    uint16_t sigmoid_output = fixed_sigmoid(sum);

    return (sigmoid_output >= 512) ? 1 : 0; // 512 = 0.5 in Q10 format
}

uint16_t single_neuron_classification_model_without_accelerator_4_4(uint16_t weights[4][4], uint16_t bias, uint16_t inputs[4][4]) {
    uint32_t output[4][4] = {0};
    uint32_t sum = 0;

    // Perform matrix multiplication of weights and inputs
    without_accelerator_4_4(weights, inputs, output);

    // Add bias to the result
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            output[i][j] += bias;
        }
    }

    // Apply ReLU activation
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            output[i][j] = (output[i][j] > 0) ? output[i][j] : 0;
        }
    }

    // Sum all elements for sigmoid input
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            sum += output[i][j];
        }
    }

    // Apply fixed-point sigmoid activation
    uint16_t sigmoid_output = fixed_sigmoid(sum);

    return (sigmoid_output >= 512) ? 1 : 0; // 512 = 0.5 in Q10 format
}

uint16_t single_neuron_classification_model_with_accelerator_4_4(uint16_t weights[4][4], uint16_t bias, uint16_t inputs[4][4]) {
    uint32_t output[4][4] = {0};
    uint32_t sum = 0;

    // Perform matrix multiplication of weights and inputs
    with_accelerator_4_4_optimized(weights, inputs, output);

    // Add bias to the result
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            output[i][j] += bias;
        }
    }

    // Apply ReLU activation
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            output[i][j] = (output[i][j] > 0) ? output[i][j] : 0;
        }
    }

    // Sum all elements for sigmoid input
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            sum += output[i][j];
        }
    }

    // Apply fixed-point sigmoid activation
    uint16_t sigmoid_output = fixed_sigmoid(sum);

    return (sigmoid_output >= 512) ? 1 : 0; // 512 = 0.5 in Q10 format
}
