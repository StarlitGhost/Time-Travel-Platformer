#include "SFMLSound.h"

#include <SFML/Audio.hpp>

using namespace FlatWorld;

void SFMLSound::Init(std::string soundName)
{
	_sound = GetSound(soundName);
}

std::map<std::string, sf::SoundBuffer*> SFMLSound::_bufferMap = std::map<std::string, sf::SoundBuffer*>();

sf::Sound SFMLSound::GetSound(std::string soundName)
{
	if (_bufferMap.find(soundName) == _bufferMap.end())
	{
		LoadSound(soundName);
	}
	return sf::Sound(*_bufferMap[soundName]);
}

int SFMLSound::LoadSound(std::string soundName)
{
	if (_bufferMap.find(soundName) == _bufferMap.end())
	{
		_bufferMap[soundName] = new sf::SoundBuffer();
		if (_bufferMap[soundName]->LoadFromFile(soundName))
		{
			// Sound loaded successfully
			return 1;
		}
		else
		{
			// Sound failed to load
			return 0;
		}
	}
	else
	{
		// Sound already loaded
		return 2;
	}
}
