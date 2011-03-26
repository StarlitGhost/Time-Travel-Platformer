#include "GLmain.h"

#define FREEGLUT_STATIC
#include <GL/freeglut.h>

void GLmain::Init(int& argc, char** argv)
{
	InitGLUT(argc, argv);
	InitGL();
}

void GLmain::InitGLUT(int& argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowSize(640, 480);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Game Name Here");

	glutReshapeFunc(Reshape);

	glutIgnoreKeyRepeat(true);
}

void GLmain::InitGL()
{
	Reshape(640, 480);

	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glClearDepth(1.0f);

	glEnable(GL_LINE_SMOOTH);
	glEnable(GL_CULL_FACE);

	glEnable(GL_TEXTURE_2D);
}

void GLmain::StartDisplay()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA); // Basic Transparency
	glLoadIdentity();
}

void GLmain::EndDisplay()
{
	glutSwapBuffers();
}

void GLmain::Redisplay()
{
	glutPostRedisplay();
}

void GLmain::StartEventLoop()
{
	glutMainLoop();
}

void GLmain::Reshape(int width, int height)
{
	glViewport(
		0, 0,
		(GLsizei)width, (GLsizei)height
		);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, width, 0, height);
	glMatrixMode(GL_MODELVIEW);
}

void GLmain::BindDisplayFunc(void (* displayFunc)(void))
{
	glutDisplayFunc(displayFunc);
}

void GLmain::BindIdleFunc(void (* idleFunc)(void))
{
	glutIdleFunc(idleFunc);
}

void GLmain::BindKeyboardFuncs(void (* keyDownFunc)(unsigned char, int, int),
							   void (* keyUpFunc)(unsigned char, int, int),
							   void (* specialKeyDownFunc)(int, int, int),
							   void (* specialKeyUpFunc)(int, int, int))
{
	glutKeyboardFunc(keyDownFunc);
	glutKeyboardUpFunc(keyUpFunc);
	glutSpecialFunc(specialKeyDownFunc);
	glutSpecialUpFunc(specialKeyUpFunc);
}

void GLmain::BindMouseFuncs(void (* mouseFunc)(int, int, int, int),
							void (* motionFunc)(int, int),
							void (* passiveMotionFunc)(int, int))
{
	glutMouseFunc(mouseFunc);
	glutMotionFunc(motionFunc);
	glutPassiveMotionFunc(passiveMotionFunc);
}
