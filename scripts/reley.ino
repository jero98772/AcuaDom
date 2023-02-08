int pin=4;
void setup() {
  pinMode(pin,OUTPUT);
}

void loop() {
  digitalWrite(pin,HIGH);
  delay(2000);
  digitalWrite(pin,LOW);
  
  delay(2000);
}