#pragma once

#include <string>

namespace FlatWorld
{
	class ISound
	{
	public:
		virtual void Init(std::string soundName) = 0;

		virtual void Play() = 0;
		virtual void Pause() = 0;
		virtual void Stop() = 0;

	};
}
