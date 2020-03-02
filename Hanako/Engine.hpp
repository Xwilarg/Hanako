#pragma once

# include <Stepper.h>

namespace Hanako
{
  class Engine final
  {
  public:
    Engine(int lPin1, int lPin2, int lPin3, int lPin4, int rPin1, int rPin2, int rPin3, int rPin4) noexcept;
    void GoForward() const noexcept;
  
  private:
    const int _steps;
    Stepper _leftWheel, _rightWheel;
  };
}
