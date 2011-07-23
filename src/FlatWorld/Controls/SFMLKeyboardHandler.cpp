#include "SFMLKeyboardHandler.h"

#include <SFML/Window.hpp>

using namespace FlatWorld;

bool SFMLKeyboardHandler::keys[sf::Key::Count] = {false};
bool SFMLKeyboardHandler::oldKeys[sf::Key::Count] = {false};

void SFMLKeyboardHandler::Update()
{
	for (int i = 0; i < sf::Key::Count; ++i)
	{
		oldKeys[i] = keys[i];
	}
}

void SFMLKeyboardHandler::HandleEvents(const sf::Event& Event)
{
	keys[Event.Key.Code] = (Event.Type == sf::Event::KeyPressed);
}

bool SFMLKeyboardHandler::Held(const sf::Key::Code& keyCode)
{
	return keys[keyCode];
}

bool SFMLKeyboardHandler::Pressed(const sf::Key::Code& keyCode)
{
	return keys[keyCode] && !oldKeys[keyCode];
}

bool SFMLKeyboardHandler::Released(const sf::Key::Code& keyCode)
{
	return !keys[keyCode] && oldKeys[keyCode];
}
