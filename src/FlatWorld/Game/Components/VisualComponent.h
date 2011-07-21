#pragma once

// Engine Headers
#include "Engine/ComponentSystem/GameComponent.h"

class VisualComponent : public GameComponent
{
	// GameComponent Interface
public:
	virtual const GCIdType FamilyId() const { return GCIdType("VisualComponent"); };

	// VisualComponent Interface
public:
	virtual void Draw() const = 0;

};
