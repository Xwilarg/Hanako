#include "Engine.hpp"
#include "Buzzer.hpp"

Hanako::Engine* engine;
Hanako::Buzzer* buzzer;

void setup()
{
  engine = new Hanako::Engine(47, 49, 51, 53, 46, 48, 50, 52);
  int tones[5] = { 500, 750, 500, 750, 1000 };
  buzzer = new Hanako::Buzzer(2, tones, 5);
  Serial.begin(9600);
}

void loop()
{
  engine->GoForward();
  buzzer->Update();
}
