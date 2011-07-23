#pragma once

#include "Audio/ISound.h"

#include <string>
#include <map>

#include <SFML/Audio/Sound.hpp>

namespace sf
{
	class SoundBuffer;
}

namespace FlatWorld
{
	class SFMLSound : public ISound
	{
	public:
		virtual void Init(std::string soundName);

		virtual void Play() { _sound.Play(); }
		virtual void Pause() { _sound.Pause(); }
		virtual void Stop() { _sound.Stop(); }

	private:
		sf::Sound _sound;

		static sf::Sound GetSound(std::string soundName);
		static int LoadSound(std::string soundName);
		static std::map<std::string, sf::SoundBuffer*> _bufferMap;

	};
}
