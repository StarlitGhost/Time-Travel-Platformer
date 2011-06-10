#include "Engine.h"

#include <SFML/Window.hpp>

#include "Controls/SFMLKeyboardHandler.h"
#include "Controls/SFMLMouseHandler.h"
#include "Core/SFMLTimer.h"
#include "Graphics/GameDisplay.h"
#include "ScreenSystem/Screen.h"
#include "ScreenSystem/ScreenManager.h"

using namespace FlatWorld;

CEngine* CEngine::thisInstance = new CEngine();

CEngine::CEngine(void)
{
}

CEngine::~CEngine(void)
{
	screenManager->Unload();
}

void CEngine::Init(sf::Window& gameWindow, CScreen* initialScreen)
{
	this->gameWindow = &gameWindow;
	GameDisplay::Resize(gameWindow.GetWidth(), gameWindow.GetHeight());

	timer = new CSFMLTimer(60.f, gameWindow);

	screenManager = CScreenManager::GetInstance();
	screenManager->PushScreen(initialScreen);

	SFMLKeyboardHandler::Init(gameWindow);
	SFMLMouseHandler::Invert(false, true);

}

CEngine* CEngine::GetInstance()
{
	if (thisInstance == 0)
	{
		thisInstance = new CEngine();
	}
	return thisInstance;
}

void CEngine::Update()
{
	timer->Update();

	screenManager->Update(timer->DT());

	SFMLKeyboardHandler::Update();
	SFMLMouseHandler::Update();
}

void CEngine::Display()
{
	screenManager->Draw();
}

void CEngine::HandleEvents()
{
	sf::Event Event;
	while (gameWindow->GetEvent(Event))
	{
		if ((Event.Type == sf::Event::Closed))
		{
			gameWindow->Close();
		}
		if (Event.Type == sf::Event::Resized)
		{
			GameDisplay::Resize(Event.Size.Width, Event.Size.Height);
		}
		if (Event.Type == sf::Event::KeyPressed || Event.Type == sf::Event::KeyReleased)
		{
			SFMLKeyboardHandler::HandleEvents(Event);
		}
		if (Event.Type == sf::Event::MouseMoved || Event.Type == sf::Event::MouseButtonPressed || Event.Type == sf::Event::MouseButtonReleased || Event.Type == sf::Event::MouseWheelMoved)
		{
			SFMLMouseHandler::HandleEvents(Event);
		}
	}
}
