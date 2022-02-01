#define IR_PIN 7
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(IR_PIN, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int irdist = analogRead(IR_PIN);
  Serial.println(irdist);
  delay(500);
}
