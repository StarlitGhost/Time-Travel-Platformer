#include "ColourUtils.h"

#include <math.h>

#include "Engine/Graphics/Colour.h"

Colour ColourUtils::Lerp(const Colour& startColour, const Colour& endColour, const float& interpolationPoint)
{
	return Colour(
		startColour.R() + ((endColour.R() - startColour.R()) * interpolationPoint),
		startColour.G() + ((endColour.G() - startColour.G()) * interpolationPoint),
		startColour.B() + ((endColour.B() - startColour.B()) * interpolationPoint),
		startColour.A() + ((endColour.A() - startColour.A()) * interpolationPoint)
		);
}

Colour ColourUtils::Negative(const Colour& colour, const bool& negativeAlpha)
{
	return Colour(1.f - colour.R(), 1.f - colour.G(), 1.f - colour.B(), negativeAlpha ? 1.f - colour.A() : colour.A());
}

Colour ColourUtils::Invert(const Colour& colour)
{
	float H, S, V;
	RGB2HSV(colour, H, S, V);
	H += 180.f;
	if (H >= 360.f)
	{
		H -= 360.f;
	}
	return HSV2RGB(H, S, V, colour.A());
}

Colour ColourUtils::HSVLerp(const Colour& startColour, const Colour& endColour, const float& interpolationPoint)
{
	float H1, S1, V1, H2, S2, V2, H, S, V, A;
	RGB2HSV(startColour, H1, S1, V1);
	RGB2HSV(endColour, H2, S2, V2);

	H = H1 + ((H2 - H1) * interpolationPoint);
	S = S1 + ((S2 - S1) * interpolationPoint);
	V = V1 + ((V2 - V1) * interpolationPoint);
	A = startColour.A() + ((endColour.A() - startColour.A()) * interpolationPoint);

	return HSV2RGB(H, S, V, A);
}

Colour ColourUtils::ForeColour(const Colour& backColour)
{
	float Y, U, V;
	RGB2YUV(backColour, Y, U, V);
	if (Y > .5f)
	{
		return Colour(0.f,0.f,0.f,1.f);
	}
	else
	{
		return Colour(1.f,1.f,1.f,1.f);
	}
}

void ColourUtils::RGB2HSV(const Colour& colour, float& outH, float& outS, float& outV)
{
	float maxC = colour.R();
	if (colour.G() > maxC) maxC = colour.G();
	if (colour.B() > maxC) maxC = colour.B();
	float minC = colour.R();
	if (colour.B() < minC) minC = colour.G();
	if (colour.B() < minC) minC = colour.B();

	float delta = maxC - minC;

	outV = maxC;

	if (delta == 0.f)
	{
		outH = 0.f;
		outS = 0.f;
	}
	else
	{
		outS = delta / maxC;
		float dR = (60.f * (maxC - colour.R()) / delta) + 180.f;
		float dG = (60.f * (maxC - colour.G()) / delta) + 180.f;
		float dB = (60.f * (maxC - colour.B()) / delta) + 180.f;
		if (maxC == colour.R())
		{
			outH = dB - dG;
		}
		else if (maxC == colour.G())
		{
			outH = dR - dB + 120.f;
		}
		else
		{
			outH = dG - dR + 240.f;
		}

		if (outH < 0.f)
		{
			outH += 360.f;
		}
		else if (outH >= 360.f)
		{
			outH -= 360.f;
		}
	}
}

Colour ColourUtils::HSV2RGB(const float& H, const float& S, const float& V, const float& A)
{
	if (V == 0.f) // Black
	{
		return Colour(0.f, 0.f, 0.f, 1.f);
	}
	else if (S == 0.f) // A shade of gray
	{
		return Colour(V, V, V, 1.f);
	}
	else
	{
		// Split Hue into 60 degree chunks, to allow for switch statement
		float hf = H / 60.f;
		int i = (int)floor(hf);					// Variable for the switch statement
		float f = hf - i;						// Factorial part of H

		// Set up non-dominant colour components
		float p = V * (1.f - S);				// Least dominant colour component
		float q = V * (1.f - S * f);			// Dunno lol
		float t = V * (1.f - S * (1.f - f));	// Dunno lol

		switch (i)
		{
		case 0:
		case 6: // In case of rounding errors
			return Colour(V, t, p, A);
			break;
		case 1:
			return Colour(q, V, p, A);
			break;
		case 2:
			return Colour(p, V, t, A);
			break;
		case 3:
			return Colour(p, q, V, A);
			break;
		case 4:
			return Colour(t, p, V, A);
			break;
		default:
		case -1: // In case of rounding errors
			return Colour(V, p, q, A);
			break;
		}
	}
}

// Possible implementations here: http://www.geekymonkey.com/Programming/CSharp/RGB2HSL_HSL2RGB.htm
//void ColourUtils::RGB2HSL(const Colour& colour, float& outH, float& outS, float& outL)
//{
//	
//}
//
//Colour ColourUtils::HSL2RGB(const float& H, const float& S, const float& L, const float& A /*= 1.f*/)
//{
//	
//}

void ColourUtils::RGB2YUV(const Colour& colour, float& outY, float& outU, float& outV)
{
	outY = (0.299f * colour.R()) + (0.587f * colour.G()) + (0.114f * colour.B());
	outU = (colour.B() - outY) * 0.565f;
	outV = (colour.R() - outY) * 0.713f;
}

Colour ColourUtils::YUV2RGB(const float& Y, const float& U, const float& V, const float& A)
{
	return Colour(
		Y + (1.403f * V),					// R
		Y - (0.344f * U) - (0.714f * V),	// G
		Y + (1.770f * U),					// B
		A);									// A
}
