// Include standard header
#include <iostream>
#include <vector>
#include <functional>

// Include SDL2
#include <SDL.h>
#include <SDL_shape.h>

// Include header
#include "../include/Box.h"
#include "../include/Border.h"
#include "../include/Button.h"
#include "../../Core/include/Core.h"
#include "../../Core/include/Controller.h"

// Constructor function for intialize from class Button
Button::Button(Core* pCore, Controller* pController, Button::Type pType,
	int x, int y, int w, int h, Text* text,
	SDL_Color first, SDL_Color seconds,
	int shadowOffsetX, int shadowOffsetY)
	: core(pCore), controller(pController), type(pType), uText(text) {
	// Settings struct elements
	this->elements[0].x = x;
	this->elements[0].y = y;
	this->elements[0].w = w;
	this->elements[0].h = h;
	this->elements[0].shadowOffsetX = shadowOffsetX;
	this->elements[0].shadowOffsetY = shadowOffsetY;

	// Copy elements #0 into #1
	this->elements[1] = this->elements[0];

	// Settings rect button
	this->rectButton.x = this->elements[0].x;
	this->rectButton.y = this->elements[0].y;
	this->rectButton.w = this->elements[0].w;
	this->rectButton.h = this->elements[0].h;

	// Intialize box and border
	// Check if is not BORDER_TR
	if (this->type != Button::Type::BORDER_TR) {
		// Intialize box
		this->box[0] = new Box(this->core);

		// Set variable for box
		this->box[0]->Color = first;
		this->box[0]->Rect.x = x;
		this->box[0]->Rect.y = y;
		this->box[0]->Rect.w = w;
		this->box[0]->Rect.h = h;
	}

	// Check if BRUTALIST
	if (this->type == Button::Type::SHADOW) {
		// Intialize shadow
		this->box[1] = new Box(this->core
		);

		// Set variable for Shadow
		this->box[1]->Color = seconds;
		this->box[1]->Rect.x = x + shadowOffsetX;
		this->box[1]->Rect.y = y + shadowOffsetY;
		this->box[1]->Rect.w = w;
		this->box[1]->Rect.h = h;
	}

	// Check if is not brutalist
	if (this->type != Button::Type::SHADOW) {
		// Intialize border
		this->border = new Border(this->core);

		// Set variable for Border
		this->border->Color = (this->type == Button::Type::BORDER_TR) ? first : seconds;
		this->border->Rect.x = x;
		this->border->Rect.y = y;
		this->border->Rect.w = w;
		this->border->Rect.h = h;
	}
}

// This function update used for update elements from class Button
Button::Elements* Button::Get() {
	// return elements variable for change
	return &this->elements[1];
}

