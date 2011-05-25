#pragma once

#include "Engine/Graphics/Colour.h"
#include "Engine/Maths/Vector2f.h"

class Particle
{
public:
    Particle(void);
    Particle(float fadeRate, Vector2f position, Vector2f velocity, Colour colourStart, Colour colourEnd);
    ~Particle(void);

	void Init(float fadeRate, Vector2f position, Vector2f velocity, Colour colourStart, Colour colourEnd);

    void Update(const float& dt);
    void Draw(void) const;
    void ReInit(float fadeRate, Vector2f position, Vector2f velocity);

    bool Active(void) const;
    void Active(const bool& active);

protected:
    bool active;
    float life;
    float fadeRate;
    Vector2f position;
    Vector2f velocity;
	Colour colourStart, colourEnd, colour;

};
