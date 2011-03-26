#pragma once

// Forward Declarations
namespace sf
{
	class Window;
	class Event;
	namespace Key{enum Code;}
}

class SFMLKeyboardHandler
{
public:
	static void Init(sf::Window& gameWindow);

	static void Update();
	static void HandleEvents(const sf::Event& Event);

	static bool Held(const sf::Key::Code& keyCode);
	static bool Pressed(const sf::Key::Code& keyCode);
	static bool Released(const sf::Key::Code& keyCode);

private:
	static bool keys[];
	static bool oldKeys[];

};
