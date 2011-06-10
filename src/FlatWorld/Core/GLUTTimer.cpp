#include "GLUTTimer.h"

#define FREEGLUT_STATIC
#include <GL/freeglut.h>

using namespace FlatWorld;

CGLUTTimer::CGLUTTimer(void)
{
}

CGLUTTimer::CGLUTTimer(const float& timeCount)
{
	Init(timeCount);
}

void CGLUTTimer::Init(const float& timeCount)
{
	dt = 1;
	f_dt = 0.001f;
	timeLast = glutGet(GLUT_ELAPSED_TIME);
	timeIncrement = (int)((1.f / timeCount) * 1000.f);
	timeLastReady = timeLast;
	timeNext = timeLast + timeIncrement;

	timeScale = 1.f;
}

CGLUTTimer::~CGLUTTimer(void)
{
}

void CGLUTTimer::Update()
{
	timeNow = glutGet(GLUT_ELAPSED_TIME);

	CalcDT(timeLast, timeNow);

	timeLast = timeNow;
}

bool CGLUTTimer::Ready()
{
	Update();
	if (timeNow >= timeNext)
	{
		CalcDT(timeLastReady, timeNow);
		timeLastReady = timeNow;
		timeNext = timeNow + timeIncrement;
		return true;
	}
	return false;
}

float CGLUTTimer::DT() const
{
	return f_dt * timeScale;
}

void CGLUTTimer::CalcDT(const int& startTime, const int& endTime)
{
	dt = endTime - startTime;
	f_dt = (float)dt * 0.001f;
}
