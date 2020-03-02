namespace Hanako
{
  class AComponent
  {
  public:
    AComponent(int pin) noexcept
      : _pin(pin)
    { }
    virtual ~AComponent() noexcept = default;

  protected:
    int _pin;
  };
}
