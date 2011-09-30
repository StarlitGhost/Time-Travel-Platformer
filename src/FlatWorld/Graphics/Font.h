#pragma once

#include <string>

#include "Maths/Rectangle.h"

class FTTextureFont;

namespace FlatWorld
{
	class Font
	{
	public:
		Font();
		~Font();

		void Render(std::string text);

		void Size(unsigned int size);

		Rectangle BBox(std::string text);

	private:
		FTTextureFont* _font;

	};
}
