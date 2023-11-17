/**
 * Copyright (c) 2020 Raspberry Pi (Trading) Ltd.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "pico/stdlib.h"

bool state;

//

unsigned long time;
const int delayTime = 50;

void interrup_func(uint gpio,uint32_t events){
    
    if(to_ms_since_boot(get_absolute_time()) - time > delayTime){
        time = to_ms_since_boot(get_absolute_time());

        state = !state;
        gpio_put(PICO_DEFAULT_LED_PIN,state);
    }
    
}

int main() {
    
    stdio_init_all();

    gpio_init(PICO_DEFAULT_LED_PIN);
    gpio_set_dir(PICO_DEFAULT_LED_PIN, GPIO_OUT);
 
    state = true;
    gpio_put(PICO_DEFAULT_LED_PIN,state);

    //interrupt
    gpio_init(6);
    gpio_pull_up(6);

    gpio_set_irq_enabled_with_callback(6, GPIO_IRQ_EDGE_FALL , true, &interrup_func);

    while (true) {

    }

    return 0;
}
