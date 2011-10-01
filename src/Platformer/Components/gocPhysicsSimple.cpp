#include "gocPhysicsSimple.h"

#include "FlatWorld/ComponentSystem/GameObject.h"
#include "FlatWorld/Utilities/MathsUtilities.h"

FlatWorld::Vector2f Direction(float angle)
{
	angle = MathsUtilities::degToRad(angle);

	return FlatWorld::Vector2f(cos(angle), sin(angle));
}

void gocPhysicsSimple::ReceiveMessage(std::string msg, void* data, unsigned int length)
{
	if (msg == "force")
		_acceleration += (*(FlatWorld::Vector2f*)data);
}

void gocPhysicsSimple::Update(float dt)
{
	_velocity += _acceleration * dt;
	_angularVelocity += _angularAcceleration * dt;

	_velocity *= (1.f - (_velocityDamping * dt));
	_angularVelocity *= (1.f - (_angularDamping * dt));

	FlatWorld::Transform xform = GetOwner()->GetTransform();
	xform.Position += _velocity;
	xform.Angle += _angularVelocity;
	GetOwner()->SetTransform(xform);

	_acceleration = FlatWorld::Vector2f(0.f, 0.f);
	_angularAcceleration = 0.f;
}

gocPhysicsSimple::gocPhysicsSimple()
{
	_velocityDamping = 1.f;

	_angularAcceleration = 0.f;
	_angularVelocity = 0.f;
	_angularDamping = 1.f;
}