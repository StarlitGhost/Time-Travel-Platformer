#include "FlatWorld/Engine.h"
#include "FlatWorld/Graphics/IGameWindow.h"
#include "FlatWorld/Graphics/SFMLGameWindow.h"

#include "Platformer/Screens/screenMenu.h"
#include "Platformer/Screens/screenArenaShooter.h"
#include "Platformer/Screens/screenGoL.h"

#include <SFML/OpenGL.hpp>

using namespace FlatWorld;

CEngine* engine;

void Init(IGameWindow* GameWindow)
{
	std::cout << "Init Start" << std::endl;

	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glClearDepth(1.0f);

	glEnable(GL_LINE_SMOOTH);
	//glEnable(GL_CULL_FACE);
	glEnable(GL_TEXTURE_2D);

	engine = CEngine::GetInstance();
	engine->Init(GameWindow, new screenArenaShooter());
}

void Update()
{
	engine->Update();
}

void Display()
{
	engine->Display();
}

int main(int /*argc*/, char** /*argv*/)
{
	std::cout << "Main Start" << std::endl;

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
