// This code implements button debounce to ensure reliable button presses.
const int BUTTON_PIN = 6;
const int LED_PIN = 12;
const int INITIAL_INTERVAL = 2048;
const int MIN_INTERVAL = 16;
const unsigned long DEBOUNCE_DELAY = 50;

int interval = INITIAL_INTERVAL;
int prevButtonReading = HIGH;
int prevButtonState = HIGH;
int buttonState = HIGH;
unsigned long lastMillis = 0;
unsigned long lastDebounceMillis = 0;

void setup() {
  pinMode(LED_PIN, OUTPUT);
  pinMode(BUTTON_PIN, INPUT_PULLUP);
}

void loop() {
  int reading = digitalRead(BUTTON_PIN);
  unsigned long currentMillis = millis();

  if (reading != prevButtonReading) {
    lastDebounceMillis = currentMillis; // Change detected, reset the debounce timer
  }

  if ((currentMillis - lastDebounceMillis) >= DEBOUNCE_DELAY) {
    if (reading != buttonState) { // State has stabilized
      prevButtonState = buttonState;
      buttonState = reading;
      if (prevButtonState == HIGH && buttonState == LOW) {
        handleButtonPress();
      }
    }
  }
  prevButtonReading= reading;

  if (currentMillis - lastMillis >= interval) {
    toggleLed();
    lastMillis = currentMillis;
  }
}

void toggleLed() {
  digitalWrite(LED_PIN, !digitalRead(LED_PIN));
}

void handleButtonPress() {
  interval /= 2;
  if (interval < MIN_INTERVAL) {
    interval = INITIAL_INTERVAL;
  }
}
