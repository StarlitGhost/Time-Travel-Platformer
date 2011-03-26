#pragma once

#include "Game/Components/InputComponent.h"

class SpatialComponent;

class InputPlayerComponent : public InputComponent
{
	// GameComponent Interface
public:
	virtual const GCIdType ComponentId() const { return GCIdType("InputPlayerComponent"); };

	// InputComponent Interface
public:
	virtual void Update(float dt);

	// InputPlayerComponent Interface
public:

private:

};
