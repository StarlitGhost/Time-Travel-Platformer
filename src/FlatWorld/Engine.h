#pragma once

// Forward Declarations
namespace sf{class Window;}
class CScreen;
class CScreenManager;
class CSFMLTimer;

class CEngine
{
public:
	~CEngine(void);

	static CEngine* GetInstance();

	void Init(sf::Window& GameWindow, CScreen* initialScreen);

	void Update();
	void Display();

	CSFMLTimer* Timer() const {return timer;};

	void HandleEvents();

private:
	static CEngine* thisInstance;
	CScreenManager* screenManager;
	CSFMLTimer* timer;
	sf::Window* gameWindow;

	CEngine(void);
};
