#include "InputPlayerComponent.h"

#include <SFML/Window.hpp>

#include "Engine/ComponentSystem/GameObject.h"

#include "Engine/Controls/SFMLKeyboardHandler.h"
#include "Engine/Controls/SFMLMouseHandler.h"

#include "Game/Components/SpatialComponent.h"

void InputPlayerComponent::Update(float dt)
{
	GameComponent* gameComponent = GetOwner()->GetComponent(GCIdType("SpatialComponent"));
	SpatialComponent* _spatialComponent = static_cast<SpatialComponent*>(gameComponent);

	if (_spatialComponent)
	{
		if (SFMLKeyboardHandler::Held(sf::Key::A))
		{
			_spatialComponent->SetPosition(Vector2f(
				_spatialComponent->GetPosition().X() - (50.f * dt),
				_spatialComponent->GetPosition().Y()
				));
		}
		else if (SFMLKeyboardHandler::Held(sf::Key::D))
		{
			_spatialComponent->SetPosition(Vector2f(
				_spatialComponent->GetPosition().X() + (50.f * dt),
				_spatialComponent->GetPosition().Y()
				));
		}
	}
}
