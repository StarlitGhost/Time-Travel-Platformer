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
#include "FlatWorld/Engine.h"

#include "FlatWorld/ComponentSystem/GameObject.h"
#include "FlatWorld/ComponentSystem/GOComponent.h"

#include "FlatWorld/Controls/SFMLKeyboardHandler.h"
#include "FlatWorld/Controls/SFMLMouseHandler.h"

#include "FlatWorld/Graphics/Colour.h"
#include "FlatWorld/Graphics/IGameWindow.h"
#include "FlatWorld/Graphics/ParticleEmitter.h"

#include "FlatWorld/Maths/Vector2f.h"

#include "FlatWorld/Utilities/ColourUtilities.h"
#include "FlatWorld/Utilities/StringUtilites.h"
#include "FlatWorld/Utilities/Timer.h"

// Game Headers
#include "Components/gocVisualRectangle.h"
#include "Components/gocInputPlayer.h"

using namespace FlatWorld;

TestScreen::TestScreen(void)
{
}

TestScreen::~TestScreen(void)
{
}

void TestScreen::Update(float dt)
{
	Timer* timer = engine->GetTimer();
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
		gameObject->RemoveComponent(GOCIdType("gocVisual"));
	}
	if (SFMLKeyboardHandler::Pressed(sf::Key::X))
	{
		gameObject->AddComponent(new gocVisualRectangle());
	}

	circleMod < M_PI * 2.f ? circleMod += 5.f * dt : circleMod -= (float)M_PI * 2.f;

	line2Start = SFMLMouseHandler::Position();

	Vector2f line1 = (line1End - line1Start).Unit();
	Vector2f line2 = (line2End - line2Start).Unit();

	float line1dotline2 = line1.Dot(line2);
	float angle = acos(line1dotline2);
	angle *= 180.f/3.14159265358979323846f;
	angle = 180.f - angle;

	particleEmitter->Update(dt);

	Colour colour = Colour(.25f, .5f, 1.f, 1.f);
	float H, S, V;
	ColourUtilities::RGB2HSV(colour, H, S, V);
	colour = ColourUtilities::HSV2RGB(H, S, V);

	gameObject->Update(dt);
	
	testData = "TS: " + ToString(timer->TimeScale()) +
		" | UPS: " + ToString((int)(1.f/dt)) +
		" | DP: " + ToString(line1dotline2) +
		" | Angle: " + ToString(angle) +
		" | Particles: " + ToString(particleEmitter->Count()) +
		" | H: " + ToString(H) + " S: " + ToString(S) + " V: " + ToString(V) +
		" | R: " + ToString(colour.R()) + " G: " + ToString(colour.G()) + " B: " + ToString(colour.B());
}

void TestScreen::Draw()
{
	glColor4f(1.f,1.f,1.f,1.f);
	glPushMatrix();
	glTranslatef(10.f,(float)engine->GetGameWindow()->Height() - 10.f,0.f);
	font->Render(testData.c_str());
	glTranslatef(0.f,-15.f,0.f);
	font->Render(testInfo.c_str());
	glBindTexture(GL_TEXTURE_2D, 0);
	glPopMatrix();

	glBegin(GL_LINES);
	glVertex2f(line1Start.x,line1Start.y);
	glVertex2f(line1End.x, line1End.y);

	glVertex2f(line2Start.x,line2Start.y);
	glVertex2f(line2End.x, line2End.y);
	glEnd();

	glPushMatrix();
	glTranslatef(circleCenter.x + sin(circleMod) * 100.f, circleCenter.y + cos(circleMod) * 100.f, 0.f);
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
	glColor4fv(ColourUtilities::Invert(test).RGBA());
	glVertex2f(100.f,100.f);
	glColor4fv(ColourUtilities::Negative(test).RGBA());
	glVertex2f(50.f,150.f);
	glEnd();
	glPopMatrix();

	gocVisual* vc = gameObject->GetComponent<gocVisual>(GOCIdType("gocVisual"));
	if (vc)
	{
		vc->Draw();
	}
}

void TestScreen::Load()
{
	engine = CEngine::GetInstance();

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
	Transform xform;
	xform.Position = Vector2f(128, 128);
	xform.Angle = 32;
	xform.Scale = Vector2f(128, 64);
	gameObject->SetTransform(xform);
	GOComponent* vc = new gocVisualRectangle();
	gameObject->AddComponent(vc);
	GOComponent* ic = new gocInputPlayer();
	gameObject->AddComponent(ic);
}

void TestScreen::Unload()
{
}
