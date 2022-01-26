// Include SDL2
#include <SDL.h>

// Include header
#include "../include/Border.h"
#include "../../Core/include/Core.h"

// Constructor function for intialize from class Border
Border::Border(Core* pCore) 
	: core(pCore) {}

// This function used for return ref of rect from class Border
SDL_Rect& Border::operator->() {
	return this->Rect;
}

// This function used for render from class Border
void Border::Render() {
	// Set render color
	SDL_SetRenderDrawColor(this->core->render,
		this->Color.r, this->Color.g,
		this->Color.b, this->Color.a);

	// Render
	SDL_RenderDrawRect(this->core->render, &this->Rect);
}