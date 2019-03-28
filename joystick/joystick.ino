#define XAXIS A0
#define YAXIS A1
#define BUTTON 0

void setup() {
  Serial.begin(9600);
  pinMode(BUTTON, INPUT);
}

void loop() {
  int xReading = analogRead(XAXIS);
  int yReading = analogRead(YAXIS);
  bool buttonReading = digitalRead(BUTTON);

  Serial.print(xReading);
  Serial.print(",");
  Serial.print(yReading);
  Serial.print(",");
  Serial.println(buttonReading);
}
