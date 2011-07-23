#pragma once

namespace FlatWorld
{
	// Forward Declarations
	class Colour;

	/****************************************************************************
	* 																			*
	* ColourUtilities																*
	* 																			*
	* A utility class which holds functions that can be performed upon or with	*
	* colours.																	*
	* 																			*
	* Written by Matthew Cox, 2010												*
	* 																			*
	****************************************************************************/
	class ColourUtilities
	{
	public:
		// RGB-based Functions
		static Colour Lerp(const Colour& startColour, const Colour& endColour, const float& interpolationPoint);
		static Colour Negative(const Colour& colour, const bool& negativeAlpha = false);

		// HSV-based Functions
		static Colour Invert(const Colour& colour);
		static Colour HSVLerp(const Colour& startColour, const Colour& endColour, const float& interpolationPoint);

		// YUV-based Functions
		static Colour ForeColour(const Colour& backColour);

		// Format Conversion
		static void RGB2HSV(const Colour& colour, float& outH, float& outS, float& outV);
		static Colour HSV2RGB(const float& H, const float& S, const float& V, const float& A = 1.f);
		//static void RGB2HSL(const Colour& colour, float& outH, float& outS, float& outL);
		//static Colour HSL2RGB(const float& H, const float& S, const float& L, const float& A = 1.f);
		static void RGB2YUV(const Colour& colour, float& outY, float& outU, float& outV);
		static Colour YUV2RGB(const float& Y, const float& U, const float& V, const float& A = 1.f);

	};
}