#pragma once

// Engine Headers
#include "Flatworld/ComponentSystem/GOComponent.h"

class VisualComponent : public FlatWorld::GOComponent
{
	// GOComponent Interface
public:
	virtual const FlatWorld::GOCIdType FamilyId() const { return FlatWorld::GOCIdType("VisualComponent"); };

	// VisualComponent Interface
public:
	virtual void Draw() const = 0;

};
