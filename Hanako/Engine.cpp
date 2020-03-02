#include "Engine.hpp"

namespace Hanako
{
  Engine::Engine(int lPin1, int lPin2, int lPin3, int lPin4, int rPin1, int rPin2, int rPin3, int rPin4) noexcept
    : _steps(2048), _leftWheel(_steps, lPin1, lPin3, lPin2, lPin4), _rightWheel(_steps, rPin1, rPin3, rPin2, rPin4)
  {
    _leftWheel.setSpeed(15);
    _rightWheel.setSpeed(15);
  }

  void Engine::GoForward() const noexcept
  {
    _leftWheel.step(1);
    _rightWheel.step(1);
  }
}
