#include "Rectangle.h"

using namespace FlatWorld;

FlatWorld::Rectangle::Rectangle(const Vector2f& topLeft, const Vector2f& bottomRight)
{
	Assign(topLeft, bottomRight);
}

FlatWorld::Rectangle::Rectangle(const Vector2f& center, float width, float height)
{
	Assign(center, width, height);
}

void Rectangle::Assign(const Vector2f& topLeft, const Vector2f& bottomRight)
{
	_topLeft = topLeft;
	_bottomRight = bottomRight;
}

void Rectangle::Assign(const Vector2f& center, float width, float height)
{
	float hWidth = width * 0.5f;
	float hHeight = height * 0.5f;

	_topLeft.x = center.x - hWidth;
	_topLeft.y = center.y + hHeight;

	_bottomRight.x = center.x + hWidth;
	_bottomRight.y = center.y - hHeight;
}

Vector2f Rectangle::Center() const
{
	return (_topLeft + _bottomRight) * 0.5f;
}

Vector2f Rectangle::TopLeft() const
{
	return _topLeft;
}

Vector2f Rectangle::TopRight() const
{
	return Vector2f(_bottomRight.x, _topLeft.y);
}

Vector2f Rectangle::BottomLeft() const
{
	return Vector2f(_topLeft.x, _bottomRight.y);
}

Vector2f Rectangle::BottomRight() const
{
	return _bottomRight;
}

float Rectangle::Width() const
{
	return _bottomRight.x - _topLeft.x;
}

float Rectangle::Height() const
{
	return _topLeft.y - _bottomRight.y;
}
