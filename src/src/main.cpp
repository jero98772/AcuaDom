#pragma once
#include "lights.h"
#include "relays.h"
#include "sensors.h"
#include "tools.h"
#include <WiFiManager.h>  
#include "constants_defines.h"

long  mytime=0L;
const char* SSID = "ACUADOOM";

void setup() {
  
  Serial.begin(115200);
  WiFiManager wifiManager;
  wifiManager.autoConnect(SSID);
}

void loop() {
  String input = Serial.readString();
  input.trim();
  if(input[2]==':'){
      long mytime=tools::timetototalSeconds(input);
      Serial.print(mytime);
  	}
  delay(99);
  mytime++;
  // put your main code here, to run repeatedly:
}