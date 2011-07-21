#include "TestScreen.h"

/*
 * NOT a good example of a screen as we'd actually use one,
 * this screen is just a place to test things very quickly,
 * before the whole framework is implemented.
 */

// Standard Headers
#define _USE_MATH_DEFINES
#include <math.h>

// 3rd Party Headers
#include <SFML/Window.hpp>
#define FTGL_LIBRARY_STATIC
#include <FTGL/ftgl.h>

// Engine Headers
#include "Engine/Engine.h"

#include "Engine/ComponentSystem/GameObject.h"
#include "Engine/ComponentSystem/GameComponent.h"

#include "Engine/Controls/SFMLKeyboardHandler.h"
#include "Engine/Controls/SFMLMouseHandler.h"

#include "Engine/Core/SFMLTimer.h"

#include "Engine/Graphics/Colour.h"
#include "Engine/Graphics/GameDisplay.h"
#include "Engine/Graphics/ParticleEmitter.h"

#include "Engine/Maths/Vector2f.h"

#include "Engine/Utilities/ColourUtils.h"
#include "Engine/Utilities/StringUtils.h"

// Game Headers
#include "Game/Components/SpatialComponent.h"
#include "Game/Components/VisualRectangleComponent.h"
#include "Game/Components/InputPlayerComponent.h"

TestScreen::TestScreen(void)
{
}

TestScreen::~TestScreen(void)
{
}

void TestScreen::Update(float dt)
{
	CSFMLTimer* timer = CEngine::GetInstance()->Timer();
	if (SFMLKeyboardHandler::Pressed(sf::Key::Escape))
	{
		exit(0);
	}
	if (SFMLKeyboardHandler::Pressed(sf::Key::Q) || SFMLMouseHandler::WheelDown())
	{
		timer->TimeScale(timer->TimeScale() - .1f);
	}
	if (SFMLKeyboardHandler::Pressed(sf::Key::E) || SFMLMouseHandler::WheelUp())
	{
		timer->TimeScale(timer->TimeScale() + .1f);
	}
	if (SFMLKeyboardHandler::Held(sf::Key::Space))
	{
		particleEmitter->Emit(1);
	}
	if (SFMLKeyboardHandler::Pressed(sf::Key::Z))
	{
		gameObject->RemoveComponent(GCIdType("VisualComponent"));
	}
	if (SFMLKeyboardHandler::Pressed(sf::Key::X))
	{
	}

	circleMod < M_PI * 2.f ? circleMod += 5.f * dt : circleMod -= (float)M_PI * 2.f;

	line2Start = SFMLMouseHandler::Position();

	Vector2f line1 = (line1End - line1Start).normalize();
	Vector2f line2 = (line2End - line2Start).normalize();

	float line1dotline2 = line1.dot(line2);
	float angle = acos(line1dotline2);
	angle *= 180.f/3.14159265358979323846f;
	angle = 180.f - angle;

	particleEmitter->Update(dt);

	Colour colour = Colour(.25f, .5f, 1.f, 1.f);
	float H, S, V;
	ColourUtils::RGB2HSV(colour, H, S, V);
	colour = ColourUtils::HSV2RGB(H, S, V);

	gameObject->Update(dt);
	
	testData = "TS: " + StringUtils::to_string(timer->TimeScale()) +
		" | UPS: " + StringUtils::to_string((int)(1.f/dt)) +
		" | DP: " + StringUtils::to_string(line1dotline2) +
		" | Angle: " + StringUtils::to_string(angle) +
		" | Particles: " + StringUtils::to_string(particleEmitter->Count()) +
		" | H: " + StringUtils::to_string(H) + " S: " + StringUtils::to_string(S) + " V: " + StringUtils::to_string(V) +
		" | R: " + StringUtils::to_string(colour.R()) + " G: " + StringUtils::to_string(colour.G()) + " B: " + StringUtils::to_string(colour.B());
}

void TestScreen::Draw()
{
	glColor4f(1.f,1.f,1.f,1.f);
	glPushMatrix();
	glTranslatef(10.f,(float)GameDisplay::Height() - 10.f,0.f);
	font->Render(testData.c_str());
	glTranslatef(0.f,-15.f,0.f);
	font->Render(testInfo.c_str());
	glBindTexture(GL_TEXTURE_2D, 0);
	glPopMatrix();

	glBegin(GL_LINES);
	glVertex2f(line1Start.X(),line1Start.Y());
	glVertex2f(line1End.X(), line1End.Y());

	glVertex2f(line2Start.X(),line2Start.Y());
	glVertex2f(line2End.X(), line2End.Y());
	glEnd();

	glPushMatrix();
	glTranslatef(circleCenter.X() + sin(circleMod) * 100.f, circleCenter.Y() + cos(circleMod) * 100.f, 0.f);
	glBegin(GL_LINES);
	glVertex2f(-5.f, 0.f);
	glVertex2f(+5.f, 0.f);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(320.f,40.f,0.f);
	particleEmitter->Draw();
	glPopMatrix();

	glPushMatrix();
	glBegin(GL_TRIANGLES);
	glColor4f(1.f,1.f,1.f,1.f);
	glVertex2f(0.f,100.f);
	glColor4f(0.f,0.f,0.f,1.f);
	glVertex2f(0.f,0.f);
	glColor4f(0.f,0.f,1.f,1.f);
	glVertex2f(100.f,50.f);

	Colour test = Colour(.7f, 1.f, .7f, 1.f);
	glColor4fv(test.RGBA());
	glVertex2f(0.f,100.f);
	glColor4fv(ColourUtils::Invert(test).RGBA());
	glVertex2f(100.f,100.f);
	glColor4fv(ColourUtils::Negative(test).RGBA());
	glVertex2f(50.f,150.f);
	glEnd();
	glPopMatrix();

	GameComponent* gameComponent = gameObject->GetComponent(GCIdType("VisualComponent"));
	VisualComponent* visualComponent = static_cast<VisualComponent*>(gameComponent);
	if (visualComponent)
	{
		visualComponent->Draw();
	}
}

void TestScreen::Load()
{
	font = new FTTextureFont("C:\\Windows\\Fonts\\tahoma.ttf");
	font->FaceSize(12);
	line1Start = Vector2f(320,240);
	line1End = Vector2f(320,400);
	line2Start = Vector2f(50,240);
	line2End = Vector2f(320,240);
	testInfo = "q / wheel down = lower timescale, e / wheel up = raise timescale, space = emit particles";
	testData = "";
	circleCenter = Vector2f(320,240);
	circleMod = 0.f;
	particleEmitter = new ParticleEmitter();

	gameObject = new GameObject(GOIdType("Object"));
	GameComponent* spatialComponent = new SpatialComponent(Vector2f(128, 128), 30, Vector2f(128, 64));
	gameObject->AddComponent(spatialComponent);
	GameComponent* visualComponent = new VisualRectangleComponent();
	gameObject->AddComponent(visualComponent);
	GameComponent* inputComponent = new InputPlayerComponent();
	gameObject->AddComponent(inputComponent);
}

void TestScreen::Unload()
{
}
