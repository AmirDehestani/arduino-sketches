// This code toggle an LED on and off every 1000 milliseconds.

const int LED_PIN = 12;
const int INTERVAL = 1000;

void setup() {
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  toggleLed();
  delay(INTERVAL);
}

void toggleLed() {
  digitalWrite(LED_PIN, !digitalRead(LED_PIN));
}
