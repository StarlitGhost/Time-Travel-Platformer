#include "gocInputPlayer.h"

#include <SFML/Window.hpp>

#include "Flatworld/ComponentSystem/GameObject.h"

#include "Flatworld/Controls/SFMLKeyboardHandler.h"
#include "Flatworld/Controls/SFMLMouseHandler.h"

using namespace FlatWorld;

void gocInputPlayer::Update(float dt)
{
	if (SFMLKeyboardHandler::Held(sf::Key::A))
	{
		Transform transform = GetOwner()->GetTransform();
		transform.Position.x -= 50.f * dt;
		GetOwner()->SetTransform(transform);
	}
	else if (SFMLKeyboardHandler::Held(sf::Key::D))
	{
		Transform transform = GetOwner()->GetTransform();
		transform.Position.x += 50.f * dt;
		GetOwner()->SetTransform(transform);
	}
}
