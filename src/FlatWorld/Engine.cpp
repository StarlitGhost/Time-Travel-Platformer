#include "Engine.h"

#include <SFML/Window.hpp>

#include "Controls/SFMLKeyboardHandler.h"
#include "Controls/SFMLMouseHandler.h"
#include "Graphics/IGameWindow.h"
#include "ScreenSystem/Screen.h"
#include "ScreenSystem/ScreenManager.h"
#include "Utilities/Timer.h"

using namespace FlatWorld;

CEngine* CEngine::_thisInstance = new CEngine();

CEngine::CEngine(void)
{
}

CEngine::~CEngine(void)
{
	_screenManager->Unload();
}

void CEngine::Init(IGameWindow* gameWindow, CScreen* initialScreen)
{
	_gameWindow = gameWindow;
	_gameWindow->Resize(_gameWindow->Width(), _gameWindow->Height());

	_timer = new Timer(60.f);

	_screenManager = CScreenManager::GetInstance();
	_screenManager->PushScreen(initialScreen);

	SFMLMouseHandler::Invert(false, true);
}

CEngine* CEngine::GetInstance()
{
	if (_thisInstance == 0)
	{
		_thisInstance = new CEngine();
	}
	return _thisInstance;
}

void CEngine::Update()
{
	_gameWindow->HandleEvents();

	_timer->Update();

	_screenManager->Update(_timer->DT());

	SFMLKeyboardHandler::Update();
	SFMLMouseHandler::Update();
}

void CEngine::Display()
{
	_gameWindow->StartDisplay();

	_screenManager->Draw();

	_gameWindow->EndDisplay();
}
