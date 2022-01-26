#ifndef CONTROLLER_H
#define CONTROLLER_H

// Requirement
// Include SDL2
#include <SDL.h>

// Macro
// Render Begin
#define BEGIN_RENDER(render) \
	SDL_RenderClear(render);

// Render End
#define END_RENDER(render) \
	SDL_RenderPresent(render);

class Controller
{
public:
	// Settings
	struct
	{
		// This variable is using for finish of looping
		bool* finish = nullptr;

		// This variable is using for limit frame
		uint16_t* fps = nullptr;
	} Settings;

	// Events variable
	struct {
		SDL_Event* data = nullptr;
		int* loop = nullptr;
	} Events;
public:
	// Loop
	// This function will break loop
	void FinishLoop();

	// Render
	// This function will clear render in window
	inline void RenderBegin(SDL_Renderer* render);

	// This function will show result in window
	inline void RenderEnd(SDL_Renderer* render);
};

#endif // CONTROLLER_H