#include "screenGoL.h"

#include <stdlib.h>
#include <intrin.h>

#include "FlatWorld/Controls/SFMLKeyboardHandler.h"
#include "FlatWorld/Graphics/Colour.h"
#include "FlatWorld/Graphics/RenderManager.h"
#include "FlatWorld/Maths/Vector2f.h"

using namespace FlatWorld;

const float iterationGap = 50.f;
const int trailLength = 5;
const float alphaStep = 0.5f / (float)trailLength;

int Alive(int cellValue)
{
	return (cellValue > 0 ? 1 : 0);
}

void screenGoL::Iterate(int* buffer1, int* buffer2)
{
	Clear(buffer2);
	
	for (int y = 1; y < h - 1; ++y)
	{
		for (int x = 1; x < w - 1; ++x)
		{
			const int offset = (w * y) + x;

			const int current = buffer1[offset];

			const int neighbours =
				Alive(buffer1[offset - w - 1]) + Alive(buffer1[offset - w]) + Alive(buffer1[offset - w + 1]) +
				Alive(buffer1[offset     - 1]) +                            Alive(buffer1[offset     + 1]) +
				Alive(buffer1[offset + w - 1]) + Alive(buffer1[offset + w]) + Alive(buffer1[offset + w + 1]);

			if (current > -trailLength + 1)
				buffer2[offset] = current - 1;
			else
				buffer2[offset] = -trailLength + 1;

			if ( (current >  0) && (neighbours == 3 || neighbours == 2) ) buffer2[offset] = 1;
			if ( (current <= 0) && (neighbours == 3                  ) ) buffer2[offset] = 1;
		}
	}
}

void screenGoL::Randomize(int* buffer)
{
	for (int y = 1; y < h - 1; ++y)
	{
		for (int x = 1; x < w - 1; ++x)
		{
			const int offset = (w * y) + x;

			buffer[offset] = rand() % 2;
		}
	}
}

void screenGoL::Clear(int* buffer)
{
	memset(buffer, 0, sizeof(int) * w * h);
}

void screenGoL::Update(float dt)
{
	bool iterate = false;

	_accum += dt;
	if (_accum > iterationGap)
	{
		iterate = true;
		_accum = 0.f;
	}

	if (SFMLKeyboardHandler::Pressed(sf::Keyboard::R))
		Load();

	//if (SFMLKeyboardHandler::Pressed(sf::Keyboard::Space))
		//iterate = true;

	if (iterate)
	{
		if (_iterations % 2 == 0)
			Iterate(_buffer1, _buffer2);
		else
			Iterate(_buffer2, _buffer1);

		_iterations++;
	}
}

void screenGoL::Draw()
{
	const float scale = 5.f;
	const float spacing = 1.f;

	RenderManager::PushMatrix();
	{
		RenderManager::Translate( Vector2f( spacing, (h - 1) * (scale + spacing) ) );
		RenderManager::Scale(Vector2f(1.f, -1.f));
		for (int y = 1; y < h - 1; ++y)
		{
			for (int x = 1; x < w - 1; ++x)
			{
				const int offset = (w * y) + x;

				bool draw = false;
				if (_iterations % 2 == 0)
				{
					if (_buffer1[offset] > -trailLength + 1)
					{
						if (_buffer1[offset] > 0)
							RenderManager::SetColour( Colour(0.f, 1.f, 0.f, 1.f) );
						else
							RenderManager::SetColour( Colour( 0.f, 1.f, 0.f, 0.5f + ( ((float)_buffer1[offset] - 1.f) * alphaStep) ) );
						draw = true;
					}
				}
				else
				{
					if (_buffer2[offset] > -trailLength + 1)
					{
						if (_buffer1[offset] > 0)
							RenderManager::SetColour( Colour(0.f, 1.f, 0.f, 1.f) );
						else
							RenderManager::SetColour( Colour( 0.f, 1.f, 0.f, 0.5f + ( ((float)_buffer2[offset] - 1.f) * alphaStep) ) );
						draw = true;
					}
				}

				if (draw)
				{
					RenderManager::PushMatrix();
					{
						RenderManager::Translate( Vector2f( (scale + spacing) * x, (scale + spacing) * y) );
						RenderManager::Scale( Vector2f(scale, scale) );

						RenderManager::DrawQuad();
					}
					RenderManager::PopMatrix();
				}
			}
		}
	}
	RenderManager::PopMatrix();
}

void screenGoL::Load()
{
	_iterations = 0;
	_accum = iterationGap;

	Randomize(_buffer1);

	Clear(_buffer2);
}

void screenGoL::Unload()
{

}
