#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"

#define Shift_GPIO  2
//#define Button_IO      (Shift_GPIO + 7)

int bits[8] ={
    0x01,
    0x02,
    0x04,
    0x08,
    0x10,
    0x20,
    0x40,
    0x80
};

uint8_t OnButton;

void gpio_callback(uint gpio,uint32_t events){

    if(events == 0x4)
    {
        if(OnButton){
            OnButton = 0;
            gpio_put(PICO_DEFAULT_LED_PIN, 1);
        }
        else{
            OnButton = 1;
            gpio_put(PICO_DEFAULT_LED_PIN, 0);
        }
    }
}

int main(){

    stdio_init_all();
    
    for(int x = Shift_GPIO; x < Shift_GPIO + 8; x++){
        gpio_init(x);
        gpio_set_dir(x,GPIO_OUT);
        gpio_set_outover(x,GPIO_OVERRIDE_INVERT);
    }
    gpio_set_irq_enabled_with_callback(10,   GPIO_IRQ_EDGE_FALL, true, &gpio_callback);

    gpio_init(PICO_DEFAULT_LED_PIN);
    gpio_set_dir(PICO_DEFAULT_LED_PIN, GPIO_OUT); 

    uint8_t y;

    while(true){
        
        if(OnButton) {
            uint32_t mask = bits[y] << Shift_GPIO;

            gpio_set_mask(mask);
            sleep_ms(1000);
            gpio_clr_mask(mask);

            y++;
            if(y >= 8){
                y=0;
            }
        }


    }

    return 0;
}