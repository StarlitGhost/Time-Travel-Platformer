#pragma once

#include "IGameWindow.h"

#include <SFML/Window.hpp>

namespace FlatWorld
{
	class SFMLGameWindow : public IGameWindow
	{
	public:
		void Resize(int newWidth, int newHeight);

		int Width() { return _window->GetWidth(); }
		int Height() { return _window->GetHeight(); }

	private:
		sf::Window* _window;
	};
}
