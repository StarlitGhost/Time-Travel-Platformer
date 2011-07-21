#pragma once

class GameDisplay
{
public:
	static void Resize(unsigned int newWidth, unsigned int newHeight);

	static int Width() {return width;}
	static int Height() {return height;}

private:
	static int width;
	static int height;
};
