#pragma once

#include "FlatWorld.h"

namespace FlatWorld
{
	class IGameWindow
	{
	public:
		virtual void StartDisplay() = 0;
		virtual void EndDisplay() = 0;
		virtual void Resize(int newWidth, int newHeight) = 0;

		virtual void HandleEvents() = 0;

		virtual int Width() const = 0;
		virtual int Height() const = 0;
		virtual bool IsOpen() const = 0;
	};
}
