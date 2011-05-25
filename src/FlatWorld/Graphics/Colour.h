#pragma once

#include <iosfwd>

/****************************************************************************
* 																			*
* Colour																	*
* 																			*
* Holds a colour in RGBA format, and provides methods to retrieve, set and	*
* apply each component.														*
* 																			*
* Written by Matthew Cox, 2010												*
* 																			*
****************************************************************************/
class Colour
{
public:
	// Default constructor, initializes all colour components to 1.0f
	Colour(void);
	// Single-value constructor, initializes all colour components to the same value
	Colour(const float& rgba);
	// Full constructor, initializes colour components to those specified
	Colour(const float& r, const float& g, const float& b, const float& a);
	// Destructor
	~Colour(void);

	// Accessors
	const float& operator[](int i) const { return _colour[i]; }
	float& operator[](int i) { return _colour[i]; }
	// Returns the colour's red component
	float R() const {return _colour[0];};
	// Returns the colour's green component
	float G() const {return _colour[1];};
	// Returns the colour's blue component
	float B() const {return _colour[2];};
	// Returns the colour's alpha component
	float A() const {return _colour[3];};

	// Returns the rgba colour array
	const float* RGBA() const {return _colour;};

	// Sets the colour's red component
	void R(const float& r) {_colour[0] = r;};
	// Sets the colour's green component
	void G(const float& g) {_colour[1] = g;};
	// Sets the colour's blue component
	void B(const float& b) {_colour[2] = b;};
	// Sets the colour's alpha component
	void A(const float& a) {_colour[3] = a;};

	// Sets all of the colour's components
	void RBGA(const float& r, const float& g, const float& b, const float& a);

	// Calls glColor3f with the colour's components as parameters, thereby causing all subsequent drawing operations to use this colour
	void Apply() const;

	// Basic Colour Presets
	static Colour Black();
	static Colour White();
	static Colour Red();
	static Colour Green();
	static Colour Blue();
	static Colour Yellow();
	static Colour Cyan();
	static Colour Magenta();
	static Colour Null();

	/* Colour Presets derived from Colour Temperatures (Found here: http://planetpixelemporium.com/tutorialpages/light.html,
	 * and correlated with further google results for 'rgb colour temperature')
	 */
	static Colour Candle();
	static Colour Tungsten40W();
	static Colour Tungsten100W();
	static Colour Halogen();
	static Colour CarbonArc();
	static Colour HighNoonSun();
	static Colour DirectSunlight();
	static Colour OvercastSky();
	static Colour BlueSky();

protected:
	float _colour[4];

};

std::istream& operator>>(std::istream& in, Colour& c);
std::ostream& operator<<(std::ostream& out, const Colour& c);
