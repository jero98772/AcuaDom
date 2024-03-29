#ifndef _LIGHTS_H
#define _LIGHTS_H
#include <Adafruit_NeoPixel.h>
#include "constants_defines.h"

class lights{
private:
    void changeColor(uint32_t color, Adafruit_NeoPixel strip);
    void changeColorAlter2colors(uint32_t color1,uint32_t color2, Adafruit_NeoPixel strip,int step);
public:
    lights();
    ~lights();
    void morningLight();
    void noonLight();
    void afternoonLight();
    void nightLight();
    void complateCicle(String time);
    void turnOff();
    void turnOn();
    //turn on at, turn off at set methots
};

#endif