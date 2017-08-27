// Simple extension of fade to fade three LEDs instead of one

#define LED_1 9
#define LED_2 10
#define LED_3 11
#define MAX_BRIGHTNESS 255
int fadeAmount = 20;
int brightness = 0;    // how bright the LED is

// the setup routine runs once when you press reset:
void setup() {
  
  //pinMode(SENSORPIN, INPUT);
  // declare pin 9 to be an output:
  pinMode(LED_1, OUTPUT);
  pinMode(LED_2, OUTPUT);
  pinMode(LED_3, OUTPUT);
}

// the loop routine runs over and over again forever:
void loop() {

  brightness += fadeAmount;
  
  if (brightness > MAX_BRIGHTNESS-abs(fadeAmount) || brightness <= 0) {
    fadeAmount *= -1;
  }

  // set the brightness of pin 9:
  analogWrite(LED_1, brightness);
  analogWrite(LED_2, int((MAX_BRIGHTNESS-brightness)/2.0));
  analogWrite(LED_3, MAX_BRIGHTNESS-brightness);
  
  // wait for 30 milliseconds to see the dimming effect
  delay(100);
}
