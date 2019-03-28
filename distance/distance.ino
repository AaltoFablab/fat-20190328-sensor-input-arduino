#define SENSOR_PIN A0

void setup() {
  Serial.begin(9600);
}

void loop() {
  int reading = analogRead(SENSOR_PIN);
  Serial.println(reading);
  delay(100);
}
