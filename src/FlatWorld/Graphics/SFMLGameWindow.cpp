#include "SFMLGameWindow.h"

#include "Controls/SFMLKeyboardHandler.h"
#include "Controls/SFMLMouseHandler.h"

#include <SFML/Window/OpenGL.hpp>

using namespace FlatWorld;

SFMLGameWindow::SFMLGameWindow(int width, int height, std::string title)
{
	_window = new sf::Window(sf::VideoMode(width, height, 32), title);
	Resize(width, height);
	_window->EnableKeyRepeat(false);
}

SFMLGameWindow::~SFMLGameWindow()
{
	delete _window;
}

void SFMLGameWindow::StartDisplay()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA); // Basic Transparency
	glLoadIdentity();
}

void SFMLGameWindow::Resize(int width, int height)
{
	glViewport(0, 0, width, height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, width, 0, height);
	glMatrixMode(GL_MODELVIEW);
}

void SFMLGameWindow::HandleEvents()
{
	sf::Event Event;
	while (_window->GetEvent(Event))
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
	}
}
