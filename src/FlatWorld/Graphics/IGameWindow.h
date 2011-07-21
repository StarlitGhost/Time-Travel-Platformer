#pragma once

#include "FlatWorld.h"

namespace FlatWorld
{
	class IGameWindow
	{
	public:
		virtual void Resize(int newWidth, int newHeight) = 0;

		virtual int Width() = 0;
		virtual int Height() = 0;
	};
}

extern "C" FWAPI FlatWorld::IGameWindow* APIENTRY GetGameWindow();