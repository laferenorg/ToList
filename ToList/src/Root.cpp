// Include header standard
#include <iostream>

// Include header SDL2
#include <SDL.h>

// Include header
#include "../include/Root.h"
#include "../../Core/include/Core.h"
#include "../../Core/include/Controller.h"
#include "../../Core/include/Font.h"

// Constructor function from class Root
Root::Root(bool* finish, uint16_t* fps) {
	// Set fps setting into parameter
	this->settings.fps = fps;

	// Set fps setting into parameter
	this->settings.finish = finish;

	// Intialize Font Apllication
	this->FontApllication = new Font;

	// Add Fonts
	this->FontApllication->Add("Default", "../Assets/Fonts/Default.ttf");
	this->FontApllication->Add("Segoe", "../Assets/Fonts/Segoe.ttf");
	this->FontApllication->Add("Roboto", "../Assets/Fonts/Roboto.ttf");

	// Intialize font into controller <Main>
	this->mainController.core->FontFamily = this->FontApllication;

	// Intialize <Main> Controller
	this->controller.Settings.finish = this->settings.finish;
	this->controller.Settings.fps = this->settings.fps;
	this->controller.Events.loop = &this->Events.loop;
	this->controller.Events.data = &this->Events.events;
}

// Start function used for setup from class Root
void Root::Start()
{
	// Call <Main> Controller
	this->mainController.Start();
}

// Event function used for handle event from class Root
void Root::Event()
{
	// Get event
	this->Events.loop = SDL_PollEvent(&this->Events.events);

	// Call <Main> Controller
	this->mainController.Event();
}

// Update function logic for setup from class Root
void Root::Update()
{
	// Call <Main> Controller
	this->mainController.Update();
}

// Render function render for setup from class Root
void Root::Render()
{
	// Call <Main> Controller
	this->mainController.Render();
}