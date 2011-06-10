#include "ScreenManager.h"

#include <vector>

#include "Screen.h"

using namespace FlatWorld;

CScreenManager* CScreenManager::thisInstance = new CScreenManager();

CScreenManager::CScreenManager(void)
{
	screens = std::vector<CScreen*>();
}

CScreenManager::~CScreenManager(void)
{
	
}

CScreenManager* CScreenManager::GetInstance()
{
	if (thisInstance == 0)
	{
		thisInstance = new CScreenManager();
	}
	return thisInstance;
}

void CScreenManager::Update(float dt)
{
	if (!screens.empty())
	{
		// Update only the top-most screen in the stack
		screens.back()->Update(dt);
	}
}

void CScreenManager::Draw()
{
	if (!screens.empty())
	{
		// Draw all screens in the stack, starting from the bottom
		for (std::vector<CScreen*>::iterator i = screens.begin(); i != screens.end(); ++i)
		{
			(*i)->Draw();
		}
	}
}

void CScreenManager::ChangeScreen(CScreen* newScreen)
{
	if (!screens.empty())
	{
		PopScreen();
	}

	PushScreen(newScreen);
}

void CScreenManager::PushScreen(CScreen* newScreen)
{
	screens.push_back(newScreen);
	screens.back()->Load();
}

void CScreenManager::PopScreen()
{
	if (!screens.empty())
	{
		screens.back()->Unload();
		screens.pop_back();
	}
}

void CScreenManager::Unload()
{
	while (!screens.empty())
	{
		PopScreen();
	}
}