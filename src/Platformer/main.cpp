#include "FlatWorld/Engine.h"
#include "FlatWorld/Graphics/IGameWindow.h"
#include "FlatWorld/Graphics/SFMLGameWindow.h"

#include "Platformer/Screens/TestScreen.h"

#include "sfml/Window/OpenGL.hpp"

using namespace FlatWorld;

CEngine* engine;

void Init(IGameWindow* GameWindow)
{
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glClearDepth(1.0f);

	glEnable(GL_LINE_SMOOTH);
	glEnable(GL_CULL_FACE);

	glEnable(GL_TEXTURE_2D);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, GameWindow->Width(), 0, GameWindow->Height());
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
	engine->Display();
}

int main(int argc, char **argv)
{
	//sf::Window GameWindow(sf::VideoMode(800, 600, 32), "Game Name Here");

	IGameWindow* GameWindow = new SFMLGameWindow(800, 600, "Game Name Here");

	//FreeConsole();

	Init(GameWindow);

	while (GameWindow->IsOpen())
	{
		Update();
		Display();
	}

	return 0;
}