#pragma once

#include <SFML/Window/Event.hpp>

// Forward Declarations
//namespace sf
//{
//	class Event;
//	namespace Key{enum Code;}
//}

namespace FlatWorld
{
	class SFMLKeyboardHandler
	{
	public:
		static void Update();
		static void HandleEvents(const sf::Event& Event);

		static bool Held(const sf::Keyboard::Key& keyCode);
		static bool Pressed(const sf::Keyboard::Key& keyCode);
		static bool Released(const sf::Keyboard::Key& keyCode);

	private:
		static bool keys[];
		static bool oldKeys[];

	};
}
