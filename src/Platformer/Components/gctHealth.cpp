#include "gctHealth.h"

#include "gocHealth.h"

FlatWorld::GOComponent* gctHealth::MakeComponent()
{
	gocHealth* goc = new gocHealth(this);
	goc->Reset();
	return goc;
}
