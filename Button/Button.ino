// This code toggle an LED on and off every 1000 milliseconds. If the button is pressed, the LED will turn off.

const int LED_PIN = 12;
const int BUTTON_PIN = 6;
const int INTERVAL = 1000;
const int READ_DELAY = 50;
int timePassed = 0;

void setup() {
  pinMode(LED_PIN, OUTPUT);
  pinMode(BUTTON_PIN, INPUT_PULLUP);
}

void loop() {
  if (digitalRead(BUTTON_PIN) == LOW) {
    digitalWrite(LED_PIN, LOW);
    timePassed = 0;
  } else {
    timePassed += READ_DELAY;
  }

  if (timePassed >= INTERVAL) {
    toggleLed();
    timePassed = 0;
  }

  delay(READ_DELAY);
}

void toggleLed() {
  digitalWrite(LED_PIN, !digitalRead(LED_PIN));
}
