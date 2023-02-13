#include <OneWire.h>
#include <DallasTemperature.h>
#include <SPI.h>
#include <Wire.h>
#define ONE_WIRE_BUS 2
OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);
int temp;
void setup() {
  Serial.begin(9600);
  sensors.begin();
  // Start up the library
}
 
 
void loop() {
  temp = sensors.getTempCByIndex(0);
  Serial.println(sensors.getTempCByIndex(0));
  delay(100);
}