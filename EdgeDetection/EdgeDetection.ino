// This code uses edge detection to halve the blink interval of an LED each time a button is pressed.

const int BUTTON_PIN = 6;
const int LED_PIN = 12;
const int INITIAL_INTERVAL = 2048;
const int MIN_INTERVAL = 16;
const int READ_DELAY = 50;

int interval = INITIAL_INTERVAL;
bool lastButtonState = HIGH;
int timePassed = 0;

void setup() {
  pinMode(LED_PIN, OUTPUT);
  pinMode(BUTTON_PIN, INPUT_PULLUP);
}

void loop() {
  bool currentButtonState = digitalRead(BUTTON_PIN);

  if (lastButtonState == HIGH && currentButtonState == LOW) {
    interval /= 2;
    if (interval < MIN_INTERVAL) {
      interval = INITIAL_INTERVAL;
    }
  }

  lastButtonState = currentButtonState;

  if (timePassed >= interval) {
    toggleLed();
    timePassed = 0;
  }

  timePassed += READ_DELAY;
  delay(READ_DELAY);
}

void toggleLed() {
  digitalWrite(LED_PIN, !digitalRead(LED_PIN));
}
