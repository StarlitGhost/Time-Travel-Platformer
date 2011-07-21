#pragma once

#include "Platformer/Components/InputComponent.h"

class SpatialComponent;

class InputPlayerComponent : public InputComponent
{
	// GameComponent Interface
public:
	virtual const FlatWorld::GCIdType ComponentId() const { return FlatWorld::GCIdType("InputPlayerComponent"); };

	// InputComponent Interface
public:
	virtual void Update(float dt);

	// InputPlayerComponent Interface
public:

private:

};
