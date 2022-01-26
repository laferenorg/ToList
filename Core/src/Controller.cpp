// Include SDL2
#include <SDL.h>

// Include headre
#include "../include/Controller.h"

// This function will break loop from class Controller
void Controller::FinishLoop() {
	// Make variable loop into true
	*this->Settings.finish = true;
}

// This function will clear render in 
// window from class Controller
void Controller::RenderBegin(SDL_Renderer* render) {
	// Clear render
	SDL_RenderClear(render);
}

// This function will show result in 
// window from class Controller
void Controller::RenderEnd(SDL_Renderer* render) {
	// Present render
	SDL_RenderPresent(render);
}