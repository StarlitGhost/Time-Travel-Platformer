#pragma once

// Forward Declarations
namespace sf
{
	class Event;
	namespace Mouse{enum Button;}
}

namespace FlatWorld
{
	class IGameWindow;
	class Vector2f;

	class SFMLMouseHandler
	{
	public:
		static void Invert(bool X, bool Y);

		static void Update();
		static void HandleEvents(const sf::Event& Event, const IGameWindow* gameWindow);

		static bool Held(const sf::Mouse::Button& button);
		static bool Pressed(const sf::Mouse::Button& button);
		static bool Released(const sf::Mouse::Button& button);

		static bool WheelUp();
		static bool WheelDown();
		static int WheelDelta();

		static Vector2f Position();
		static Vector2f PositionChange();
		static bool Moved();

	private:
		static bool buttons[];
		static bool oldButtons[];
		static Vector2f position;
		static Vector2f oldPosition;
		static bool invertX;
		static bool invertY;
		static int wheelDelta;

	};
}
