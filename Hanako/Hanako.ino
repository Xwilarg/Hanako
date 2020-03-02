#include <Stepper.h>

constexpr int steps = 2048;
constexpr int readyLed = 12;
Stepper motorLeft = Stepper(steps, 47, 51, 49, 53);
Stepper motorRight = Stepper(steps, 46, 50, 48, 52);

void setup() {
  pinMode(readyLed, OUTPUT);
  motorLeft.setSpeed(15); // rpm
  motorRight.setSpeed(15); // rpm
  Serial.begin(9600);
  digitalWrite(readyLed, HIGH);
}

void loop() {
  for (int i = 0; i < steps; i++)
  {
    motorLeft.step(1);
    motorRight.step(1);
  }
}
