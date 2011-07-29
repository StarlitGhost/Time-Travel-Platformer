#include "gocHealth.h"

void gocHealth::Reset()
{
	_health = _gctHealth->GetInitialHealth();
}

gocHealth::gocHealth(gctHealth* gct)
{
	_gctHealth = gct;
}
