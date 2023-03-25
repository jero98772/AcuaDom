#include <lights.h>
#include <Adafruit_NeoPixel.h>
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
void lights::morningLigth(){}
void lights::noonLigth(){}
void lights::afternoonLigth(){}
void lights::nightLigth(){}
void lights::complateCicle(){}
void lights::changeColor(uint32_t color, int wait, auto strip){
  for(int i=0; i<strip.numPixels(); i++) { 
    strip.setPixelColor(i, color);         
    strip.show();                          
  }
}
