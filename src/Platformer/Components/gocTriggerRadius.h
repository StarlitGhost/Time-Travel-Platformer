#pragma once

#include "Components/gocTrigger.h"

class gctTriggerRadius;
namespace FlatWorld {class Vector2f;}

class gocTriggerRadius : public gocTrigger
{
	// GOComponent Interface
public:
	virtual const FlatWorld::GOCIdType ComponentId() const { return FlatWorld::GOCIdType("gocTriggerRadius"); }

	// gocTriggerRadius Interface
public:
	typedef float RadiusValueType;

	gocTriggerRadius(gctTriggerRadius* gct);

	const FlatWorld::Vector2f& GetPosition() const;

	RadiusValueType GetRadius() const { return _radius; }
	void SetRadius(const RadiusValueType radius) { _radius = radius; }

	void Reset();

private:
	gctTriggerRadius* _gctTriggerRadius;
	RadiusValueType _radius;

};
