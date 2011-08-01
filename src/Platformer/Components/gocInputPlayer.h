#pragma once

#include "Components/gocInput.h"

class gocInputPlayer : public gocInput
{
	// GOComponent Interface
public:
	virtual const FlatWorld::GOCIdType ComponentId() const { return FlatWorld::GOCIdType("gocInputPlayer"); };

	// gocInput Interface
public:
	virtual void Update(float dt);

	// gocInputPlayer Interface
public:

private:

};
