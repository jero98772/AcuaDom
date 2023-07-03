#include "relays.h"
#include "constants_defines.h"

relays::relays(){
    pinMode(relayLight,OUTPUT);
    pinMode(relayThermostat,OUTPUT);
    pinMode(relayFilters,OUTPUT);
}
relays::~relays(){}
void relays::turnOnlights(){
    digitalWrite(relayLight,HIGH);
}
void relays::turnOfflights(){
    digitalWrite(relayLight,LOW);
}
void relays::turnOnFilters(){
    digitalWrite(relayFilters,HIGH);
}
void relays::turnOffFilters(){
    digitalWrite(relayFilters,LOW);
}
void relays::turnOnThermostat(){
    digitalWrite(relayThermostat,HIGH);
}
void relays::turnOffThermostat(){
    digitalWrite(relayThermostat,LOW);
}
void relays::turnOnAll(){
    digitalWrite(relayLight,HIGH);
    digitalWrite(relayThermostat,HIGH);
    digitalWrite(relayFilters,HIGH);
}
void relays::turnOffAll(){
    digitalWrite(relayFilters,LOW);
    digitalWrite(relayThermostat,LOW);
    digitalWrite(relayFilters,LOW);
}