#include <stdint.h>
int main(){
    volatile uint32_t a[2][2] = {{1,2},{3,4}};
    volatile uint32_t b[2][2] = {{5,6},{7,8}};
    volatile uint32_t c[2][2] = {{0,0},{0,0}};
    
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k < 2; k++) {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }

    return 0;
}