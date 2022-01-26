#ifndef MAIN_H
#define MAIN_H

// Requirement
// Include header standard
#include <memory>

// Include SDL2
#include <SDL.h>

// Include Storage
#include <Storage.hpp>

// Include header
#include "../../Core/include/Core.h"
#include "../../Core/include/Controller.h"
#include "../../Core/include/Log.h"

class Main {
private:
	// Setup controller variable
	Controller* controller = nullptr;

	// Setup storage variable
	std::Storage* storage;

	// Setup log variable
	Log* log = new Log("Main");
public:
	// Setup core variable
	Core* core;
public:
	// Constructor
	Main(Controller* pController);
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

#endif // MAIN_H