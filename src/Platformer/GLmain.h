#pragma once

/****************************************************************************
* 																			*
* GLmain																	*
* 																			*
* Abstracts away most/all of the GL functions that would otherwise take up	*
* space in the actual main. We can still change/add to them here if needed,	*
* I just thought they'd be better off in their own static class.			*
* 																			*
* Written by Matthew Cox, 2010												*
* 																			*
****************************************************************************/
class GLmain
{
public:
	static void Init(int& argc, char** argv);
	static void InitGLUT(int& argc, char** argv);
	static void InitGL();

	static void StartDisplay();
	static void EndDisplay();

	static void Redisplay();

	static void StartEventLoop();

	static void Reshape(int width, int height);

	static void BindDisplayFunc(void (* displayFunc)(void));
	static void BindIdleFunc(void (* idleFunc)(void));

	static void BindKeyboardFuncs(
		void (* keyDownFunc)(unsigned char, int, int),
		void (* keyUpFunc)(unsigned char, int, int),
		void (* specialKeyDownFunc)(int, int, int),
		void (* specialKeyUpFunc)(int, int, int));

	static void BindMouseFuncs(
		void (* mouseFunc)(int, int, int, int),
		void (* motionFunc)(int, int),
		void (* passiveMotionFunc)(int, int));
};
