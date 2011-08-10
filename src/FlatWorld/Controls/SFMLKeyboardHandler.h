#pragma once

#include <SFML/Window.hpp>

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

		static bool Held(const sf::Key::Code& keyCode);
		static bool Pressed(const sf::Key::Code& keyCode);
		static bool Released(const sf::Key::Code& keyCode);

	private:
		static bool keys[];
		static bool oldKeys[];

	};
}
