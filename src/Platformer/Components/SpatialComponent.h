#pragma once

// Engine Headers
#include "Flatworld/ComponentSystem/GameComponent.h"
#include "Flatworld/Maths/Vector2f.h"

class SpatialComponent : public FlatWorld::GameComponent
{
	// GameComponent Interface
public:
	virtual const FlatWorld::GCIdType FamilyId() const { return FlatWorld::GCIdType("SpatialComponent"); };
	virtual const FlatWorld::GCIdType ComponentId() const { return FlatWorld::GCIdType("SpatialComponent"); };

	// SpatialComponent Interface
public:
	SpatialComponent(const FlatWorld::Vector2f& position, const float rotation, const FlatWorld::Vector2f& scale);

	virtual void SetPosition(const FlatWorld::Vector2f& position) { _position = position; };
	virtual const FlatWorld::Vector2f& GetPosition() const { return _position; };

	virtual void SetRotation(const float& rotation) { _rotation = rotation; };
	virtual const float& GetRotation() const { return _rotation; };

	virtual void SetScale(const FlatWorld::Vector2f& scale) { _scale = scale; };
	virtual const FlatWorld::Vector2f& GetScale() const { return _scale; };

private:
	FlatWorld::Vector2f _position;
	float _rotation;
	FlatWorld::Vector2f _scale;

};
