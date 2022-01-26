#ifndef CORE_H
#define CORE_H

// Requirement
// Include standard header
#include <string>
#include <inttypes.h>

// Include header SDL2
#include <SDL.h>

// Include header
#include "Log.h"
#include "Font.h"

class Core {
public:
	// Struct but can be using without init
	// Size
	struct Size {
		int width, height;
	};

	// Position
	struct Position {
		int xpos, ypos;
	};
public:
	// Setup variable requirement
	SDL_Window* window = nullptr;
	SDL_Renderer* render = nullptr;

	// Setup variable font
	Font* FontFamily = nullptr;
private:
	// Setup variable Log
	Log* log = new Log("Core");
public:
	// Constructor function
	Core(std::string title, Core::Size size, 
		Core::Position position, uint32_t flags);

	// Deconstructor function
	~Core();
public:
	// Function will show error
	void error() const;
};

#endif // CORE_H