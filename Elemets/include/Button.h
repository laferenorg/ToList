#ifndef BUTTON_H
#define BUTTON_H

// Requirement
// Include standard header
#include <vector>
#include <functional>

// Include SDL2
#include <SDL.h>

// Include header
#include "../../Core/include/Core.h"
#include "../../Core/include/Controller.h"
#include "Text.h"

// Include header elemets
#include "Box.h"
#include "Border.h"

class Button
{
public:
	// Static enum for type button
	enum Type {
		SHADOW,
		DEFAULT,
		BORDER_BG,
		BORDER_TR
	};

	// Static struct for update button
	struct Elements {
		int x, y; // variable for position
		int w, h; // variable for size
		int shadowOffsetX, shadowOffsetY; // variable for offset shadow
	};

	// Static struct for event
	struct Event {
		std::string nameEvent;
		std::function<void()> callback;
	};
private:
	// Setup variable core
	Core* core = nullptr;

	// Setup variable controller
	Controller* controller = nullptr;

	// Setup variable box and border
	Box* box[2] = { nullptr, nullptr };
	Border* border = nullptr;

	// Setup variable event has been clicked
	bool hasClick = false;
public:
	// Setup variable text
	Text* uText = nullptr;
private:
	// Setup variable for type
	Button::Type type = Button::Type::DEFAULT;

	// Setup variable for elements
	Button::Elements elements[2];

	// Setup variable rect
	SDL_Rect rectButton;

	// Setup vector <Button::Event>
	std::vector<Event*> events;
private:
	// This function will handle logic
	inline void Update();
public:
	// Constructor
	Button(Core* pCore, Controller* pController, Button::Type pType, 
		int x, int y, int w, int h, Text* text,
		SDL_Color first, SDL_Color seconds = SDL_Color(),
		int shadowOffsetX = 1, int shadowOffsetY = 1);

	// This function update used for update elements
	Button::Elements* Get();

	// This function used for render
	void Render();

	// This function used for handle event
	void On(std::string nameEvent, std::function<void()> callback);
};

#endif // BUTTON_H