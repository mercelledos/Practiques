

// capacitive sensing includes
#include <CapacitiveSensor.h>

// capacitive sensing constant
CapacitiveSensor sensor = CapacitiveSensor(4, 2);  // 1M resistor between pins 4 & 2, pin 2 is sensor pin

void setup() {
  Serial.begin(115200);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);

  pinMode (2,INPUT);
}

void loop() {
  long measurement = sensor.capacitiveSensor(30);

  Serial.println(measurement);
  delay(100);

  if (measurement > 100) {
    digitalWrite(11, HIGH);
    delay(1000);
    digitalWrite(10, LOW);
    delay(1000);
    digitalWrite(9, LOW);
    delay(1000);

  } else {
    digitalWrite(11, LOW);
    delay(1000);
  }
}
