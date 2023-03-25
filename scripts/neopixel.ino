#include <Adafruit_NeoPixel.h>
#define PIN1 6      // Output pin for led strip
#define NUMPIXELS1 12 // Number of LED Diodes
#define SPEED 30
#define PIN2 5      // Output pin for led strip
#define NUMPIXELS2 32
long  time=0;
int ctoi(char x){
	return x - '0';
}

Adafruit_NeoPixel strip1 = Adafruit_NeoPixel(NUMPIXELS1, PIN1, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel strip2 = Adafruit_NeoPixel(NUMPIXELS2, PIN2, NEO_GRB + NEO_KHZ800);
int timetototalSeconds(String time){
  int hours = ctoi(time[0])*10+ctoi(time[1]);
  int minutes = ctoi(time[3])*10+ctoi(time[4]);
  return hours*60*60+minutes*60;
}

void setup()
{
    Serial.begin(9600); //Sets the baud for serial data transmission                               
    strip1.begin();
    strip2.begin();
    strip1.setBrightness(50);
    strip2.setBrightness(50);
    strip1.show(); // Initialize all pixels to 'off'
    strip2.show();
}

void loop(){
    //if(Serial.available() == 0) {}     //wait for data available
    String input = Serial.readString();  //read until timeout
    input.trim();
  	if(input[2]==':'){
      time=timetototalSeconds(input);
      //Serial.println(time);
  	}
  	Serial.println(time);
  	Serial.println(input);  
	colorWipe(strip1.Color(100, 0, 255), SPEED,strip1);
	colorWipe(strip2.Color(100, 255, 255), SPEED,strip2);
  	delay(1);
  	time++;
}
  
void colorWipe(uint32_t color, int wait, auto strip) {
  for(int i=0; i<strip.numPixels(); i++) { // For each pixel in strip...
    strip.setPixelColor(i, color);         //  Set pixel's color (in RAM)
    strip.show();                          //  Update strip to match
    //delay(wait);                           //  Pause for a moment
  }
}


