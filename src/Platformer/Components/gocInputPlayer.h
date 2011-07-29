#pragma once

#include "Platformer/Components/InputComponent.h"

class SpatialComponent;

class InputPlayerComponent : public InputComponent
{
	// GameComponent Interface
public:
	virtual const FlatWorld::GOCIdType ComponentId() const { return FlatWorld::GOCIdType("InputPlayerComponent"); };

	// InputComponent Interface
public:
	virtual void Update(float dt);

	// InputPlayerComponent Interface
public:

private:

};
