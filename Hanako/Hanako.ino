#include <Stepper.h>

constexpr int steps = 2048;
constexpr int buzzer = 2;
Stepper motorLeft = Stepper(steps, 47, 51, 49, 53);
Stepper motorRight = Stepper(steps, 46, 50, 48, 52);
int buzzerIndex;
unsigned long buzzerTimerRef;
constexpr int buzzerTonesSize = 5;
int buzzerTones[buzzerTonesSize] = { 500, 750, 500, 750, 1000 };

void setup() {
  pinMode(buzzer, OUTPUT);
  motorLeft.setSpeed(15); // rpm
  motorRight.setSpeed(15); // rpm
  Serial.begin(9600);
  tone(buzzer, buzzerTones[0]);
  buzzerTimerRef = millis();
  buzzerIndex++;
}

void loop() {
  motorLeft.step(1);
  motorRight.step(1);
  if (buzzerIndex <= buzzerTonesSize)
  {
    if (millis() > buzzerTimerRef + 200)
    {
      if (buzzerIndex == buzzerTonesSize)
      {
        noTone(buzzer);
      }
      else
      {
        tone(buzzer, buzzerTones[buzzerIndex]);
        buzzerTimerRef = millis();
        buzzerIndex++;
      }
    }
  }
}
