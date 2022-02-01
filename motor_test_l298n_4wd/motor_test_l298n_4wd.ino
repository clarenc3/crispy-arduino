#define in1 2
#define in2 3
#define in3 4
#define in4 5

#define speed1 9
#define speed2 10

#define maxspeed 120
#define minspeed 40

bool in1_stat = false;
bool in2_stat = false;
bool in3_stat = false;
bool in4_stat = false;

int speed_both = 100;

void UpdateEngine() {
  if (in1_stat) digitalWrite(in1, HIGH);
  else digitalWrite(in1, LOW);

  if (in2_stat) digitalWrite(in2, HIGH);
  else digitalWrite(in2, LOW);
  
  if (in3_stat) digitalWrite(in3, HIGH);
  else digitalWrite(in3, LOW);

  if (in4_stat) digitalWrite(in4, HIGH);
  else digitalWrite(in4, LOW);
}


void Accelerate(int until = maxspeed) { 
  for (;speed_both <= until; speed_both += 20) {
    analogWrite(speed1, speed_both);
    analogWrite(speed2, speed_both);
    delay(200);
  }
}

void Decelerate(int until = minspeed) {
  for (;speed_both >= until; speed_both -= 20) {
    analogWrite(speed1, speed_both);
    analogWrite(speed2, speed_both);
    delay(200);
  }
}

void HardLeft(int ms = 1000) {

  in1_stat = true;
  in2_stat = false;
  in3_stat = false;
  in4_stat = true;

  UpdateEngine();

  delay(ms);
}


void HardRight(int ms = 1000) {

  in1_stat = false;
  in2_stat = true;
  in3_stat = true;
  in4_stat = false;

  UpdateEngine();

  delay(ms);
}


void Forward(int ms = 1000) {

  if (speed_both > minspeed) Decelerate();

  in1_stat = false;
  in2_stat = true;
  in3_stat = false;
  in4_stat = true;
  
  UpdateEngine();

  delay(ms);
}

void Backward(int ms = 1000) {

  if (speed_both > minspeed) Decelerate();

  in1_stat = true;
  in2_stat = false;
  in3_stat = true;
  in4_stat = false;

  UpdateEngine();
  
  delay(ms);
}


void setup() {
  // put your setup code here, to run once:
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);

  pinMode(speed1, OUTPUT);
  pinMode(speed2, OUTPUT);

  // Set the starting speed
  analogWrite(speed1, speed_both);
  analogWrite(speed2, speed_both);
}

void loop() {
  /*
  // Turn on forwards
  Forward(500);
  // Accelerate
  Accelerate();

  // Go backwards
  Backward(500);
  Accelerate();
*/
  HardLeft(1000);
  HardRight(1000);

}
