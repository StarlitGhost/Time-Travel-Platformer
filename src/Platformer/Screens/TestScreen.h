#pragma once
#include "Engine/ScreenSystem/Screen.h"

#include <string>

#define FTGL_LIBRARY_STATIC
#include <FTGL/ftgl.h>

#include "Engine/Maths/Vector2f.h"

class GameObject;
class ParticleEmitter;

class TestScreen : public CScreen
{
public:
	TestScreen(void);
	~TestScreen(void);

	void Update(float dt);
	void Draw();
	void Load();
	void Unload();

private:
	Vector2f line1Start, line1End;
	Vector2f line2Start, line2End;
	FTTextureFont* font;
	std::string testInfo, testData;
	Vector2f circleCenter;
	float circleMod;
	ParticleEmitter* particleEmitter;

	GameObject* gameObject;
};
