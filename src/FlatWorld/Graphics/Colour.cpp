#include "Colour.h"

#include <iostream>

#include <SFML/Window/OpenGL.hpp>

using namespace FlatWorld;

Colour::Colour(void)
{
	RBGA(1.0f, 1.0f, 1.0f, 1.0f);
}

Colour::Colour(const float& r, const float& g, const float& b, const float& a)
{
	RBGA(r, g, b, a);
}

Colour::Colour(const float& rgba)
{
	RBGA(rgba, rgba, rgba, rgba);
}

Colour::~Colour(void)
{
}

void Colour::RBGA(const float& r, const float& g, const float& b, const float& a)
{
	_colour[0] = r;
	_colour[1] = g;
	_colour[2] = b;
	_colour[3] = a;
}

void Colour::Apply() const
{
	glColor4fv(&_colour[0]);
}

Colour Colour::Black()
{
	return Colour(0.f, 0.f, 0.f, 1.f);
}

Colour Colour::White()
{
	return Colour(1.f, 1.f, 1.f, 1.f);
}

Colour Colour::Red()
{
	return Colour(1.f, 0.f, 0.f, 1.f);
}

Colour Colour::Green()
{
	return Colour(0.f, 1.f, 0.f, 1.f);
}

Colour Colour::Blue()
{
	return Colour(0.f, 0.f, 1.f, 1.f);
}

Colour Colour::Yellow()
{
	return Colour(1.f, 1.f, 0.f, 1.f);
}

Colour Colour::Cyan()
{
	return Colour(0.f, 1.f, 1.f, 1.f);
}

Colour Colour::Magenta()
{
	return Colour(1.f, 0.f, 1.f, 1.f);
}

Colour Colour::Null()
{
	return Colour(0.f, 0.f, 0.f, 0.f);
}

Colour Colour::Candle()
{
	return Colour(1.f, 0.576f, 0.161f, 1.f);
}

Colour Colour::Tungsten40W()
{
	return Colour(1.f, 0.772f, 0.561f, 1.f);
}

Colour Colour::Tungsten100W()
{
	return Colour(1.f, 0.839f, 0.667f, 1.f);
}

Colour Colour::Halogen()
{
	return Colour(1.f, 0.945f, 0.878f, 1.f);
}

Colour Colour::CarbonArc()
{
	return Colour(1.f, 0.980f, 0.957f, 1.f);
}

Colour Colour::HighNoonSun()
{
	return Colour(1.f, 1.f, 0.984f, 1.f);
}

Colour Colour::DirectSunlight()
{
	return Colour(1.f, 1.f, 1.f, 1.f);
}

Colour Colour::OvercastSky()
{
	return Colour(0.788f, 0.886f, 1.f, 1.f);
}

Colour Colour::BlueSky()
{
	return Colour(0.251f, 0.612f, 1.f, 1.f);
}

std::istream& operator>>(std::istream& in, Colour& c)
{
	char temp;
	in >> temp >> c[0] >> temp >> c[1] >> temp >> c[2] >> temp >> c[3] >> temp;
	return in;
}

std::ostream& operator<<(std::ostream& out, const Colour& c)
{
	out << "(" << c[0] << "," << c[1] << "," << c[2] << "," << c[3] << ")";
	return out;
}
