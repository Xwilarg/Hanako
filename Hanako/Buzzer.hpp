#pragma once

# include "AComponent.hpp"

namespace Hanako
{
  class Buzzer final : public AComponent
  {
  public:
    Buzzer(int pin, int* tones, int tonesSize) noexcept;
    void Update() noexcept;

  private:
    int _index;
    unsigned long _timerRef;
    const int _delayBetweenTones;
    int* _tones;
    int _tonesSize;
  };
}
