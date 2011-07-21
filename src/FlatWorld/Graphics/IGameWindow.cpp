#include "IGameWindow.h"

#include "GameWindow.h"

using namespace FlatWorld;

IGameWindow* GetGameWindow()
{
	IGameWindow* p = new GameWindow();

	return p;
}
