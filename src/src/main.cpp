#pragma once
#include "lights.h"
#include "relays.h"
#include "sensors.h"
#include "tools.h"
#include <WiFiManager.h>  
#include "constants_defines.h"

long  mytime=0L;
const char* SSID = "ACUADOOM";

WiFiManager wifiManager;
lights light;
sensors sensor;
relays relay;

void options(String input){
  if(input=="on"){
      relay.turnOnAll()
  }else if(input=="off"){
    relay.turnOffAll()
  }
  else if(input=="onligths"){
    relay.turnOnligths()
    light.turnOn()
  }else if(input=="offligths"){
    relay.turnOffligths()
    light.turnOff()
  }
  else if(input=="onfilters"){
    relay.turnOnFilters()
  }else if(input=="offfilters"){
    relay.turnOffFilters()
  }else if(input=="onthermostat"){
    relay.turnOnThermostat()
  }else if(input=="offthermostat"){
    relay.turnOffThermostat()
  }

}
void showData(){
  Serial.println("Humidty of the room");
  Serial.print(sensor.dhtHumidityGet());
  Serial.println("Temperature on Celcius of the room");
  Serial.print(sensor.floatdhtTemperatureGetCelcius());
  Serial.println("Water temperature");
  Serial.print(sensor.waterTemperatureGet());
  Serial.println("Water Level");
  Serial.print(sensor.waterLevelSensorGet());
  Serial.println("Turbity of Water");
  Serial.print(sensor.turbityGet());

}

void setup() {
  Serial.begin(115200);
  wifiManager.autoConnect(SSID);
  relay.turnOnAll()
  light.turnOn()
}

void loop() {
  String input = Serial.readString();
  input.trim();
  if(input[2]==':'){
      long mytime=tools::timetototalSeconds(input);
      Serial.print(mytime);
  }
  options(input)
  delay(99);
  mytime++;
  // put your main code here, to run repeatedly:
}