#pragma once

#include "Graphics/IGameWindow.h"

#include <SFML/Graphics/RenderWindow.hpp>

/*#include <Gwen/Renderers/SFML.h>
#include <Gwen/Skins/Simple.h>
#include <Gwen/Skins/TexturedBase.h>
#include <Gwen/Input/SFML.h>*/

namespace FlatWorld
{
	class SFMLGameWindow : public IGameWindow
	{
	public:
		SFMLGameWindow(int width, int height, std::string title);
		~SFMLGameWindow();

		void StartDisplay();
		void EndDisplay();
		void Resize(int newWidth, int newHeight);

		void HandleEvents();

		int Width() const { return _window->GetWidth(); }
		int Height() const { return _window->GetHeight(); }
		bool IsOpen() const { return _window->IsOpened(); }

	private:
		sf::RenderWindow* _window;
		/*Gwen::Renderer::SFML* _gwenRenderer;
		Gwen::Skin::Simple _gwenSkin;
		Gwen::Controls::Canvas* _gwenCanvas;
		Gwen::Input::SFML* _gwenInput;*/
	};
}
