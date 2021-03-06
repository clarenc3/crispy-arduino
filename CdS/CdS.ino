// Dim LEDs in proportion to a CdS light meter

#define LED_1 9
#define LED_2 10
#define LED_3 11
#define SENSORPIN A0
#define DELAY 20

// Recorded temperature
float temp = 0.0;
// Minimum temperature for LED
float MinTemp = 500;
// Maximum temperature for LED
float MaxTemp = 1024;
// Which LED is currently on but hasn't hit maximum
int DimLED = -1;
float TempWidth = (MaxTemp-MinTemp)/2.0;

// the setup routine runs once when you press reset:
void setup() {
  // Change the analog reference to max 1.1V as per https://playground.arduino.cc/Main/LM35HigherResolution
  //analogReference(INTERNAL);
  
  pinMode(SENSORPIN, INPUT);
  pinMode(LED_1, OUTPUT);
  pinMode(LED_2, OUTPUT);
  pinMode(LED_3, OUTPUT);

}

// the loop routine runs over and over again forever:
void loop() {
  temp = analogRead(SENSORPIN);
  
  DimLED = -1;
  // Cut into bits of temperature
  if (temp > MinTemp) {
    digitalWrite(LED_1, HIGH);
  } else {
    digitalWrite(LED_1, LOW);
    DimLED = 1;
  }
  
  if (temp > MinTemp+TempWidth) {
    digitalWrite(LED_2, HIGH);
  } else {
    digitalWrite(LED_2, LOW);
    if (DimLED < 0) {
      DimLED = 2;
    }
  }
  
  if (temp > MaxTemp) {
    // Put a warning blink on all LEDs
    WarnBlink(1);
  } else {
    digitalWrite(LED_3, LOW);
    if (DimLED < 0) {
      DimLED = 3;
    }
  }

  if (temp >= MinTemp - TempWidth) {
    switch(DimLED) {
      case 1: 
        analogWrite(LED_1, int(255*((temp-MinTemp)/TempWidth)));
        break;
      case 2: 
        analogWrite(LED_2, int(255*((temp-MinTemp-TempWidth)/TempWidth)));
        break;
      case 3: 
        analogWrite(LED_3, int(255*((temp-MaxTemp)/TempWidth)));
        break;
    }
  }
  
  delay(DELAY);
}

void WarnBlink(int nBlinks) {
  for (int i = 0; i < nBlinks; ++i) {
    digitalWrite(LED_1, HIGH);
    digitalWrite(LED_2, HIGH);
    digitalWrite(LED_3, HIGH);
    delay(400);
    digitalWrite(LED_1, LOW);
    digitalWrite(LED_2, LOW);
    digitalWrite(LED_3, LOW);
    delay(400);
  }
}
