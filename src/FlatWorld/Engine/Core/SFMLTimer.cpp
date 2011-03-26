#include "SFMLTimer.h"

#include <SFML/Window.hpp>

CSFMLTimer::CSFMLTimer(void)
{
}

CSFMLTimer::CSFMLTimer(const float& timeCount, sf::Window& GameWindow)
{
	Init(timeCount, GameWindow);
}

CSFMLTimer::~CSFMLTimer(void)
{
}

void CSFMLTimer::Init(const float& timeCount, sf::Window& GameWindow)
{
	this->GameWindow = &GameWindow;
	if (timeCount != 0.f)
	{
		intervalDt = 1.f/timeCount;
	}
	else
	{
		intervalDt = 1.f/60.f;
	}
	dt = 0.f;
	totalDt = 0.f;
	timeScale = 1.f;
}

void CSFMLTimer::Update()
{
	dt = GameWindow->GetFrameTime();
}

bool CSFMLTimer::Ready()
{
	Update();
	if (totalDt < intervalDt)
	{
		totalDt += dt;
		return false;
	}
	else
	{
		totalDt = 0.f;
		return true;
	}
}