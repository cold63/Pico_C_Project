#include "sonic.h"
#include <stdio.h>

uint64_t timeout =26100;

sr04_sonic::sr04_sonic(int trig_Pin,int echo_Pin)
{
    this->trigPin = trig_Pin;
    this->echoPin = echo_Pin;

    gpio_init(this->trigPin);
    gpio_init(this->echoPin);
    gpio_set_dir(this->trigPin,GPIO_OUT);
    gpio_set_dir(this->echoPin,GPIO_IN);
}


uint64_t sr04_sonic::getPulse(int trigPin,int echoPin)
{
    gpio_put(trigPin,1);
    sleep_us(10);
    gpio_put(trigPin,0);

    uint64_t width = 0;

    while(gpio_get(echoPin) == 0) tight_loop_contents();
    absolute_time_t startTime = get_absolute_time();
    while(gpio_get(echoPin) == 1){
        width++;
        sleep_us(1);
       if(width > timeout) return 0;
    }
    absolute_time_t endTime = get_absolute_time();
    return absolute_time_diff_us(startTime,endTime);
}

uint64_t sr04_sonic::getCM()
{
    uint64_t pulseLength = getPulse(this->trigPin,this->echoPin);
    return pulseLength /29.1/2; //or multiply by 0.0343
}

uint64_t sr04_sonic::getINCH()
{
    uint64_t pulseLength = getPulse(this->trigPin,this->echoPin);
    return pulseLength / 74.f / 2.f;
}
