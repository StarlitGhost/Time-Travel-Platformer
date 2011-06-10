#pragma once

#ifdef _WIN32
	#ifdef FWAPI_EXPORT_SYMBOLS
		#define FWAPI __declspec( dllexport )
	#else
		#define FWAPI __declspec( dllimport )
	#endif
#else
	#define FWAPI
#endif

// Forward Declarations
namespace sf{class Window;}

namespace FlatWorld
{
	class CScreen;
	class CScreenManager;
	class CSFMLTimer;

	class FWAPI CEngine
	{
	public:
		~CEngine(void);

		static CEngine* GetInstance();

		void Init(sf::Window& GameWindow, CScreen* initialScreen);

		void Update();
		void Display();

		CSFMLTimer* Timer() const { return timer; };

		void HandleEvents();

	private:
		static CEngine* thisInstance;
		CScreenManager* screenManager;
		CSFMLTimer* timer;
		sf::Window* gameWindow;

		CEngine(void);
	};
}