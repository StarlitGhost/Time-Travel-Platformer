#pragma once

#include <vector>

// Forward Declarations
class CScreen;

/****************************************************************************
* 																			*
* ScreenManager																*
* 																			*
* 'Screens' are held in a stack (implemented with a vector),				*
* and new screens are pushed and popped onto and off this stack.			*
* All screens in the stack are drawn, but only the top one is updated.		*
* The idea of the screen system is to create a separate screen for each		*
* 'screen' that the player will be seeing. This includes the main menu,		*
* each level of the game, pause screens, game over screens... and so on.	*
* The idea of them being in a stack allows a pause screen to still show		*
* the level the player was playing in the background, and to go back to		*
* /exactly/ the point in the level they were at after unpausing, as the		*
* pause screen would be popped off the top of the stack, causing the level	*
* screen to begin updating again.											*
* 																			*
* Lol, long text is long.													*
* 																			*
* Written by Matthew Cox, 2009-2010											*
* 																			*
****************************************************************************/
class CScreenManager
{
public:
	// Destructor
	~CScreenManager(void);

	/*
	 * Returns a pointer to the instance of ScreenManager (we only ever need one)
	 * This allows access to the ScreenManager from *anywhere* it is needed,
	 * without tedious adding of parameters to functions just to pass along access to it
	 */
	static CScreenManager* GetInstance();

	// Tells the Screen at the top of the stack to update
	void Update(float dt);
	// Tells each Screen in the stack to draw itself, starting from the bottom
	void Draw();

	// Unloads the Screen at the top of the stack, and loads a new one in it's place
	void ChangeScreen(CScreen* newScreen);
	// Pushes a new Screen to the top of the stack, and tells it to load itself
	void PushScreen(CScreen* newScreen);
	// Pops the Screen on the top of the stack off, and tells it to unload itself
	void PopScreen();

	// Tells all of the Screens in the stack to unload themselves, and cleans up the ScreenManager ready for destruction
	void Unload();

protected:
	/*
	 * Constructor. Called by GetInstance only if it hasn't been called before.
	 * It is protected to avoid it being called anywhere else, as we only ever want one instance of ScreenManager.
	 */
	CScreenManager(void);

private:
	static CScreenManager* thisInstance;

	std::vector<CScreen*> screens;

};
