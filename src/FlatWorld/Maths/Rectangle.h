#pragma once

#include "Maths/Vector2f.h"

namespace FlatWorld
{
	class Rectangle
	{
	public:
		Rectangle(const Vector2f& topLeft, const Vector2f& bottomRight);
		Rectangle(const Vector2f& center, float width, float height);

		void Assign(const Vector2f& topLeft, const Vector2f& bottomRight);
		void Assign(const Vector2f& center, float width, float height);

		Vector2f Center() const;

		Vector2f TopLeft() const;
		Vector2f TopRight() const;
		Vector2f BottomLeft() const;
		Vector2f BottomRight() const;

		float Width() const;
		float Height() const;

	private:
		Vector2f _topLeft, _bottomRight;

	};
}
