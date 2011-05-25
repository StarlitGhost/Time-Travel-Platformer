#pragma once

// Standard Headers
#include <map>
#include <string>
#include <vector>

// Engine Headers
#include "Engine/ComponentSystem/GameComponent.h"

// Typedefs
typedef std::string GOIdType;

class GameObject
{
public:
	GameObject(const GOIdType& id);
	~GameObject(void);

	void Update(float dt);

	const GOIdType& GetId() const { return _id; };
	void SetId(const GOIdType& id) { _id = id; };

	GameComponent* GetComponent(const GCIdType& familyId);

	void AddComponent(GameComponent* component);
	void RemoveComponent(const GCIdType& familyId);

	void ClearComponents();

private:
	std::string _id;

	typedef std::map<GCIdType, GameComponent*> ComponentMap;
	ComponentMap _components;

};
