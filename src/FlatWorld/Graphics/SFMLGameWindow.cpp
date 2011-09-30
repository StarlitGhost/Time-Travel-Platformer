#include "SFMLGameWindow.h"

#include "Controls/SFMLKeyboardHandler.h"
#include "Controls/SFMLMouseHandler.h"
#include "Graphics/RenderManager.h"
#include "Graphics/RendererGL.h"
#include "Maths/Rectangle.h"

#include <SFML/OpenGL.hpp>

using namespace FlatWorld;

SFMLGameWindow::SFMLGameWindow(int width, int height, std::string title)
{
	_window = new sf::RenderWindow(sf::VideoMode(width, height, 32), title);
	_window->EnableKeyRepeat(false);

	RenderManager::SetRenderer(new RendererGL());

//	_gwenRenderer = new Gwen::Renderer::SFML(*_window);
//
//	_gwenSkin.SetRender(_gwenRenderer);
//	//_skin.Init("DefaultSkin.png");
//
//	_gwenSkin.SetDefaultFont(L"OpenSans.ttf", 11);
//
//	_gwenCanvas = new Gwen::Controls::Canvas(&_gwenSkin);
//	_gwenCanvas->SetDrawBackground(true);
//	_gwenCanvas->SetBackgroundColor(Gwen::Color(150, 170, 170, 128));
//
//	_gwenInput = new Gwen::Input::SFML();
//	_gwenInput->Initialize(_gwenCanvas);

	Resize(width, height);
}

SFMLGameWindow::~SFMLGameWindow()
{
//	delete _gwenInput;
//	delete _gwenCanvas;
//	delete _gwenRenderer;
	delete _window;
}

void SFMLGameWindow::StartDisplay()
{
	RenderManager::Clear();
	RenderManager::SetBlendMode(IRenderer::BLEND_Transparency);
	RenderManager::SetToIdentityMatrix();

	//glScalef(1.f,-1.f,1.f);
	//glTranslatef(0.f, -Height(), 0.f);
}

void SFMLGameWindow::EndDisplay()
{
//	_gwenCanvas->RenderCanvas();

	_window->Display();
}

void SFMLGameWindow::Resize(int width, int height)
{
	RenderManager::SetViewport(FlatWorld::Rectangle(
		Vector2f(0.f, (float)height),
		Vector2f((float)width, 0.f)
		));

//	_gwenCanvas->SetSize(width, height);
}

void SFMLGameWindow::HandleEvents()
{
	sf::Event Event;
	while (_window->PollEvent(Event))
	{
		if ((Event.Type == sf::Event::Closed))
		{
			_window->Close();
		}
		if (Event.Type == sf::Event::Resized)
		{
			Resize(Event.Size.Width, Event.Size.Height);
		}
		if (Event.Type == sf::Event::KeyPressed || Event.Type == sf::Event::KeyReleased)
		{
			SFMLKeyboardHandler::HandleEvents(Event);
		}
		if (Event.Type == sf::Event::MouseMoved || Event.Type == sf::Event::MouseButtonPressed || Event.Type == sf::Event::MouseButtonReleased || Event.Type == sf::Event::MouseWheelMoved)
		{
			SFMLMouseHandler::HandleEvents(Event, this);
		}

//		_gwenInput->ProcessMessage(Event);
	}
}
