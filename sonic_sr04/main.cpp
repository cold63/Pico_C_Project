#include <stdio.h>
#include "pico/stdlib.h"
#include "pico-sonic/sonic.h"

int main(){
    // Enable UART 
    stdio_init_all();

    sr04_sonic MySonic = sr04_sonic(2,3);

    while(true){
        printf("%llu cm \n",MySonic.getCM());
        sleep_ms(100);
    }

    return 0;
}