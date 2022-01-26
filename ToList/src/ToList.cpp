// Include standard header
#include <iostream>

// Include SDL2
#include <SDL.h>
#include <SDL_ttf.h>

// Include header
#include "../../Core/include/Log.h"
#include "../../Core/include/Vital.h"

// main
auto main(int argc, const char* argv) -> decltype(0) {
	// Setup variable Log
	Log* log = new Log("main");

	// Init SDL2 { Timer, Video, Events }
	// And check intialize has been successfull
	if(SDL_Init(SDL_INIT_TIMER | SDL_INIT_VIDEO | SDL_INIT_EVENTS) != 0) {
		// Show error message
		log->Run(log->Error, std::string(SDL_GetError()));
	}
	else {
		// Show message success
		log->Run(log->Default, "SDL has been intialize");
	}

	// Intialize SDL2 TTF and check intialize has been successfull
	if (TTF_Init() == -1) {
		// Show error message
		log->Run(log->Error, std::string(TTF_GetError()));
	}
	else {
		// Show message success
		log->Run(log->Default, "TTF has been intialize");
	}

	// Setup variable vital
	Vital root = Vital();

	// Vital run
	root.Run();

	// Free
	{
		// Close TTF
		TTF_Quit();

		// Close SDL2
		SDL_Quit();

		// Show message close dependencies
		log->Run(log->Default, "Dependencies have been close");

		// Delete log
		delete log;

		// Void if argc and argv unused
		(void)argc;
		(void)argv;
	}
	return 0;
}