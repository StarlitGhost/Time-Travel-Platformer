#include "Vector2f.h"

#include <iostream>
#include <math.h>
#include <assert.h>

#include "Utilities/MathsUtilities.h"

using namespace FlatWorld;
using namespace MathsUtilities;

Vector2f::Vector2f()
{
	Assign(0.f, 0.f);
}

Vector2f::Vector2f(float x, float y)
{
	Assign(x, y);
}

Vector2f::Vector2f(float xy[])
{
	Assign(xy[0], xy[1]);
}

void Vector2f::Assign(float x, float y)
{
	this->x = x;
	this->y = y;
}

void Vector2f::Zero()
{
	Assign(0, 0);
}

void Vector2f::Negate()
{
	Assign(-x, -y);
}

float Vector2f::Dot(const Vector2f& v) const
{
	return (x * v.x) + (y * v.y);
}

float Vector2f::Length(void) const
{
	return sqrt(LengthSquared());
}

float Vector2f::LengthSquared(void) const
{
	return this->Dot(*this);
}

Vector2f& Vector2f::Normalize()
{
	*this *= 1 / Length();
	return *this;
}

Vector2f Vector2f::Unit(void) const
{
	Vector2f v(*this);
	v.Normalize();
	return v;
}

bool Vector2f::IsNormalized() const
{
	return equal(LengthSquared(), 1);
}

float& Vector2f::operator[](int i)
{
	assert(i >= 0);
	assert(i <= 1);

	return *(&x + i);
}

const float& Vector2f::operator[](int i) const
{
	assert(i >= 0);
	assert(i <= 1);

	return *(&x + i);
}

bool Vector2f::operator==(const Vector2f& v) const
{
	return (equal(x, v.x) && equal(y, v.y));
}

bool Vector2f::operator!=(const Vector2f& v) const
{
	return !(*this == v);
}

std::istream& operator>>(std::istream& in, Vector2f& v)
{
	char temp;
	in >> temp >> v.x >> temp >> v.y >> temp;
	return in;
}

std::ostream& operator<<(std::ostream& out, const Vector2f& v)
{
	out << "(" << v.x << "," << v.y << ")";
	return out;
}
