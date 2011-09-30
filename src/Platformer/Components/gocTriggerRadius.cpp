#include "gocTriggerRadius.h"
#include "gctTriggerRadius.h"

#include "FlatWorld/ComponentSystem/GameObject.h"
#include "FlatWorld/Maths/Vector2f.h"

using namespace FlatWorld;

gocTriggerRadius::gocTriggerRadius(gctTriggerRadius* gct)
{
	_gctTriggerRadius = gct;
}

const Vector2f& gocTriggerRadius::GetPosition() const
{
	return GetOwner()->GetTransform().Position;
}

void gocTriggerRadius::Reset()
{
	_radius = _gctTriggerRadius->GetRadius();
}
