#include "SFMLGameWindow.h"

#include <SFML/Window/OpenGL.hpp>

using namespace FlatWorld;

int SFMLGameWindow::width = 0;
int SFMLGameWindow::height = 0;

void SFMLGameWindow::Resize(unsigned int newWidth, unsigned int newHeight)
{
	width = newWidth;
	height = newHeight;
	glViewport(0, 0, width, height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, width, 0, height);
	glMatrixMode(GL_MODELVIEW);
}
