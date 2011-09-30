#pragma once

#include "FlatWorld/ScreenSystem/Screen.h"

class screenMenu : public FlatWorld::CScreen
{
public:
	void Update(float dt);
	void Draw();
	void Load();
	void Unload();

};
