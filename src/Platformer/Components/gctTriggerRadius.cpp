#include "gctTriggerRadius.h"

#include "gocTriggerRadius.h"

FlatWorld::GOComponent* gctTriggerRadius::MakeComponent()
{
	gocTriggerRadius* goc = new gocTriggerRadius(this);
	goc->Reset();
	return goc;
}
