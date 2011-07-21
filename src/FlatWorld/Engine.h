#pragma once

//#include "FlatWorld.h"

namespace FlatWorld
{
	class CScreen;
	class CScreenManager;
	class Timer;
	class IGameWindow;

	class CEngine
	{
	public:
		~CEngine(void);

		static CEngine* GetInstance();

		void Init(IGameWindow* GameWindow, CScreen* initialScreen);

		void Update();
		void Display();

		Timer* GetTimer() const { return _timer; }
		IGameWindow* GetGameWindow() const { return _gameWindow; }

	private:
		static CEngine* _thisInstance;
		CScreenManager* _screenManager;
		Timer* _timer;
		IGameWindow* _gameWindow;

		CEngine(void);
	};
}