#include "TextureManager.h"

#include <SFML/OpenGL.hpp>
#include <SFML/Graphics/Image.hpp>

using namespace FlatWorld;

TextureManager::TexMap TextureManager::_textureMap;

unsigned int TextureManager::GetTextureHandle(std::string fileName)
{
	if (_textureMap.find(fileName) == _textureMap.end())
		Load(fileName);

	return _textureMap[fileName];
}

void TextureManager::Load(std::string fileName)
{
	GLuint texHandle = 0;
	sf::Image img;
	img.LoadFromFile(fileName);
	glGenTextures(1, &texHandle);
	glBindTexture(GL_TEXTURE_2D, texHandle);
	gluBuild2DMipmaps(GL_TEXTURE_2D, GL_RGBA, img.GetWidth(), img.GetHeight(), GL_RGBA, GL_UNSIGNED_BYTE, img.GetPixelsPtr());
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
	_textureMap[fileName] = texHandle;

	//_textureMap[fileName] = SOIL_load_OGL_texture(
	//	fileName.c_str(),
	//	SOIL_LOAD_AUTO,
	//	SOIL_CREATE_NEW_ID,
	//	SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y);
}

void TextureManager::FreeTexture(std::string fileName)
{
	glDeleteTextures(1, &_textureMap[fileName]);
}

void TextureManager::FreeTextures()
{
	for (TexMap::iterator i = _textureMap.begin(); i != _textureMap.end(); ++i)
	{
		glDeleteTextures(1, &(i->second));
	}
}
