#include "relays.h"
#include "constants_defines.h"

relays::relays(){
    pinMode(relayLigth,OUTPUT);
    pinMode(relayThermostat,OUTPUT);
    pinMode(relayFilters,OUTPUT);
}
relays::~relays(){}
void relays::turnOnligths(){
    digitalWrite(relayLigth,HIGH);
}
void relays::turnOffligths(){
    digitalWrite(relayLigth,LOW);
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
    digitalWrite(relayLigth,HIGH);
    digitalWrite(relayThermostat,HIGH);
    digitalWrite(relayFilters,HIGH);
}
void relays::turnOffAll(){
    digitalWrite(relayFilters,LOW);
    digitalWrite(relayThermostat,LOW);
    digitalWrite(relayFilters,LOW);
}