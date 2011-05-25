#include "GameDisplay.h"

#include <SFML/Window/OpenGL.hpp>

int GameDisplay::width = 0;
int GameDisplay::height = 0;

void GameDisplay::Resize(unsigned int newWidth, unsigned int newHeight)
{
	width = newWidth;
	height = newHeight;
	glViewport(0, 0, width, height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, width, 0, height);
	glMatrixMode(GL_MODELVIEW);
}
