#include <Stepper.h>
#include "Buzzer.hpp"

Hanako::Buzzer* buzzer;

constexpr int steps = 2048;
Stepper motorLeft = Stepper(steps, 47, 51, 49, 53);
Stepper motorRight = Stepper(steps, 46, 50, 48, 52);

void setup() {
  motorLeft.setSpeed(15); // rpm
  motorRight.setSpeed(15); // rpm
  int tones[5] = { 500, 750, 500, 750, 1000 };
  buzzer = new Hanako::Buzzer(2, tones, 5);
  Serial.begin(9600);
}

void loop() {
  motorLeft.step(1);
  motorRight.step(1);
  buzzer->Update();
}
