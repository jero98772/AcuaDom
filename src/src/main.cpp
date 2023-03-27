#pragma once
#include "lights.h"
#include "relays.h"
#include "sensors.h"
#include "tools.h"
/*void recivemsg(){
  while (Serial.available() == 0) {
    String dat=Serial.readString();
    if(dat!=""){
      Serial.println(dat);
    }
  }*/
void setup() {
  Serial.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly:
}