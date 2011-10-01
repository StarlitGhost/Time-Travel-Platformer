#include "screenArenaShooter.h"

/*
 * NOT a good example of a screen as we'd actually use one,
 * this screen is just a place to test things very quickly,
 * before the whole framework is implemented.
 */

// Standard Headers
#define _USE_MATH_DEFINES
#include <math.h>

// Engine Headers
#include "FlatWorld/Engine.h"

#include "FlatWorld/ComponentSystem/GameObject.h"
#include "FlatWorld/ComponentSystem/GOComponent.h"

#include "FlatWorld/Controls/SFMLKeyboardHandler.h"
#include "FlatWorld/Controls/SFMLMouseHandler.h"

#include "FlatWorld/Graphics/Colour.h"
#include "FlatWorld/Graphics/Font.h"
#include "FlatWorld/Graphics/IGameWindow.h"
#include "FlatWorld/Graphics/RenderManager.h"

#include "FlatWorld/Maths/Vector2f.h"

#include "FlatWorld/Utilities/StringUtilites.h"
#include "FlatWorld/Utilities/Timer.h"

// Game Headers
#include "Components/gocVisualRectangle.h"
#include "Components/gocInputPlayer.h"
#include "Components/gocHealth.h"
#include "Components/gocTriggerRadius.h"
#include "Components/gocPhysicsSimple.h"
#include "Components/gctTriggerRadius.h"

using namespace FlatWorld;

void screenArenaShooter::Update(float dt)
{
	Timer* timer = engine->GetTimer();

	if (SFMLKeyboardHandler::Pressed(sf::Keyboard::Escape))
		exit(0);

	if (SFMLKeyboardHandler::Pressed(sf::Keyboard::Q) || SFMLMouseHandler::WheelDown())
		timer->TimeScale(timer->TimeScale() - .1f);

	if (SFMLKeyboardHandler::Pressed(sf::Keyboard::E) || SFMLMouseHandler::WheelUp())
		timer->TimeScale(timer->TimeScale() + .1f);

	if (SFMLKeyboardHandler::Pressed(sf::Keyboard::Z))
		gameObject->RemoveComponent(GOCIdType("gocVisual"));

	if (SFMLKeyboardHandler::Pressed(sf::Keyboard::X))
		gameObject->AddComponent(new gocVisualRectangle());

	gameObject->Update(dt);

	testData = "TS: " + ToString(timer->TimeScale()) +
		" | Frame Time: " + ToString(dt * 1000.f);
}

void screenArenaShooter::Draw()
{
	RenderManager::SetColour(Colour::White());
	RenderManager::PushMatrix();
	{
		RenderManager::Translate(Vector2f(10.f, (float)engine->GetGameWindow()->Height() - 10.f));
		font->Render(testData);
		RenderManager::Translate(Vector2f(0.f, -15.f));
		font->Render(testInfo);
	}
	RenderManager::PopMatrix();

	RenderManager::SetColour(Colour::White());
	gocVisual* vc = gameObject->GetComponent<gocVisual>(GOCIdType("gocVisual"));
	if (vc)
		vc->Draw();
}

void screenArenaShooter::Load()
{
	engine = CEngine::GetInstance();

	font = new FlatWorld::Font();
	font->Size(12);

	testInfo = "q / wheel down = lower timescale, e / wheel up = raise timescale";
	testData = "";

	gameObject = new GameObject(GOIdType("Object"));
	Transform xform;
	xform.Position = Vector2f(128, 128);
	xform.Angle = 0;
	xform.Scale = Vector2f(32, 32);
	gameObject->SetTransform(xform);
	gocVisualRectangle* vc = new gocVisualRectangle();
	vc->SetTexture("playerShip.png");
	gameObject->AddComponent(vc);
	GOComponent* ic = new gocInputPlayer();
	gameObject->AddComponent(ic);
	//GOCTemplate* trigTemplate = new gctTriggerRadius();
	//GOComponent* trc = trigTemplate->MakeComponent();
	//gameObject->AddComponent(trc);
	//GOComponent* pc = new gocPhysicsSimple();
	//gameObject->AddComponent(pc);
}

void screenArenaShooter::Unload()
{
	if (gameObject)
		delete gameObject;
	if (font)
		delete font;
}
