#include "Timer.h"

#include <math.h>

#include "Utilities/MathsUtilities.h"

using namespace FlatWorld;

Timer::Timer()
{
    Init(30.f);
}

Timer::Timer(float readyPerSecond)
{
    Init(readyPerSecond);
}

void Timer::Init(float readyPerSecond)
{
    _dt = 1.f / 60.f;
    _timeScale = 1.f;

    if (MathsUtilities::equal(readyPerSecond, 0.f))
        readyPerSecond = 30.f;
    _interval = 1.f / fabs(readyPerSecond);

    _clock.Reset();
}

void Timer::Update()
{
    _dt = ((float)_clock.GetElapsedTime() * 0.001f) * _timeScale;
    _clock.Reset();
}

bool Timer::Ready()
{
    if ((_clock.GetElapsedTime() * 0.001f) > _interval)
    {
        return true;
    }
    return false;
}

bool Timer::ReadyAndReinit()
{
    if (Ready())
    {
        _clock.Reset();
        return true;
    }
    return false;
}

float Timer::DT()
{
    return _dt * _timeScale;
}

void Timer::TimeScale(float timeScale)
{
    _timeScale = fabs(timeScale);
}
