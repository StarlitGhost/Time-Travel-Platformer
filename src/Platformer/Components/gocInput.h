#pragma once

#include "Flatworld/ComponentSystem/GOComponent.h"

class InputComponent : public FlatWorld::GOComponent
{
	// GOComponent Interface
public:
	virtual const FlatWorld::GOCIdType FamilyId() const { return FlatWorld::GOCIdType("InputComponent"); };

	// InputComponent Interface
public:
	virtual void Update(float dt) = 0 {};

};
