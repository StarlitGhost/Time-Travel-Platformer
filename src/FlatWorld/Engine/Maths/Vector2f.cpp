#include "Vector2f.h"

#include <math.h>

Vector2f::Vector2f(void)
{
    vec[0] = 0;
    vec[1] = 0;
}

Vector2f::Vector2f(float xy)
{
	vec[0] = xy;
	vec[1] = xy;
}

Vector2f::Vector2f(float x, float y)
{
    vec[0] = x;
    vec[1] = y;
}

Vector2f::~Vector2f(void)
{
}

bool Vector2f::operator==(const Vector2f& v) const
{
	return (vec[0] == v.X() && vec[1] == v.Y());
}

bool Vector2f::operator!=(const Vector2f& v) const
{
	return !(*this == v);
}

Vector2f Vector2f::operator-() const
{
	return Vector2f(-vec[0], -vec[1]);
}

Vector2f Vector2f::operator+(const Vector2f& v) const
{
	Vector2f temp = Vector2f(vec[0], vec[1]);
	temp += v;
	return temp;
}

Vector2f Vector2f::operator-(const Vector2f& v) const
{
	Vector2f temp = Vector2f(vec[0], vec[1]);
	temp -= v;
	return temp;
}

Vector2f& Vector2f::operator+=(const Vector2f& v)
{
	vec[0] += v.X();
	vec[1] += v.Y();
	return *this;
}

Vector2f& Vector2f::operator-=(const Vector2f& v)
{
	vec[0] -= v.X();
	vec[1] -= v.Y();
	return *this;
}

float Vector2f::dot(const Vector2f& v) const
{
    return (vec[0] * v.X()) + (vec[1] * v.Y());
}

float Vector2f::length(void) const
{
    return sqrt(length2());
}

float Vector2f::length2(void) const
{
    return (vec[0] * vec[0]) + (vec[1] * vec[1]);
}

Vector2f Vector2f::normalize(void) const
{
    return *this * (1 / length());
}
