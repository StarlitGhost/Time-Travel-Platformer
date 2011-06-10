#include "ParticleEmitter.h"

// Engine Headers
#include "Graphics/Colour.h"
#include "Graphics/Particle.h"
#include "Maths/Vector2f.h"

using namespace FlatWorld;

ParticleEmitter::ParticleEmitter()
{
	//ctor
}

ParticleEmitter::~ParticleEmitter()
{
	//dtor
}

void ParticleEmitter::Update(const float& dt)
{
	for (int i = activeParticles.size() - 1; i > 0; --i)
	{
		activeParticles[i]->Update(dt);
		if (!activeParticles[i]->Active())
		{
			inactiveParticles.push_back(activeParticles[i]);
			activeParticles.erase(activeParticles.begin()+i);
		}
	}
}

void ParticleEmitter::Draw(void) const
{
	for (int i = activeParticles.size() - 1; i > 0; --i)
	{
		activeParticles[i]->Draw();
	}
}

// Stuff in here should be gotten rid of or parameterized, it's purely for testing purposes.
void ParticleEmitter::Emit(const int& numParticles)
{
	for (int i = 0; i < numParticles; ++i)
	{
		float randXVel = (float)((rand()%31) - 15);
		float randYVel = (float)((rand()%16) + 15);
		if (inactiveParticles.size() > 0)
		{
			activeParticles.push_back(inactiveParticles.back());
			inactiveParticles.pop_back();
			activeParticles.back()->ReInit(0.1f, Vector2f(), Vector2f(randXVel, randYVel));
		}
		else
		{
			activeParticles.push_back(new Particle(.1f, Vector2f(), Vector2f(randXVel, randYVel), Colour(.01f,1.f,.01f,1.f), Colour(1.f,.01f,.01f,0.f)));
		}
	}
}

int ParticleEmitter::Count() const
{
	return activeParticles.size();
}
