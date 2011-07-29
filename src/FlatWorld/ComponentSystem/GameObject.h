#pragma once

// Standard Headers
#include <map>
#include <string>
#include <vector>

// Engine Headers
#include "GOComponent.h"
#include "typedefs.h"
#include "Maths/Transform.h"

namespace FlatWorld
{
	class GameObject
	{
	public:
		GameObject(const GOIdType& id);
		~GameObject(void);

		void Update(float dt);

		const Transform& GetTransform() const { return _transform; }
		void SetTransform(const Transform& transform) { _transform = transform; }

		const GOIdType& GetId() const { return _id; }
		void SetId(const GOIdType& id) { _id = id; }

		GOComponent* GetComponent(const GOCIdType& familyId);

		void AddComponent(GOComponent* component);
		void RemoveComponent(const GOCIdType& familyId);

		void ClearComponents();

	private:
		Transform _transform;

		GOIdType _id;

		typedef std::map<GOCIdType, GOComponent*> ComponentMap;
		ComponentMap _components;

	};
}