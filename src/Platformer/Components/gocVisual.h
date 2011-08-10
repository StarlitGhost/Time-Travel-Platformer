#pragma once

// Engine Headers
#include "FlatWorld/ComponentSystem/GOComponent.h"

class gocVisual : public FlatWorld::GOComponent
{
	// GOComponent Interface
public:
	virtual const FlatWorld::GOCIdType FamilyId() const { return FlatWorld::GOCIdType("VisualComponent"); };

	// gocVisual Interface
public:
	virtual void Draw() const = 0;

};
