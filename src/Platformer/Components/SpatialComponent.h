#pragma once

// Engine Headers
#include "Engine/ComponentSystem/GameComponent.h"
#include "Engine/Maths/Vector2f.h"

class SpatialComponent : public GameComponent
{
	// GameComponent Interface
public:
	virtual const GCIdType FamilyId() const { return GCIdType("SpatialComponent"); };
	virtual const GCIdType ComponentId() const { return GCIdType("SpatialComponent"); };

	// SpatialComponent Interface
public:
	SpatialComponent(const Vector2f& position, const float rotation, const Vector2f& scale);

	virtual void SetPosition(const Vector2f& position) { _position = position; };
	virtual const Vector2f& GetPosition() const { return _position; };

	virtual void SetRotation(const float& rotation) { _rotation = rotation; };
	virtual const float& GetRotation() const { return _rotation; };

	virtual void SetScale(const Vector2f& scale) { _scale = scale; };
	virtual const Vector2f& GetScale() const { return _scale; };

private:
	Vector2f _position;
	float _rotation;
	Vector2f _scale;

};
