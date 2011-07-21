#include "Timer.h"

using namespace FlatWorld;

Timer::Timer(void)
{
	Init(30.f);
}

Timer::Timer(float timeCount)
{
	Init(timeCount);
}

void Timer::Init(float timeCount)
{
	//****************** INITIALISATIONS **************************
	// Awesome accurate timings are available from the CPU
	if (QueryPerformanceFrequency((LARGE_INTEGER *) &_perfFrequ))
	{
		_perfCount = true;
		_timeCount = (DWORD)(_perfFrequ / timeCount);
		QueryPerformanceCounter((LARGE_INTEGER *) &_currentTime);
		_timeScale = 1.0 / _perfFrequ;
	}
	else // Can't be awesomely accurate :(
	{
		_currentTime = timeGetTime();//Set the initial time
		_timeScale = 0.001;//millisecond time scale
		_timeCount = 33;//number of milliseconds between frames
	}
	_readyTime = _currentTime + _timeCount;//set time update interval
	//*************************************************************

	_dt = 1;
	_funScale = 1.f;
}

Timer::~Timer(void)
{
}

void Timer::Update()
{
	LONGLONG tempTime;
	if (_perfCount)
	{
		QueryPerformanceCounter((LARGE_INTEGER *) &tempTime);
	}
	else
	{
		tempTime = timeGetTime();
	}
	_dt = (tempTime - _currentTime) * (LONGLONG)_funScale;
	_currentTime += _dt;
}

bool Timer::Ready()
{
	if (_currentTime > _readyTime)
	{
		return true;
	}
	return false;
}

bool Timer::ReadyAndReinit()
{
	if (Ready()) {
		_readyTime = _currentTime + _timeCount; //Reset the timer
		return true;
	}
	return false;
}

float Timer::DT()
{
	return (float)(_dt * _timeScale);
}

void Timer::TimeScale(float timeScale)
{
	if (timeScale < 0)
	{
		timeScale *= -1.f;
	}
	_funScale = timeScale;
}
