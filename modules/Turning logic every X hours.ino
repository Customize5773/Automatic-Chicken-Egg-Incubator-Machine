#define EGG_TURNING_SERVO_PIN 22
Servo eggServo;

// Timing for egg turning
unsigned long lastTurnTime = 0;
const unsigned long TURN_INTERVAL = 6UL * 60UL * 60UL * 1000UL; // Turn every 6 hours
bool turnState = false;

void setup() {
  ...
  eggServo.attach(EGG_TURNING_SERVO_PIN);
  eggServo.write(0); // Start position
  ...
}

void loop() {
  ...
  // Egg Turning Logic
  unsigned long currentMillis = millis();
  if (currentMillis - lastTurnTime > TURN_INTERVAL) {
    turnState = !turnState;
    eggServo.write(turnState ? 180 : 0); // Flip position
    lastTurnTime = currentMillis;
  }
  ...
}

/*🔄 You can adjust TURN_INTERVAL to any duration you want:
     - Every 6 hours = 6 * 60 * 60 * 1000 = 21600000 ms
     - Every 12 hours = 12 * 60 * 60 * 1000 = 43200000 ms*/
