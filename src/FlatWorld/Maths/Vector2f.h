#pragma once

namespace FlatWorld
{
	/****************************************************************************
	* 																			*
	* Vector2f																	*
	* 																			*
	* Implements 2D vectors, and common operations that can be					*
	* performed with them.														*
	* 																			*
	* Written by Matthew Cox, 2008-2010											*
	* 																			*
	****************************************************************************/
	class Vector2f
	{
	public:
		// Default constructor, initializes x and y to 0
		Vector2f(void);
		// Single-value constructor, initializes x and y to the same value
		Vector2f(float xy);
		// Full constructor, initializes x and y to the specified values
		Vector2f(float x, float y);

		// Destructor
		~Vector2f(void);

		// Returns the vector's x value
		float X(void) const {return vec[0];};
		// Returns the vector's y value
		float Y(void) const {return vec[1];};
		// Returns the internal array representation of the vector
		const float* XY(void) const {return vec;};

		// Comparison
		bool operator==(const Vector2f& v) const;
		bool operator!=(const Vector2f& v) const;
		// Unary
		Vector2f operator-() const;
		// Scalar
		template <typename T> Vector2f operator*(const T& scalar) const
		{
			Vector2f temp = Vector2f(vec[0], vec[1]);
			temp *= scalar;
			return temp;
		}
		// Arithmetic
		Vector2f operator+(const Vector2f& v) const;
		Vector2f operator-(const Vector2f& v) const;
		// Shorthand
		Vector2f& operator+=(const Vector2f& v);
		Vector2f& operator-=(const Vector2f& v);
		template <typename T> Vector2f& operator*=(const T& scalar)
		{
			vec[0] *= scalar;
			vec[1] *= scalar;
			return *this;
		};

		// Returns the dot product of this and the specified vector
		float dot(const Vector2f& v) const;
		// Returns the scalar length of the vector (uses sqrt(), if possible it is better to use length2)
		float length(void) const;
		// Returns the squared length of the vector
		float length2(void) const;
		// Returns a normalized copy of the vector
		Vector2f normalize(void) const;

	protected:
		float vec[2];
	};
}
