#pragma once

namespace FlatWorld
{
	/****************************************************************************
	* 																			*
	* Screen																	*
	* 																			*
	* Abstract 'Screen' class. All Screens should derive from this,				*
	* and implement the specified functions.									*
	* 																			*
	* Written by Matthew Cox, 2009-2010											*
	* 																			*
	****************************************************************************/
	class CScreen
	{
	public:
		// Tells the objects managed by the Screen to update
		virtual void Update(float dt) = 0;
		// Tells the objects managed by the Screen to draw themselves
		virtual void Draw() = 0;
		// Loads the objects that are to be managed by the Screen, and initializes any 'global' variables used by the Screen
		virtual void Load() = 0;
		// Unloads the objects managed by the Screen
		virtual void Unload() = 0;

	};
}