// This function will handle logic from class Button
void Button::Update() {
	// Setup variable for detect haved changed
	struct {
		bool x = false, y = false; // position
		bool w = false, h = false; // size
		bool offSetX = false, offSetY = false; // Offset shadow
	} changed;

	// Check if have change
	// Position Section
	// Position X
	if (this->elements[0].x != this->elements[1].x) {
		// Copy position x from #1 into #0
		this->elements[0].x = this->elements[1].x;

		// Set x changed into true
		changed.x = true;
	}

	// Position Y
	if (this->elements[0].y != this->elements[1].y) {
		// Copy position y from #1 into #0
		this->elements[0].y = this->elements[1].y;

		// Set y changed into true
		changed.y = true;
	}

	// Size Section
	// Size Width
	if (this->elements[0].w != this->elements[1].w) {
		// Copy size w from #1 into #0
		this->elements[0].w = this->elements[1].w;

		// Set w changed into true
		changed.w = true;
	}

	// Size Height
	if (this->elements[0].h != this->elements[1].h) {
		// Copy size h from #1 into #0
		this->elements[0].h = this->elements[1].h;

		// Set h changed into true
		changed.h = true;
	}

	// Offset Section
	// Offset X
	if (this->elements[0].shadowOffsetX != this->elements[1].shadowOffsetX) {
		// Copy offset shadowOffsetX from #1 into #0
		this->elements[0].shadowOffsetX = this->elements[1].shadowOffsetX;

		// Set offset x changed into true
		changed.offSetX = true;
	}

	// Offset Y
	if (this->elements[0].shadowOffsetY != this->elements[1].shadowOffsetY) {
		// Copy offset y from #1 into #0
		this->elements[0].shadowOffsetY = this->elements[1].shadowOffsetY;

		// Set offset y changed into true
		changed.offSetY = true;
	}

	// Set all elements if have changed
	// Position X, Y, OffsetX, and OffsetY
	if (changed.x || changed.y || changed.offSetX || changed.offSetY) {
		// set position
		this->box[0]->Rect.x = this->elements[0].x;
		this->box[0]->Rect.y = this->elements[0].y;

		// If Shadow
		if (this->type == Button::Type::SHADOW) {
			// Set shadow
			this->box[1]->Rect.x = this->elements[0].x + this->elements[0].shadowOffsetX;
			this->box[1]->Rect.y = this->elements[0].y + this->elements[0].shadowOffsetY;
		}

		// If using border
		if (this->type != Button::Type::SHADOW && this->type != Button::Type::DEFAULT) {
			// Set shadow
			this->border->Rect.x = this->elements[0].x;
			this->border->Rect.y = this->elements[0].y;
		}
	}

	// Size Width and Height
	if (changed.w || changed.h) {
		// set size if not border transparent
		if (this->type != Button::Type::BORDER_TR) {
			// Set size
			this->box[0]->Rect.w = this->elements[0].w;
			this->box[0]->Rect.h = this->elements[0].h;
		}

		// If using Shadow
		if (this->type == Button::Type::SHADOW) {
			// Set shadow
			this->box[1]->Rect.w = this->elements[0].w;
			this->box[1]->Rect.h = this->elements[0].h;
		}

		// If using border
		if (this->type != Button::Type::SHADOW && this->type != Button::Type::DEFAULT) {
			// Set shadow
			this->border->Rect.w = this->elements[0].w;
			this->border->Rect.h = this->elements[0].h;
		}

		// Settings rect button
		this->rectButton.w = this->elements[0].w;
		this->rectButton.h = this->elements[0].h;
	}

	// Make text into center
	// X Position
	this->uText->elements[1].rect.x = this->elements[0].x + \
		(this->elements[0].w / 2) - (this->uText->elements[0].rect.w / 2);
	
	// Y Position
	this->uText->elements[1].rect.y = this->elements[0].y + \
		(this->elements[0].h / 2) - (this->uText->elements[0].rect.h / 2);

	// Settings rect button
	this->rectButton.x = this->elements[0].x;
	this->rectButton.y = this->elements[0].y;

	// Check event
	switch (this->controller->Events.data->type) {
		// Check mouse button clicked
		case SDL_MOUSEBUTTONDOWN: {
			// Rect of mouse
			SDL_Rect rectMouse;

			// Settings size
			rectMouse.w = 2;
			rectMouse.h = 2;

			// Get position cursor
			SDL_GetMouseState(&rectMouse.x, &rectMouse.y);

			// Set position of rect
			rectMouse.x -= rectMouse.w / 2;
			rectMouse.h -= rectMouse.h / 2;

			// If mouse button left
			if (this->controller->Events.data->button.button == SDL_BUTTON_LEFT &&
				SDL_HasIntersection(&rectMouse, &this->rectButton) &&
				!this->hasClick) {
				// Set hasClick into true
				this->hasClick = true;

				// Change style
				// If style shadow
				if (this->type == Button::Type::SHADOW) {
					this->elements[1].shadowOffsetX /= 2;
					this->elements[1].shadowOffsetY /= 2;
				}

				// If style border
				if (this->type == Button::Type::BORDER_TR ||
					this->type == Button::Type::BORDER_BG ||
					this->type == Button::Type::DEFAULT) {
					this->elements[1].w -= this->elements[0].shadowOffsetX;
					this->elements[1].h -= this->elements[0].shadowOffsetY;
				}

				// Get all event
				for (auto& eventA : this->events) {
					// If Event click
					if (eventA->nameEvent == "click") {
						// Call function "callback"
						eventA->callback();
					}
				}
			}
		} break;

		// Check mouse relase
		case SDL_MOUSEBUTTONUP: {
			if (this->hasClick) {
				// Set has click into false
				this->hasClick = false;

				// Change style
				// If style shadow
				if (this->type == Button::Type::SHADOW) {
					this->elements[1].shadowOffsetX *= 2;
					this->elements[1].shadowOffsetY *= 2;
				}

				// If style border
				if (this->type == Button::Type::BORDER_TR ||
					this->type == Button::Type::BORDER_BG ||
					this->type == Button::Type::DEFAULT) {
					this->elements[1].w += this->elements[0].shadowOffsetX;
					this->elements[1].h += this->elements[0].shadowOffsetY;
				}

				// Get all event
				for (auto& eventA : this->events) {
					// If Event click
					if (eventA->nameEvent == "up") {
						// Call function "callback"
						eventA->callback();
					}
				}
			}
		} break;
	}
}

// This function used for render from class Button
void Button::Render() {
	// Call function update
	this->Update();

	// Render Shadow With Check type
	if (this->type == Button::Type::SHADOW && this->type != Button::Type::DEFAULT) {
		// render
		this->box[1]->Render();
	}

	// Render Box With Check type
	if (this->type != Button::Type::BORDER_TR) {
		// render
		this->box[0]->Render();
	}

	// Render Border With Check type
	if (this->type != Button::Type::SHADOW && this->type != Button::Type::DEFAULT) {
		// render
		this->border->Render();
	}

	// Render Text
	this->uText->Render();
}

// This function used for handle event from class Button
void Button::On(std::string nameEvent, std::function<void()> callback) {
	// setup variable button event
	Button::Event* eventCall = new Button::Event;

	// Set name
	eventCall->nameEvent = nameEvent;
	
	// Set callback
	eventCall->callback = callback;

	// Push into events
	this->events.push_back(eventCall);
}