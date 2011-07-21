#pragma once

#include <iosfwd>

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
		Vector2f();
		// Full constructor, initializes x and y to the specified values
		Vector2f(float x, float y);
		Vector2f(float xy[]);

		void Assign(float x, float y);
		// Returns an array representation of the vector
		const float* xy() const { return &x; }

		// Returns the dot product of this and the specified vector
		float Dot(const Vector2f& v) const;
		// Returns the scalar Length of the vector (uses sqrt(), if possible it is better to use LengthSquared)
		float Length() const;
		// Returns the squared Length of the vector
		float LengthSquared() const;
		// Normalizes the vector, and returns a reference to itself
		Vector2f& Normalize();
		// Returns a normalized copy of the vector
		Vector2f Unit() const;
		// Returns true if the vector's length is 1
		bool IsNormalized() const;

		float& operator[](int i);
		const float& operator[](int i) const;

		// Comparison
		bool operator==(const Vector2f& v) const;
		bool operator!=(const Vector2f& v) const;

		friend Vector2f operator-(const Vector2f& v);
		friend Vector2f operator+(const Vector2f& lhs, const Vector2f& rhs);
		friend Vector2f operator-(const Vector2f& lhs, const Vector2f& rhs);
		friend Vector2f& operator+=(Vector2f& lhs, const Vector2f& rhs);
		friend Vector2f& operator-=(Vector2f& lhs, const Vector2f& rhs);

		template <typename T>
		friend Vector2f operator*(const Vector2f& v, const T scalar);
		template <typename T>
		friend Vector2f operator*(const T scalar, const Vector2f& v);
		template <typename T>
		friend Vector2f operator/(const Vector2f& v, const T scalar);
		template <typename T>
		friend Vector2f& operator*=(Vector2f& v, const T scalar);
		template <typename T>
		friend Vector2f& operator/=(Vector2f& v, const T scalar);

		float x,y;
	};

	std::istream& operator>>(std::istream& in, Vector2f& v);
	std::ostream& operator<<(std::ostream& out, const Vector2f& v);
	
	inline Vector2f operator-(const Vector2f& v)
	{
		return Vector2f(-v.x, -v.y);
	}

	inline Vector2f operator+(const Vector2f& lhs, const Vector2f& rhs)
	{
		Vector2f temp = Vector2f(lhs);
		temp += rhs;
		return temp;
	}

	inline Vector2f operator-(const Vector2f& lhs, const Vector2f& rhs)
	{
		Vector2f temp = Vector2f(lhs);
		temp -= rhs;
		return temp;
	}

	inline Vector2f& operator+=(Vector2f& lhs, const Vector2f& rhs)
	{
		lhs.x += rhs.x;
		lhs.y += rhs.y;
		return lhs;
	}

	inline Vector2f& operator-=(Vector2f& lhs, const Vector2f& rhs)
	{
		lhs.x -= rhs.x;
		lhs.y -= rhs.y;
		return lhs;
	}

	template <typename T>
	inline Vector2f operator*(const Vector2f& v, const T scalar)
	{
		Vector2f temp = Vector2f(v);
		temp *= scalar;
		return temp;
	}

	template <typename T>
	inline Vector2f operator*(const T scalar, const Vector2f& v)
	{
		Vector2f temp = Vector2f(v);
		temp *= scalar;
		return temp;
	}

	template <typename T>
	inline Vector2f operator/(const Vector2f& v, const T scalar)
	{
		Vector2f temp = Vector2f(v);
		temp /= scalar;
		return temp;
	}

	template <typename T>
	inline Vector2f& operator*=(Vector2f& v, const T scalar)
	{
		v.x *= scalar;
		v.y *= scalar;
		return v;
	}

	template <typename T>
	inline Vector2f& operator/=(Vector2f& v, const T scalar)
	{
		assert(scalar != 0);
		v.x /= scalar;
		v.y /= scalar;
		return v;
	}
}
