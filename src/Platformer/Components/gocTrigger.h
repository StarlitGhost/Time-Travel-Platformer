#pragma once

// Engine Headers
#include "FlatWorld/ComponentSystem/GOComponent.h"

class gocTrigger : public FlatWorld::GOComponent
{
	// GOComponent Interface
public:
	virtual const FlatWorld::GOCIdType FamilyId() const { return FlatWorld::GOCIdType("gocTrigger"); }

	// gocTrigger Interface
public:

};
