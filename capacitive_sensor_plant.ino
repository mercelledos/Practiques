/* Revisió 16 octubre 2023
Marc */

// capacitive sensing includes
#include <CapacitiveSensor.h>

// capacitive sensing constant
CapacitiveSensor sensor = CapacitiveSensor(4, 2);  // 1M resistor between pins 4 & 2, pin 2 is sensor pin

//podeu declarar un nom per a cada led i d'aquesta manera tenir el codi més endreçat:
const int red = 9;
const int green = 10;
const int blue = 11;

void setup() {
  Serial.begin(115200);
  pinMode(red, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(blue, OUTPUT);

  pinMode (2,INPUT);
}

void loop() {
  long measurement = sensor.capacitiveSensor(30);
  Serial.println(measurement);
  delay(10);

  if (measurement > 100 && measurement <= 600) {
    digitalWrite(red, LOW);
    digitalWrite(green, LOW);
    digitalWrite(blue, HIGH);
  
  } else if (measurement > 600 && measurement <= 10000) {
    digitalWrite(red, LOW);
    digitalWrite(green, HIGH);
    digitalWrite(blue, LOW);
    
  } else if (measurement > 10000) {
    digitalWrite(red, HIGH);
    digitalWrite(green, LOW);
    digitalWrite(blue, LOW);

  } else {
    digitalWrite(red, LOW);
    digitalWrite(green, LOW);
    digitalWrite(blue, LOW);
  }
  
}
