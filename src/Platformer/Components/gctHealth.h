#pragma once

#include "FlatWorld/ComponentSystem/GOCTemplate.h"

class gctHealth : public FlatWorld::GOCTemplate
{
	// GOCTemplate Interface
public:
	virtual const FlatWorld::GOCIdType& ComponentId() { return FlatWorld::GOCIdType("gocHealth"); }
	virtual const FlatWorld::GOCIdType& FamilyId() { return FlatWorld::GOCIdType("gocHealth"); }

	virtual FlatWorld::GOComponent* MakeComponent();

	// gctHealth Interface
public:
	typedef int HealthValueType;

	HealthValueType GetInitialHealth() const { return _initialHealth; }
	void SetInitialHealth(const HealthValueType initialHealth) { _initialHealth = initialHealth; }

private:
	HealthValueType _initialHealth;

};
