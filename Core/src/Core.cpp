// Include standard header
#include <iostream>

// Include header SDL2
#include <SDL.h>

// Include header
#include "../include/Core.h"
#include "../include/Log.h"

// Constructor function from class Core
Core::Core(std::string title, Core::Size size,
	Core::Position position, uint32_t flags) {
	// Message warning to know this section
	this->log->Run(this->log->Warning, title.c_str());

	// Intialize window
	this->window = SDL_CreateWindow(title.c_str(),
		position.xpos, position.ypos,
		size.width, size.height,
		flags);

	// Intialize Render
	this->render = SDL_CreateRenderer(this->window, -1, 
		SDL_RENDERER_PRESENTVSYNC | SDL_RENDERER_ACCELERATED);

	// Check
	// Window
	if (this->window) {
		// Show message
		this->log->Run(this->log->Default, "Window has been init");
	}

	// Render
	if (this->render) {
		// Show message
		this->log->Run(this->log->Default, "Render has been init");
	}
	
	// Check window and render have error
	if (!this->window || !this->render) {
		this->error();
	}
}

// Deconstructor function from class Core
Core::~Core() {
	// Free Font
	free(this->FontFamily);

	// Destroy render
	SDL_DestroyRenderer(this->render);

	// Destroy window
	SDL_DestroyWindow(this->window);

	// Free Log
	free(this->log);
}

// Function will show error from class Core
void Core::error() const {
	// Show error
	log->Run(log->Error, std::string(SDL_GetError()));
}