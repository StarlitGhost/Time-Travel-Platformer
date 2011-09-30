#pragma once

#include "FlatWorld/ScreenSystem/Screen.h"

#include <string>

namespace FlatWorld
{
	class CEngine;
	class Font;
	class GameObject;
}

class screenTest : public FlatWorld::CScreen
{
public:
	void Update(float dt);
	void Draw();
	void Load();
	void Unload();

private:
	FlatWorld::CEngine* engine;

	FlatWorld::Font* font;
	std::string testInfo, testData;

	FlatWorld::GameObject* gameObject;
};
