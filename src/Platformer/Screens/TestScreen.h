#pragma once

#include "FlatWorld/ScreenSystem/Screen.h"

#include <string>

#define FTGL_LIBRARY_STATIC
#include <FTGL/ftgl.h>

#include "FlatWorld/Maths/Vector2f.h"

namespace FlatWorld
{
	class CEngine;
	class GameObject;
	class ParticleEmitter;
}

class TestScreen : public FlatWorld::CScreen
{
public:
	TestScreen(void);
	~TestScreen(void);

	void Update(float dt);
	void Draw();
	void Load();
	void Unload();

private:
	FlatWorld::CEngine* engine;

	FlatWorld::Vector2f line1Start, line1End;
	FlatWorld::Vector2f line2Start, line2End;
	FTTextureFont* font;
	std::string testInfo, testData;
	FlatWorld::Vector2f circleCenter;
	float circleMod;
	FlatWorld::ParticleEmitter* particleEmitter;

	FlatWorld::GameObject* gameObject;
};
