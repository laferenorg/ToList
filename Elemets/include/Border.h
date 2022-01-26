#ifndef BORDER_H
#define BORDER_H

// Requirement
// Include SDL2
#include <SDL.h>

// Include header
#include "../../Core/include/Core.h"

class Border
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
	Border(Core* pCore);

	// This function used for return ref of rect
	SDL_Rect& operator->();

	// This function used for render
	void Render();
};

#endif // BORDER_H