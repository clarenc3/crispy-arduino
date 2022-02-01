// toneAC runs on 9 & 10 on an uno https://bitbucket.org/teckel12/arduino-toneac/wiki/Home
#include "toneAC.h"

#define light A0

int numTones = 10;
int tones[] = {261, 277, 294, 311, 330, 349, 370, 392, 415, 440};

const int maxlight = 1000;
const int minlight = 500;
const int difflight = maxlight-minlight;
const int interval_light = difflight/(numTones+1);

void setup() {
  // put your setup code here, to run once
  Serial.begin(9600);
 }

void loop() {
  // Read light, roughly 400-920
  int lightread = analogRead(light)-minlight;
  
  //Serial.print("Analog:");
  //Serial.println(lightread);
  //Serial.print("\n");

  int interval = lightread/interval_light;
  //Serial.print(interval);
  //Serial.print("\n");
  //toneAC(tones[interval]);

  delay(50);
}
