#include <lights.h>
#include <Adafruit_NeoPixel.h>
#include "constants_defines.h"

Adafruit_NeoPixel strip1 = Adafruit_NeoPixel(NUMPIXELS1, PINSTRIP1, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel strip2 = Adafruit_NeoPixel(NUMPIXELS2, PINSTRIP2, NEO_GRB + NEO_KHZ800);

lights::lights(){
    strip1.begin();
    strip2.begin();
    strip1.setBrightness(50);
    strip2.setBrightness(50);
    strip1.show(); // Initialize all pixels to 'off'
    strip2.show();
}
lights::~lights(){}
void lights::morningLigth(){
    strip1.setBrightness(50);
    strip2.setBrightness(50);
    changeColorAlter2colors(strip2.Color(255,255,255),strip2.Color(0,0,255),strip2,3);
    changeColor(strip1.Color(255,255,255), strip1);    
}
void lights::noonLigth(){
    strip1.setBrightness(100);
    strip2.setBrightness(100);
    changeColorAlter2colors(strip2.Color(255,255,255),strip2.Color(0,0,255),strip2,0);
    changeColor(strip1.Color(255,255,255), strip1);  
}
void lights::afternoonLigth(){
    strip1.setBrightness(75);
    strip2.setBrightness(75);
    changeColorAlter2colors(strip2.Color(255,255,255),strip2.Color (255, 212, 92),strip2,3);
    changeColor(strip1.Color(255,255,255), strip1);  
}
void lights::nightLigth(){
    strip1.setBrightness(25);
    strip2.setBrightness(25);
    changeColorAlter2colors(strip2.Color(255,255,255),strip2.Color (0,0,255),strip2,2);
    changeColor(strip1.Color(255,255,255), strip1); 
}
void lights::complateCicle(){}
void lights::changeColor(uint32_t color, Adafruit_NeoPixel strip){
  for(int i=0; i<strip.numPixels(); i++) { 
    strip.setPixelColor(i, color);         
    strip.show();                          
  }
}
void lights::changeColorAlter2colors(uint32_t color1,uint32_t color2, Adafruit_NeoPixel strip,int step){
  for(int i=0; i<strip.numPixels(); i++) {
    if(i%step!=0) strip.setPixelColor(i, color1);
    else strip.setPixelColor(i, color2);
    strip.show();
  }
}

