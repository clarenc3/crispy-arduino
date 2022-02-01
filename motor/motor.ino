#include <Stepper.h>

#define STEPS 2048
#define STEP 1000

Stepper stepper(STEPS, 8, 10, 9, 11);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  stepper.setSpeed(15);
}

void loop() {
  Serial.println("Going forward");
  stepper.step(STEP);
  // put your main code here, to run repeatedly:
  delay(500);
  
  Serial.println("Going backward");
  stepper.step(-STEP);
  delay(500);
}
