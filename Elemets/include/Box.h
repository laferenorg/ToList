#ifndef BOX_H
#define BOX_H

// Requirement
// Include SDL2
#include <SDL.h>

// Include header
#include "../../Core/include/Core.h"

class Box
{
private:
	// Setup variable core
	Core* core = nullptr;
public:
	// Setup variable for color
	SDL_Color Color = { 0, 0, 0, 0 };

	// Setup variable Rect
	SDL_Rect Rect = { 0, 0, 0, 0 };
public:
	// Constructor
	Box(Core* pCore);

	// This function used for return ref of rect
	SDL_Rect& operator->();

	// This function used for render
	void Render();
};

#endif // BOX_H