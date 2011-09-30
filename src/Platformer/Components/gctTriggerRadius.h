#pragma once

#include "FlatWorld/ComponentSystem/GOCTemplate.h"

class gctTriggerRadius : public FlatWorld::GOCTemplate
{
	// GOCTemplate Interface
public:
	virtual const FlatWorld::GOCIdType ComponentId() const { return FlatWorld::GOCIdType("gocTriggerRadius"); }
	virtual const FlatWorld::GOCIdType FamilyId() const { return FlatWorld::GOCIdType("gocTriggerRadius"); }

	virtual FlatWorld::GOComponent* MakeComponent();

	// gctTriggerRadius Interface
public:
	typedef float RadiusValueType;

	RadiusValueType GetRadius() const { return _radius; }
	void SetRadius(const RadiusValueType radius) { _radius = radius; }

private:
	RadiusValueType _radius;

};
