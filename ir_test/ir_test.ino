#include <IRremote.h>
#define IRPIN 10

IRrecv irrecv(IRPIN);
decode_results signals;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  irrecv.enableIRIn();
}

void loop() {
  // put your main code here, to run repeatedly:
  if (irrecv.decode(&signals)) {
    Serial.println(signals.value, HEX);
    irrecv.resume();
  }
}
