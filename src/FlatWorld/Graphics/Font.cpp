#include "Font.h"

#define FTGL_LIBRARY_STATIC
#include <FTGL/ftgl.h>

#include <SFML/OpenGL.hpp>

#include "Graphics/RenderManager.h"
#include "Maths/Vector2f.h"

using namespace FlatWorld;

Font::Font()
{
	#ifdef _WIN32
		_font = new FTTextureFont("C:\\Windows\\Fonts\\tahoma.ttf");
	#else
		_font = new FTTextureFont("/usr/share/fonts/truetype/ttf-dejavu/DejaVuSans.ttf");
	#endif
}

Font::~Font()
{
	if (_font)
		delete _font;
}

void Font::Render(std::string text)
{
	_font->Render(text.c_str());
	RenderManager::ApplyTexture(0);
}

void Font::Size(unsigned int size)
{
	_font->FaceSize(size);
}

FlatWorld::Rectangle Font::BBox(std::string text)
{
	FTBBox bbox = _font->BBox(text.c_str());
	return FlatWorld::Rectangle(
		Vector2f((float)bbox.Upper().X(), (float)bbox.Upper().Y()),
		Vector2f((float)bbox.Lower().X(), (float)bbox.Lower().Y())
		);
}
