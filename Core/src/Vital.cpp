// Include header standard
#include <iostream>
#include <inttypes.h>

// Include header SDL2
#include <SDL.h>

// Include header
#include "../include/Vital.h"
#include "../../ToList/include/Root.h"

// Constructor function from class Vital
Vital::Vital() {
	// Set finish variable in settings to false
	this->settings->finish = false;

	// Set frame limit per seconds into 60 (default)
	this->settings->fps = 60;
}

// Deconstructor function from class Vital
Vital::~Vital() {
	// Delete settings variable
	delete this->settings;
}

// Run function from class Vital
void Vital::Run() {
	// Setup variable
	// start ticks
	uint32_t startTicks = 0;

	// Root controller
	Root root = Root(&this->settings->finish, &this->settings->fps);

	// Before start looping call start function from root
	root.Start();

	// Start looping
	while (!this->settings->finish) {
		// Get ticks for first loop
		startTicks = SDL_GetTicks();

		// Event
		// Call event function from root
		root.Event();

		// Update
		// Call update function from root
		root.Update();

		// Render
		// Call render function from root
		root.Render();

		// Proccess frame limit
		this->FPS(startTicks, this->settings->fps);
	}
}

// FPS function is used for limit frame from class Vital
void Vital::FPS(uint32_t& ticks, uint16_t& fps) {
	// Proccess frame per seconds
	if ((1000 / fps) > (SDL_GetTicks() - ticks)) {
		SDL_Delay(1000 / fps - (SDL_GetTicks() - ticks));
	}
}