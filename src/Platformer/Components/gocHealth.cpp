#include "gocHealth.h"

#include "gctHealth.h"

void gocHealth::Reset()
{
	_health = _gctHealth->GetInitialHealth();
}

gocHealth::gocHealth(gctHealth* gct)
{
	_gctHealth = gct;
}

gocHealth::HealthValueType gocHealth::GetInitialHealth() const
{
	return _gctHealth->GetInitialHealth();
}

void gocHealth::SetInitialHealth(const HealthValueType health)
{
	_gctHealth->SetInitialHealth(health);
}
