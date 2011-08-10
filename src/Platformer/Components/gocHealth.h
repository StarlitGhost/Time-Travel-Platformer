#pragma once

#include "FlatWorld/ComponentSystem/GOComponent.h"

class gctHealth;

class gocHealth : public FlatWorld::GOComponent
{
	// GOComponent Interface
public:
	virtual const FlatWorld::GOCIdType ComponentId() const { return FlatWorld::GOCIdType("gocHealth"); }
	virtual const FlatWorld::GOCIdType FamilyId() const { return FlatWorld::GOCIdType("gocHealth"); }

	// gocHealth Interface
public:
	typedef int HealthValueType;

	gocHealth(gctHealth* gct);

	HealthValueType GetInitialHealth() const;
	void SetInitialHealth(const HealthValueType health);

	HealthValueType GetHealth() const { return _health; }
	void SetHealth(const HealthValueType health) { _health = health; }

	void Reset();

private:
	gctHealth* _gctHealth;
	HealthValueType _health;

};
