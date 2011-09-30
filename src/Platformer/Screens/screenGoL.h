#pragma once

#include "FlatWorld/ScreenSystem/Screen.h"

class screenGoL : public FlatWorld::CScreen
{
public:
	void Update(float dt);
	void Draw();
	void Load();
	void Unload();

private:
	void Iterate(int* buffer1, int* buffer2);
	void Randomize(int* buffer);
	void Clear(int* buffer);

	static const unsigned int w = 134, h = 101;
	int _buffer1[w*h], _buffer2[w*h];
	int _iterations;
	float _accum;
};
