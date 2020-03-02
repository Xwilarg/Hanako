#include <Arduino.h>
#include "Buzzer.hpp"

namespace Hanako
{
  Buzzer::Buzzer(int pin, int* tones, int tonesSize)
    : AComponent(pin), _index(1), _timerRef(millis()),
    _delayBetweenTones(200), _tones(tones), _tonesSize(tonesSize)
  {
    pinMode(_pin, OUTPUT);
    tone(_pin, tones[0]);
  }

  void Buzzer::Update()
  {
    if (_index <= _tonesSize)
    {
      if (millis() > _timerRef + _delayBetweenTones)
      {
        if (_index == _tonesSize)
        {
          noTone(_pin);
        }
        else
        {
          tone(_pin, _tones[_index]);
          _timerRef = millis();
          _index++;
        }
      }
    }
  }
}
