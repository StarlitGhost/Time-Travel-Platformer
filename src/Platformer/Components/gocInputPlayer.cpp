#include "gocInputPlayer.h"

#include "FlatWorld/ComponentSystem/GameObject.h"

#include "FlatWorld/Controls/SFMLKeyboardHandler.h"
#include "FlatWorld/Controls/SFMLMouseHandler.h"

using namespace FlatWorld;

void gocInputPlayer::Update(float /*dt*/)
{
	if (SFMLKeyboardHandler::Held(sf::Keyboard::A))
		GetOwner()->SendMessage(this, "turn", 0.5f);
	if (SFMLKeyboardHandler::Held(sf::Keyboard::D))
		GetOwner()->SendMessage(this, "turn", -0.5f);

	if (SFMLKeyboardHandler::Held(sf::Keyboard::W))
		GetOwner()->SendMessage(this, "accelerate", 0.5f);
	if (SFMLKeyboardHandler::Held(sf::Keyboard::S))
		GetOwner()->SendMessage(this, "accelerate", -0.5f);
}
