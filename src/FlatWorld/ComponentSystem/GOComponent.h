#pragma once

// Standard Headers
#include <string>

#include "typedefs.h"
#include "MessagingSystem/IMessagingSystem.h"

namespace FlatWorld
{
	// Forward Declarations
	class GameObject;

	class GOComponent : public IMessagingSystem
	{
		// GOComponent Interface
	public:
		GOComponent() : _owner(NULL) {}
		virtual ~GOComponent() {}

		virtual void Update(float /*dt*/) {}
		
		virtual void ReceiveMessage(std::string /*msg*/, void* /*data*/, unsigned int /*size*/) {}

		virtual const GOCIdType ComponentId() const = 0;
		virtual const GOCIdType FamilyId() const = 0;

		void SetOwner(GameObject* owner) { _owner = owner; }
		GameObject* GetOwner() const { return _owner; }

	private:
		GameObject* _owner;

	};
}
