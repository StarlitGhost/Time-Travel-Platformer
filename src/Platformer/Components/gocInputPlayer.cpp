#include "gocInputPlayer.h"

#include "FlatWorld/ComponentSystem/GameObject.h"

#include "FlatWorld/Controls/SFMLKeyboardHandler.h"
#include "FlatWorld/Controls/SFMLMouseHandler.h"
#include "FlatWorld/Utilities/MathsUtilities.h"

using namespace FlatWorld;

void gocInputPlayer::Update(float dt)
{
	const float moveSpeed = 200.f;
	Vector2f movement;
	if (SFMLKeyboardHandler::Held(sf::Keyboard::W))
		movement += Vector2f(0.f, moveSpeed);
		//GetOwner()->SendMessage(this, "force", Vector2f(0.f, 5.f));
	if (SFMLKeyboardHandler::Held(sf::Keyboard::D))
		movement += Vector2f(moveSpeed, 0.f);
		//GetOwner()->SendMessage(this, "force", Vector2f(5.f, 0.f));
	if (SFMLKeyboardHandler::Held(sf::Keyboard::S))
		movement += Vector2f(0.f, -moveSpeed);
		//GetOwner()->SendMessage(this, "force", Vector2f(0.f, -5.f));
	if (SFMLKeyboardHandler::Held(sf::Keyboard::A))
		movement += Vector2f(-moveSpeed, 0.f);
		//GetOwner()->SendMessage(this, "force", Vector2f(-5.f, 0.f));

	Transform xform = GetOwner()->GetTransform();
	Vector2f vecToMouse = SFMLMouseHandler::Position() - xform.Position;
	xform.Position += movement * dt;
	xform.Angle = MathsUtilities::radToDeg(atan2(vecToMouse.y, vecToMouse.x));
	GetOwner()->SetTransform(xform);
}
