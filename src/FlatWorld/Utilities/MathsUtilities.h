#pragma once

#include <stdlib.h>
#define _USE_MATH_DEFINES
#include <math.h>

namespace MathsUtilities
{
	const float epsilon = 0.00001f;		// Floating point epsilon for equality testing
	const float epsilonSquared = epsilon * epsilon;		// Squared floating point epsilon, for where it is necessary

	inline float degToRad(const float degrees)
	{
		return (degrees * (float)M_PI) / 180.0f;
	}

	inline float radToDeg(const float radians)
	{
		return (radians * 180.0f) / ((float)M_PI);
	}

	inline int randomInRangei(const int p_lowerBound, const int p_upperBound)
	{
		return (rand()%p_upperBound) + p_lowerBound;
	}

	inline bool equal(float lhs, float rhs)
	{
		const float diff = lhs - rhs;
		return diff < epsilon && diff > -epsilon ? true : false;
	}

	template <typename T>
	inline T minimum(T a, T b)
	{
		return a < b ? a : b;
	}

	template <typename T>
	inline T maximum(T a, T b)
	{
		return a > b ? a : b;
	}

	template <typename T>
	inline T clamp(T val, T minimum, T maximum)
	{
		return val < minimum ? minimum : (maximum < val ? maximum : val);
	}

	template <typename T>
	inline T approach(T val, T target, T stepSize)
	{
		if (val < target)
		{
			val += stepSize;
			if (val > target) return target;
		}
		else if (val > target)
		{
			val -= stepSize;
			if (val < target) return target;
		}
		return val;
	}
}