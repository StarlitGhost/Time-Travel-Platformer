#pragma once

#include "Platformer/Components/VisualComponent.h"

class gocVisualRectangle : public VisualComponent
{
	// GameComponent Interface
public:
	virtual const FlatWorld::GOCIdType ComponentId() const { return FlatWorld::GOCIdType("gocVisualRectangle"); };

	// VisualComponent Interface
public:
	virtual void Draw() const;

	// gocVisualRectangle Interface
public:

};

