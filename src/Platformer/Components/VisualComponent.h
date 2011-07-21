#pragma once

// Engine Headers
#include "Flatworld/ComponentSystem/GameComponent.h"

class VisualComponent : public FlatWorld::GameComponent
{
	// GameComponent Interface
public:
	virtual const FlatWorld::GCIdType FamilyId() const { return FlatWorld::GCIdType("VisualComponent"); };

	// VisualComponent Interface
public:
	virtual void Draw() const = 0;

};
