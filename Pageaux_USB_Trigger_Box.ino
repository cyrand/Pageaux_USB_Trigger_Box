/* Send TTL triggers to equipment on reception of input on serial port
From host computer:
Send 'L' to turn output low
Send 'H' to turn output high
Date: 2025-05-01
Author: André Cyr
*/

int trgPin = 6;
int ledPin = 7;

void setup() {
  pinMode(trgPin,OUTPUT);
  pinMode(ledPin,OUTPUT);
  digitalWrite(trgPin,0);
  digitalWrite(ledPin,0);
  Serial.begin(1000000);
}

void loop() {
  while(Serial.available()){
    int incomingByte = Serial.read();
    switch(incomingByte){
      case 'L':
         digitalWrite(trgPin,0);
         digitalWrite(ledPin,0);
         break;
      case 'H':
        digitalWrite(trgPin,1);
        digitalWrite(ledPin,1);
        break;
      default:
        break;
    }
  }
}
