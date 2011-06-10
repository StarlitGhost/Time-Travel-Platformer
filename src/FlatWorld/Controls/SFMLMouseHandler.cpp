#include "SFMLMouseHandler.h"

#include <iostream>

#include <SFML/Window/Event.hpp>

#include "Graphics/GameDisplay.h"
#include "Maths/Vector2f.h"

using namespace FlatWorld;

bool SFMLMouseHandler::buttons[sf::Mouse::ButtonCount] = {false};
bool SFMLMouseHandler::oldButtons[sf::Mouse::ButtonCount] = {false};
Vector2f SFMLMouseHandler::position = Vector2f();
Vector2f SFMLMouseHandler::oldPosition = Vector2f();
bool SFMLMouseHandler::invertX = false;
bool SFMLMouseHandler::invertY = false;
int SFMLMouseHandler::wheelDelta = 0;

void SFMLMouseHandler::Invert(bool X, bool Y)
{
	invertX = X;
	invertY = Y;
}

void SFMLMouseHandler::Update()
{
	for (int i = 0; i < sf::Mouse::ButtonCount; ++i)
	{
		oldButtons[i] = buttons[i];
	}
	oldPosition = position;
	wheelDelta = 0;
}

void SFMLMouseHandler::HandleEvents(const sf::Event& Event)
{
	if (Event.Type == sf::Event::MouseMoved)
	{
		position = Vector2f(
			invertX ? (float)(GameDisplay::Width() - Event.MouseMove.X) : (float)Event.MouseMove.X,
			invertY ? (float)(GameDisplay::Height() - Event.MouseMove.Y) : (float)Event.MouseMove.Y
			);
	}
	else if (Event.Type == sf::Event::MouseButtonPressed)
	{
		buttons[Event.MouseButton.Button] = true;
	}
	else if (Event.Type == sf::Event::MouseButtonReleased)
	{
		buttons[Event.MouseButton.Button] = false;
	}
	else
	{
		wheelDelta = Event.MouseWheel.Delta;
		std::cout << wheelDelta << std::endl;
	}
}

bool SFMLMouseHandler::Held(const sf::Mouse::Button& button)
{
	return buttons[button];
}

bool SFMLMouseHandler::Pressed(const sf::Mouse::Button& button)
{
	return buttons[button] && !oldButtons[button];
}

bool SFMLMouseHandler::Released(const sf::Mouse::Button& button)
{
	return !buttons[button] && oldButtons[button];
}

bool SFMLMouseHandler::WheelUp()
{
	return wheelDelta > 0;
}

bool SFMLMouseHandler::WheelDown()
{
	return wheelDelta < 0;
}

int SFMLMouseHandler::WheelDelta()
{
	return wheelDelta;
}

Vector2f SFMLMouseHandler::Position()
{
	return position;
}

Vector2f SFMLMouseHandler::PositionChange()
{
	return position - oldPosition;
}

bool SFMLMouseHandler::Moved()
{
	return position != oldPosition;
}