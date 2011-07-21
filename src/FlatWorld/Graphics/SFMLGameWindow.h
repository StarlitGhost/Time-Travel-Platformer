#pragma once

#include "IGameWindow.h"

#include <SFML/Window.hpp>

namespace FlatWorld
{
	class SFMLGameWindow : public IGameWindow
	{
	public:
		SFMLGameWindow(int width, int height, std::string title);
		~SFMLGameWindow();

		void StartDisplay();
		void EndDisplay() { _window->Display(); }
		void Resize(int newWidth, int newHeight);

		void HandleEvents();

		int Width() const { return _window->GetWidth(); }
		int Height() const { return _window->GetHeight(); }
		bool IsOpen() const { return _window->IsOpened(); }

	private:
		sf::Window* _window;
	};
}
