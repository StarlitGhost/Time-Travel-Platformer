#include "SFMLKeyboardHandler.h"

#include <SFML/Window/Event.hpp>

using namespace FlatWorld;

bool SFMLKeyboardHandler::keys[sf::Keyboard::KeyCount] = {false};
bool SFMLKeyboardHandler::oldKeys[sf::Keyboard::KeyCount] = {false};

void SFMLKeyboardHandler::Update()
{
	for (int i = 0; i < sf::Keyboard::KeyCount; ++i)
	{
		oldKeys[i] = keys[i];
	}
}

void SFMLKeyboardHandler::HandleEvents(const sf::Event& Event)
{
	keys[Event.Key.Code] = (Event.Type == sf::Event::KeyPressed);
}

bool SFMLKeyboardHandler::Held(const sf::Keyboard::Key& keyCode)
{
	return keys[keyCode];
}

bool SFMLKeyboardHandler::Pressed(const sf::Keyboard::Key& keyCode)
{
	return keys[keyCode] && !oldKeys[keyCode];
}

bool SFMLKeyboardHandler::Released(const sf::Keyboard::Key& keyCode)
{
	return !keys[keyCode] && oldKeys[keyCode];
}
