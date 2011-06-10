#pragma once

#include "Flatworld/ComponentSystem/GameComponent.h"

class InputComponent : public FlatWorld::GameComponent
{
	// GameComponent Interface
public:
	virtual const FlatWorld::GCIdType FamilyId() const { return FlatWorld::GCIdType("InputComponent"); };

	// InputComponent Interface
public:
	virtual void Update(float dt) = 0 {};

};
