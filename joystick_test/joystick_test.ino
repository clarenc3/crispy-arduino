#define SW 2
#define YDIR 1
#define XDIR 0

#define LEFT_LED 9
#define BOTTOM_LED 11
#define RIGHT_LED 5
#define TOP_LED 6

#define X_CALIB 511
#define Y_CALIB 503

void setup() {
  // put your setup code here, to run once:
  pinMode(SW, INPUT);
  
  pinMode(LEFT_LED, OUTPUT);
  pinMode(BOTTOM_LED, OUTPUT);
  pinMode(RIGHT_LED, OUTPUT);
  pinMode(TOP_LED, OUTPUT);
  
  digitalWrite(SW, HIGH);
  Serial.begin(9600);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  int switchval = digitalRead(SW);
  /*
  Serial.print("Switch: ");
  Serial.print(switchval);
  Serial.print("\n");
  */

  int xval = analogRead(XDIR);
  /*
  Serial.print("XDIR: ");
  Serial.print(xval);
  Serial.print("\n");
  */

  int yval = analogRead(YDIR);
  /*
  Serial.print("YDIR: ");
  Serial.print(yval);
  Serial.print("\n\n");
  */

  // Now control some LEDs based on this
  if (switchval != 1) {
    analogWrite(LEFT_LED, 255);
    analogWrite(RIGHT_LED, 255);
    analogWrite(TOP_LED, 255);
    analogWrite(BOTTOM_LED, 255);
    return;
  }

  // Do the x direction
  if (xval > X_CALIB+2) {
    analogWrite(RIGHT_LED, float(xval-X_CALIB-2)/1024. * 255 );
    analogWrite(LEFT_LED, 0);
  } else if (xval < X_CALIB-2) {
    analogWrite(LEFT_LED, float(X_CALIB-2-xval)/1024. * 255);
    analogWrite(RIGHT_LED, 0);
  } else {
    digitalWrite(LEFT_LED, LOW);
    digitalWrite(RIGHT_LED, LOW);
  }

  if (yval > Y_CALIB+2) {
    analogWrite(TOP_LED, float(yval-Y_CALIB-2)/1024. * 255);
    analogWrite(BOTTOM_LED, 0);
  } else if (yval < Y_CALIB-2) {
    analogWrite(TOP_LED, 0);
    analogWrite(BOTTOM_LED, float(Y_CALIB-2-yval)/1024. * 255);
  } else {
    digitalWrite(TOP_LED, LOW);
    digitalWrite(BOTTOM_LED, LOW);
  }
  
  delay(50);
}
