#include <IRremote.h>

#define ir_rec_pin 7
IRrecv irrecv(ir_rec_pin);
decode_results results;

#define LED_PIN_RED 8
#define LED_PIN_YEL 9
#define LED_PIN_GRE 10

const int nLEDs = 3;
bool LED_stat[nLEDs];

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  
  irrecv.enableIRIn();
  irrecv.blink13(true);
  
  pinMode(LED_PIN_RED, OUTPUT);
  pinMode(LED_PIN_YEL, OUTPUT);
  pinMode(LED_PIN_GRE, OUTPUT);

  for (int i = 0; i < nLEDs; ++i) LED_stat[i] = false;
}

void TurnOn() {
  digitalWrite(LED_PIN_RED, HIGH);
  digitalWrite(LED_PIN_YEL, HIGH);
  digitalWrite(LED_PIN_GRE, HIGH);
  
  for (int i = 0; i < nLEDs; ++i) LED_stat[i] = true;
}

void TurnOff() {
  digitalWrite(LED_PIN_RED, LOW);
  digitalWrite(LED_PIN_YEL, LOW);
  digitalWrite(LED_PIN_GRE, LOW);
  
  for (int i = 0; i < nLEDs; ++i) LED_stat[i] = false;
}

void UpdateLEDs() {
  if (LED_stat[0] == true) digitalWrite(LED_PIN_RED, HIGH);
  else digitalWrite(LED_PIN_RED, LOW);
  
  if (LED_stat[1] == true) digitalWrite(LED_PIN_YEL, HIGH);
  else digitalWrite(LED_PIN_YEL, LOW);
  
  if (LED_stat[2] == true) digitalWrite(LED_PIN_GRE, HIGH);
  else digitalWrite(LED_PIN_GRE, LOW);
}

void loop() {
  // put your main code here, to run repeatedly:

  // Both LG and Onkyo remotes are NEC protocol
  // On LG, ON is 20DF10EF
  // On Onkyo, ON is 4B36D32C
  
  if (irrecv.decode(&results)) {
    Serial.println(results.value, HEX);
    /*
    switch (results.decode_type){
        case NEC: Serial.println("NEC"); break ;
            case SONY: Serial.println("SONY"); break ;
            case RC5: Serial.println("RC5"); break ;
            case RC6: Serial.println("RC6"); break ;
            case DISH: Serial.println("DISH"); break ;
            case SHARP: Serial.println("SHARP"); break ;
            case JVC: Serial.println("JVC"); break ;
            case SANYO: Serial.println("SANYO"); break ;
            case MITSUBISHI: Serial.println("MITSUBISHI"); break ;
            case SAMSUNG: Serial.println("SAMSUNG"); break ;
            case LG: Serial.println("LG"); break ;
            case WHYNTER: Serial.println("WHYNTER"); break ;
            case AIWA_RC_T501: Serial.println("AIWA_RC_T501"); break ;
            case PANASONIC: Serial.println("PANASONIC"); break ;
            case DENON: Serial.println("DENON"); break ;
          default:
            case UNKNOWN: Serial.println("UNKNOWN"); break ;
          }
          */
    // The on button
    if (results.value == 0x20DF10EF) {
      for (int i = 0; i < nLEDs; ++i) LED_stat[i] = true;
    }

    // RIGHT = 20DF609F
    else if (results.value == 0x20DF609F) {
      LED_stat[2] = !LED_stat[2];
      
    // LEFT = 20DFE01F
    } else if (results.value == 0x20DFE01F) {
      LED_stat[0] = !LED_stat[0];
    }
    
    // LEFT = 20DFE01F
    else if (results.value == 0x20DF22DD) {
      LED_stat[1] = !LED_stat[1];
    }

    // CENTER = 20DF02FD, invert
    else if (results.value == 0x20DF02FD || results.value == 0x20DF827D) {
      for (int i = 0; i < nLEDs; ++i) LED_stat[i] = !LED_stat[i];
    }
    
    UpdateLEDs();
    
    irrecv.resume();
  }
}
