#include "InputPlayerComponent.h"

#include <SFML/Window.hpp>

#include "Flatworld/ComponentSystem/GameObject.h"

#include "Flatworld/Controls/SFMLKeyboardHandler.h"
#include "Flatworld/Controls/SFMLMouseHandler.h"

#include "Components/SpatialComponent.h"

using namespace FlatWorld;

void InputPlayerComponent::Update(float dt)
{
	GameComponent* gameComponent = GetOwner()->GetComponent(GCIdType("SpatialComponent"));
	SpatialComponent* _spatialComponent = static_cast<SpatialComponent*>(gameComponent);

	if (_spatialComponent)
	{
		if (SFMLKeyboardHandler::Held(sf::Key::A))
		{
			_spatialComponent->SetPosition(Vector2f(
				_spatialComponent->GetPosition().x - (50.f * dt),
				_spatialComponent->GetPosition().y
				));
		}
		else if (SFMLKeyboardHandler::Held(sf::Key::D))
		{
			_spatialComponent->SetPosition(Vector2f(
				_spatialComponent->GetPosition().x + (50.f * dt),
				_spatialComponent->GetPosition().y
				));
		}
	}
}
