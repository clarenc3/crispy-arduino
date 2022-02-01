// toneAC runs on 9 & 10 on an uno https://bitbucket.org/teckel12/arduino-toneac/wiki/Home
#include "toneAC.h"

#define light A0

int numTones = 10;
int tones[] = {261, 277, 294, 311, 330, 349, 370, 392, 415, 440};

const int maxlight = 1000;
const int minlight = 500;
const int difflight = maxlight-minlight;
const int interval_light = difflight/(numTones+1);

#define trig 2
#define echo 3

const int maxdistance = 20;
const float interval_distance = float(maxdistance)/(numTones+1);

void setup() {
  // put your setup code here, to run once
  Serial.begin(9600);
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
 }

void loop() {
  // Read light, roughly 400-920
  //int lightread = analogRead(light)-minlight;

  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);

  double duration = pulseIn(echo, HIGH);
  double distance = (duration*0.0343)/2;

  //if (distance > maxdistance) distance = maxdistance;
  
  //int interval = distance/interval_distance;
  Serial.print("\nDistance: ");
  Serial.println(distance);
  delay(100);
  /*
  Serial.print("\nInterval:");
  Serial.println(interval);
  Serial.print("\n");
  Serial.print(interval_distance);
  */
  //toneAC(tones[interval-1]);
  //delay(20);
  
  //Serial.print("Analog:");
  //Serial.println(lightread);
  //Serial.print("\n");

//int interval = lightread/interval_light;
  //Serial.print(interval);
  //Serial.print("\n");
  //toneAC(tones[interval]);

  //delay(50);
}
