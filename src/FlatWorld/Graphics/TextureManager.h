#pragma once

#include <map>
#include <string>

namespace FlatWorld
{
	class TextureManager
	{
	public:
		static unsigned int GetTextureHandle(std::string fileName);

		static void FreeTexture(std::string fileName);
		static void FreeTextures();

	private:
		static void Load(std::string fileName);

		typedef std::map<std::string, unsigned int> TexMap;
		static TexMap _textureMap;

	};
}
