#define READ_PIN A0
#define LED_PIN 12

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int SensorValue = analogRead(READ_PIN); // 0-1023
  digitalWrite(LED_PIN, HIGH);
  delay(SensorValue+50);
  digitalWrite(LED_PIN, LOW);
  delay(SensorValue+50);
}
