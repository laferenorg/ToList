// Include header standard
#include <iostream>
#include <memory>

// Include header
#include "../include/Main.h"
#include "../../Core/include/Core.h"
#include "../../Core/include/Controller.h"

// Include Storage
#include <Storage.hpp>

// Include header element
#include "../../Elemets/include/Button.h"
#include "../../Elemets/include/Text.h"

// Constructor function from class Main
Main::Main(Controller* pController)
	: controller(pController) {
	// Intialize core
	this->core = new Core("Todo List", { 640, 480 },
		{ SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED }, 
		SDL_WINDOW_SHOWN);

	// Intialize stoage variable
	this->storage = new std::Storage;
}

// Start function is used for setup from class Main
void Main::Start() {
	// Add button
	Button* button = new Button(this->core, this->controller, Button::Type::DEFAULT,
		20, 20, 105, 50, 
		new Text(this->core, "Hello, World",
			{ 0, 0, 0, 0 }, 20, 20, TEXT_AUTO_SIZE, TEXT_AUTO_SIZE, 12),
		{ 45, 212, 191, 0 }, { 0, 0, 0, 0xFF }, 
		2, 2);
	this->storage->add<Button*>(button);
}

// Event function is used for handle event from class Main
void Main::Event() {
	// Handle event
	// Check
	if (*this->controller->Events.loop) {
		// Switch
		switch (this->controller->Events.data->type) {
			// If SDL Request quit
			case SDL_QUIT: {
				// Quit
				this->controller->FinishLoop();
			} break;

			// If SDL Window event
			case SDL_WINDOWEVENT: {
				// Get event
				const uint32_t DT = this->controller->Events.data->window.event;

				// Check if close request
				if (DT == SDL_WINDOWEVENT_CLOSE) {
					// Quit
					this->controller->FinishLoop();
				}
			} break;
		}
	}
}

// Update function is used for logic from class Main
void Main::Update() {
	
}

// Render function is used for rende from class Main
void Main::Render() {
	// TODO: Something to render
	// Set background
	SDL_SetRenderDrawColor(this->core->render,
		255, 255, 255, 0);

	// Begin to render
	BEGIN_RENDER(this->core->render)

		// Somthing to render
		// render button
		(*this->storage->get<Button*>(0))->Render();

		
	// End to render
	END_RENDER(this->core->render)
}