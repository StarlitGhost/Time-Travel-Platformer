#pragma once

#include "Flatworld/ComponentSystem/GOComponent.h"

class gocInput : public FlatWorld::GOComponent
{
	// GOComponent Interface
public:
	virtual const FlatWorld::GOCIdType FamilyId() const { return FlatWorld::GOCIdType("gocInput"); };

	// gocInput Interface
public:
	virtual void Update(float dt) = 0 {};

};
