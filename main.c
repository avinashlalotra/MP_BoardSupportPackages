#include <stdint.h>
#define MAPPEDADDR 0x20000000
void delay_(int x){
    for (int delay = 0; delay < x; delay++) {}
}
void count(int x,uint32_t *ptr){
    for(int i=1; i<x; i++){
        *ptr = i;
        delay_(10);
    }
}


int main() {
    uint32_t * ptr = (uint32_t *)MAPPEDADDR;
    *ptr = 0x1;
    *ptr = 0x2;
    return 0;
}