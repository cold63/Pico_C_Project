#ifndef SR04_SONIC_H
#define SR04_SONIC_H


#include "pico/stdlib.h"
#include "hardware/gpio.h"
#include "hardware/timer.h"



#ifdef __cplusplus
class sr04_sonic {
    private:
    int trigPin;
    int echoPin;
    uint64_t getPulse(int trigPin,int echoPin); 

    public:
    sr04_sonic(int trigPin,int echoPin);
    uint64_t getCM();
    uint64_t getINCH();

};
 
#endif

#endif