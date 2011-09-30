#pragma once

#include "Maths/Vector2f.h"

namespace FlatWorld
{
	class Transform
	{
	public:
		Transform();
		Transform(const Vector2f& position, const Vector2f& scale, float angle);
		Transform(const Transform& xform);

		void Assign(const Vector2f& position, const Vector2f& scale, float angle);

		Vector2f Position;
		Vector2f Scale;
		float Angle;

	};
}
