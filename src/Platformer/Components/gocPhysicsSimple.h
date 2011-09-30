#pragma once

#include "Components/gocPhysics.h"

#include "FlatWorld/Maths/Vector2f.h"

class gocPhysicsSimple : public gocPhysics
{
	// GOComponent Interface
public:
	virtual const FlatWorld::GOCIdType ComponentId() const { return FlatWorld::GOCIdType("gocPhysicsSimple"); }
	
	virtual void ReceiveMessage(std::string msg, void* data, unsigned int length);

	// gocPhysics Interface
public:
	virtual void Update(float dt);

	// gocPhysicsSimple Interface
public:
	gocPhysicsSimple();

private:
	FlatWorld::Vector2f _acceleration;
	FlatWorld::Vector2f _velocity;
	float _velocityDamping;

	float _angularAcceleration;
	float _angularVelocity;
	float _angularDamping;
};
