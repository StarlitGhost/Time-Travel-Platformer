#include "Particle.h"

// 3rd Party Headers
#include <SFML/OpenGL.hpp>

// Engine Headers
#include "Graphics/Colour.h"
#include "Graphics/RenderManager.h"
#include "Maths/Transform.h"
#include "Maths/Vector2f.h"
#include "Utilities/ColourUtilities.h"

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
	this->xform.Position = position;
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
			xform.Position += velocity * dt;
			colour = ColourUtilities::HSVLerp(colourStart, colourEnd, 1.f - life);
		}
	}
}

void Particle::Draw(void) const
{
	if (active)
	{
		RenderManager::PushMatrix();
		{
			RenderManager::ApplyTexture(0);
			RenderManager::SetColour(colour);
			RenderManager::Transform(xform);
			RenderManager::DrawQuad();
		}
		RenderManager::PopMatrix();
	}
}

void Particle::ReInit(float fadeRate, Vector2f position, Vector2f velocity)
{
	active = true;
	life = 1.f;
	this->fadeRate = fadeRate;
	this->xform.Position = position;
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