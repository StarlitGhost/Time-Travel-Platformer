#pragma once

// Standard Headers
#include <string>

#include "typedefs.h"

namespace FlatWorld
{
	// Forward Declarations
	class GameObject;

	class GOComponent
	{
		// GOComponent Interface
	public:
		GOComponent() : _owner(NULL) {};
		virtual ~GOComponent() = 0 {};

		virtual void Update(float dt) {};

		virtual const GOCIdType ComponentId() const = 0;
		virtual const GOCIdType FamilyId() const = 0;

		void SetOwner(GameObject* owner) { _owner = owner; };
		GameObject* GetOwner() const { return _owner; };

	private:
		GameObject* _owner;

	};
}