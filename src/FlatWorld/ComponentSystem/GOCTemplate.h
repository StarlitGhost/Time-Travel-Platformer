#pragma once

#include "ComponentSystem/GOComponent.h"
#include "ComponentSystem/typedefs.h"

namespace FlatWorld
{
	class GOCTemplate
	{
	public:
		GOCTemplate() {}
		virtual ~GOCTemplate() = 0;

		virtual const GOCIdType ComponentId() const = 0;
		virtual const GOCIdType FamilyId() const = 0;

		virtual GOComponent* MakeComponent() = 0;

	};
}
