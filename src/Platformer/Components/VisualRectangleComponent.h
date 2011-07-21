#pragma once

#include "Platformer/Components/VisualComponent.h"

class VisualRectangleComponent : public VisualComponent
{
	// GameComponent Interface
public:
	virtual const FlatWorld::GCIdType ComponentId() const { return FlatWorld::GCIdType("VisualRectangleComponent"); };

	// VisualComponent Interface
public:
	virtual void Draw() const;

	// VisualRectangleComponent Interface
public:

};

