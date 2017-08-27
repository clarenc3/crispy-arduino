// Compare LM35 to DS18B20 measured temperature for debugging
// Get DS18b20 temperature fast from device address
// LM35 sits on analog

#define REQUIRESNEW false
#define REQUIRESALARMS false
#include <OneWire.h>
#include <DallasTemperature.h>
// Pin which OneWire sits
#define ONE_WIRE_BUS 2
#define LM35_WIRE A0

// The OneWire object on our bus
OneWire oneWire(ONE_WIRE_BUS);
// The temperature class
DallasTemperature Sensors(&oneWire);
uint8_t* deviceAddress;
DeviceAddress tempAddress;

void setup() {
  // Set 3.3V on analog
  analogReference(INTERNAL);
  // Set the LM35 wire to input
  pinMode(LM35_WIRE, INPUT);
  Serial.begin(9600);
  Serial.println("Dallas Temperature IC Control Library Demo");
  // Start the sensors
  Sensors.begin();
  // Lessen number of calls by saving the address of Dallas
  // Index 0 is first thermometer
  Sensors.getAddress(tempAddress, 0);
  deviceAddress = (uint8_t*)tempAddress;
}

void loop() {
  // Check if device is connected
  // isConnected(uint8_t)
  // Get the DS temp
  Sensors.requestTemperaturesByAddress(deviceAddress);
  float tempDS = Sensors.getTempC(deviceAddress);

  // Compare to LM35 reading
  float tempLM = analogRead(LM35_WIRE);
  tempLM = tempLM/9.3090909;
  
  Serial.print("Temperature Dallas is: ");
  Serial.print(tempDS);
  Serial.print(" *C\n");
  
  Serial.print("Temperature LM35 is: ");
  Serial.print(tempLM);
  Serial.print(" *C\n");
  
  Serial.print("Difference = ");
  Serial.print(tempLM-tempDS);
  Serial.print("\n");
  
  delay(1000);
}
