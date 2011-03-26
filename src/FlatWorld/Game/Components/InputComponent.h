#pragma once

#include "Engine/ComponentSystem/GameComponent.h"

class InputComponent : public GameComponent
{
	// GameComponent Interface
public:
	virtual const GCIdType FamilyId() const { return GCIdType("InputComponent"); };

	// InputComponent Interface
public:
	virtual void Update(float dt) = 0 {};

};
