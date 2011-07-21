#pragma once

// Standard Headers
#include <string>

namespace FlatWorld
{
	// Forward Declarations
	class GameObject;

	// Typedefs
	typedef std::string GCIdType;

	class GameComponent
	{
		// GameComponent Interface
	public:
		GameComponent() : _owner(NULL) {};
		virtual ~GameComponent() = 0 {};

		virtual void Update(float dt) {};

		virtual const GCIdType ComponentId() const = 0;
		virtual const GCIdType FamilyId() const = 0;

		void SetOwner(GameObject* owner) { _owner = owner; };
		GameObject* GetOwner() const { return _owner; };

	private:
		GameObject* _owner;

	};
}