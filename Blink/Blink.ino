
void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  toggleLed();
  delay(100);
}

void toggleLed() {
  digitalWrite(LED_BUILTIN, !digitalRead(LED_BUILTIN));
}
