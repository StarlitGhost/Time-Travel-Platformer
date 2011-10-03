#pragma once

#include "FlatWorld/ScreenSystem/Screen.h"

#include <string>

namespace FlatWorld
{
	class CEngine;
	class Font;
	class ISound;
	class GameObject;
}

class screenArenaShooter : public FlatWorld::CScreen
{
public:
	void Update(float dt);
	void Draw();
	void Load();
	void Unload();

private:
	FlatWorld::CEngine* engine;

	FlatWorld::Font* font;
	FlatWorld::ISound* sound;
	std::string testData;

	FlatWorld::GameObject* gameObject;
};
