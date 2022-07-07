/**
 * Copyright (c) 2020 Raspberry Pi (Trading) Ltd.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include <stdio.h>
#include "pico/stdlib.h"

int main() {
    // Enable UART 
    stdio_init_all();

    gpio_init(25);
    gpio_set_dir(25, GPIO_OUT);    
    
    while (true) {
        gpio_put(25, 1);
        sleep_ms(1500);
        gpio_put(25, 0);
        printf("blink test\n");
        sleep_ms(1500);
    }

    return 0;
}
