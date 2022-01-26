#ifndef ROOT_H
#define ROOT_H

// Requirement
// Include header standard
#include <vector>
#include <string>

// Include header SDL2
#include <SDL.h>

// Include header
#include "Main.h"
#include "../../Core/include/Controller.h"
#include "../../Core/include/Font.h"

class Root
{
public:
	// Static struct can be using without init
	// Settings
	struct Settings
	{
		// This variable is using for finish of looping
		bool* finish = nullptr;

		// This variable is using for limit frame
		uint16_t* fps = nullptr;
	};
private:
	// Variable for event handle
	struct {
		SDL_Event events;
		int loop;
	} Events;
private:
	// Setup Settings variable
	Root::Settings settings;

	// <Main> Controller
	Controller controller;
	Main mainController = Main(&controller);
	
	// Setup font
	Font* FontApllication;
public:
	// Constructor
	Root(bool* finish, uint16_t* fps);
public:
	// Start function is used for setup
	void Start();

	// Event function is used for handle event
	void Event();

	// Update function is used for logic
	void Update();

	// Render function is used for render
	void Render();
};

#endif // ROOT_H