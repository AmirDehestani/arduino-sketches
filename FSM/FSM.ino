// This Arduino sketch implements a finite state machine (FSM) that cycles through three states (RED, GREEN, BLUE) each time a button is pressed.
const int BUTTON_PIN = 6;
const int RED_LED_PIN = 12;
const int GREEN_LED_PIN = 11;
const int BLUE_LED_PIN = 10;

enum State {
  RED = 0,
  GREEN = 1,
  BLUE = 2
};
State currentState = RED;

const unsigned long DEBOUNCE_DELAY = 50;
unsigned long lastDebounceMillis = 0;
int prevButtonReading = HIGH;
int prevButtonState = HIGH;
int buttonState = HIGH;

void setup() {
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  pinMode(RED_LED_PIN, OUTPUT);
  pinMode(GREEN_LED_PIN, OUTPUT);
  pinMode(BLUE_LED_PIN, OUTPUT);
  digitalWrite(RED_LED_PIN, HIGH);
}

void loop() {
  int reading = digitalRead(BUTTON_PIN);

  if (reading != prevButtonReading) {
    lastDebounceMillis = millis();
  }

  if ((millis() - lastDebounceMillis) >= DEBOUNCE_DELAY) {
    if (reading != buttonState) {
      prevButtonState = buttonState;
      buttonState = reading;
      if (prevButtonState == HIGH && buttonState == LOW) {
        nextState();
      }
    }
  }

  prevButtonReading = reading;
}

void nextState() {
  currentState = static_cast<State>((currentState + 1) % 3);
  digitalWrite(RED_LED_PIN, currentState == RED ? HIGH : LOW);
  digitalWrite(GREEN_LED_PIN, currentState == GREEN ? HIGH : LOW);
  digitalWrite(BLUE_LED_PIN, currentState == BLUE ? HIGH : LOW);
}
