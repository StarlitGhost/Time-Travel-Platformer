#pragma once

#include "Components/gocVisual.h"

class gocVisualRectangle : public gocVisual
{
	// GOComponent Interface
public:
	virtual const FlatWorld::GOCIdType ComponentId() const { return FlatWorld::GOCIdType("gocVisualRectangle"); }

	// gocVisual Interface
public:
	virtual void Draw() const;

	// gocVisualRectangle Interface
public:

};

