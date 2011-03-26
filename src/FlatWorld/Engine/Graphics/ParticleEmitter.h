#pragma once

#include <vector>

// Forward Declarations
class Particle;

class ParticleEmitter
{
public:
    ParticleEmitter();
    ~ParticleEmitter();

    void Update(const float& dt);
    void Draw(void) const;

    void Reset(void);
    void Emit(const int& numParticles);

	int Count() const;
protected:
    std::vector<Particle*> activeParticles;
    std::vector<Particle*> inactiveParticles;
};
