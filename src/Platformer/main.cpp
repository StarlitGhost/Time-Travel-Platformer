#include <SFML/Window.hpp>

#include "FlatWorld/Engine.h"

#include "Platformer/Screens/TestScreen.h"

using namespace FlatWorld;

CEngine* engine;

void Init(sf::Window& GameWindow)
{
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glClearDepth(1.0f);

	glEnable(GL_LINE_SMOOTH);
	glEnable(GL_CULL_FACE);

	glEnable(GL_TEXTURE_2D);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, GameWindow.GetWidth(), 0, GameWindow.GetHeight());
	glMatrixMode(GL_MODELVIEW);

	engine = CEngine::GetInstance();
	engine->Init(GameWindow, new TestScreen());
}

void Update()
{
	engine->Update();
}

void Display()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA); // Basic Transparency
	glLoadIdentity();

	engine->Display();
}

int main(int argc, char **argv)
{
	sf::Window GameWindow(sf::VideoMode(800, 600, 32), "Game Name Here");

	//FreeConsole();

	Init(GameWindow);

	while (GameWindow.IsOpened())
	{
		engine->HandleEvents();
		
		Update();
		Display();

		GameWindow.Display();
	}

	return 0;
}