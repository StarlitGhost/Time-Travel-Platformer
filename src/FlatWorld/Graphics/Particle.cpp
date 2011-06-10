#include "Particle.h"

// 3rd Party Headers
#include <SFML/Window/OpenGL.hpp>

// Engine Headers
#include "Graphics/Colour.h"
#include "Maths/Vector2f.h"
#include "Utilities/ColourUtils.h"

using namespace FlatWorld;

Particle::Particle(void)
{

}
Particle::Particle(float fadeRate, Vector2f position, Vector2f velocity, Colour colourStart, Colour colourEnd)
{
	Init(fadeRate, position, velocity, colourStart, colourEnd);
}

Particle::~Particle(void)
{
}

void Particle::Init(float fadeRate, Vector2f position, Vector2f velocity, Colour colourStart, Colour colourEnd)
{
	active = true;
	life = 1.f;
	this->fadeRate = fadeRate;
	this->position = position;
	this->velocity = velocity;
	this->colourStart = colourStart;
	colour = this->colourStart;
	this->colourEnd = colourEnd;
}


void Particle::Update(const float& dt)
{
	if (active)
	{
		life -= fadeRate * dt;
		if (life <= 0.f)
		{
			active = false;
			return;
		}
		else
		{
			position += velocity * dt;
			colour = ColourUtils::HSVLerp(colourStart, colourEnd, 1.f - life);
		}
	}
}

void Particle::Draw(void) const
{
	if (active)
	{
		glBegin(GL_QUADS);
			colour.Apply();
			glVertex2f(position.X(), position.Y() + 1.f);
			glVertex2f(position.X() - 1.f, position.Y());
			glVertex2f(position.X(), position.Y() - 1.f);
			glVertex2f(position.X() + 1.f, position.Y());
		glEnd();
	}
}

void Particle::ReInit(float fadeRate, Vector2f position, Vector2f velocity)
{
	active = true;
	life = 1.f;
	this->fadeRate = fadeRate;
	this->position = position;
	this->velocity = velocity;
	colour = colourStart;
}

bool Particle::Active(void) const
{
	return active;
}
void Particle::Active(const bool& active)
{
	this->active = active;
}