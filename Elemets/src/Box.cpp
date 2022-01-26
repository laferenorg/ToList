// Include SDL2
#include <SDL.h>

// Include header
#include "../include/Box.h"
#include "../../Core/include/Core.h"

// Constructor function for intialize from class Border
Box::Box(Core* pCore)
	: core(pCore) {}

// This function used for return ref of rect from class Border
SDL_Rect& Box::operator->() {
	return this->Rect;
}

// This function used for render from class Border
void Box::Render() {
	// Set render color
	SDL_SetRenderDrawColor(this->core->render,
		this->Color.r, this->Color.g,
		this->Color.b, this->Color.a);

	// Render
	SDL_RenderFillRect(this->core->render, &this->Rect);
}