#include "Maths/Transform.h"

using namespace FlatWorld;

Transform::Transform()
{
	Assign(Vector2f(0.f, 0.f), Vector2f(1.f, 1.f), 0.f);
}

Transform::Transform(const Vector2f& position, const Vector2f& scale, float angle)
{
	Assign(position, scale, angle);
}

Transform::Transform(const Transform& xform)
{
	Assign(xform.Position, xform.Scale, xform.Angle);
}

void Transform::Assign(const Vector2f& position, const Vector2f& scale, float angle)
{
	this->Position = position;
	this->Scale = scale;
	this->Angle = angle;
}
