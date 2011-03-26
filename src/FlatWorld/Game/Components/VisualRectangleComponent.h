#pragma once

#include "Game/Components/VisualComponent.h"

class VisualRectangleComponent : public VisualComponent
{
	// GameComponent Interface
public:
	virtual const GCIdType ComponentId() const { return GCIdType("VisualRectangleComponent"); };

	// VisualComponent Interface
public:
	virtual void Draw() const;

	// VisualRectangleComponent Interface
public:

};

