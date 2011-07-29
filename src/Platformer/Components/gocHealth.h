#pragma once

#include "Flatworld/ComponentSystem/GOComponent.h"
#include "gctHealth.h"

class gocHealth : public FlatWorld::GOComponent
{
	// GOComponent Interface
public:
	virtual const FlatWorld::GOCIdType FamilyId() const { return FlatWorld::GOCIdType("gocHealth"); };

	// gocHealth Interface
public:
	typedef int HealthValueType;

	gocHealth(gctHealth* gct);

	HealthValueType GetInitialHealth() const { return _gctHealth->GetInitialHealth(); }
	void SetInitialHealth(const HealthValueType health) { _gctHealth->SetInitialHealth(health); }

	HealthValueType GetHealth() const { return _health; }
	void SetHealth(const HealthValueType health) { _health = health; }

	void Reset();

private:
	gctHealth* _gctHealth;
	HealthValueType _health;

};
