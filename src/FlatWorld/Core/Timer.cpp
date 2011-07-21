#include "Timer.h"

CTimer::CTimer(void)
{
	Init(30.f);
}

CTimer::CTimer(float timeCount)
{
	Init(timeCount);
}

void CTimer::Init(float timeCount)
{
	//****************** INITIALISATIONS **************************
	// Awesome accurate timings are available from the CPU
	if (QueryPerformanceFrequency((LARGE_INTEGER *) &perfFrequ))
	{
		perfCount = true;
		this->timeCount = (DWORD)(perfFrequ / timeCount);
		QueryPerformanceCounter((LARGE_INTEGER *) &timeLast);
		timeScale = 1.0 / perfFrequ;
	}
	else // Can't be awesomely accurate :(
	{
		timeLast = timeGetTime();//Set the initial time
		timeScale = 0.001;//millisecond time scale
		this->timeCount = 33;//number of milliseconds between frames
	}
	timeNext = timeLast + this->timeCount;//set time update interval
	//*************************************************************
}

CTimer::~CTimer(void)
{
}

void CTimer::Update()
{
	timeLast = timeNow;
	if (perfCount)
	{
		QueryPerformanceCounter((LARGE_INTEGER *) &timeNow);
	}
	else
	{
		timeNow = timeGetTime();
	}
}

bool CTimer::Ready()
{
	Update();
	if (timeNow > timeNext) {
		timeNext = timeNow + timeCount; //Reset the timer
		return true;
	}
	else
	{
		return false;
	}
}

float CTimer::DT()
{
	return (float)((timeNow - timeLast) * timeScale);
}
