// Include standard header
#include <iostream>
#include <string>

// Include SDL2
#include <SDL.h>
#include <SDL_ttf.h>

// Include header
#include "../../Core/include/Font.h"
#include "../include/Text.h"

// Constructor function from class Text
Text::Text(Core* pCore, std::string text, SDL_Color color,
	int x, int y, int w, int h, int size, std::string font) : core(pCore) {
	// Add text
	this->elements[0].text = text;

	// Add color
	this->elements[0].color = color;

	// Add rect
	this->elements[0].rect.x = x;
	this->elements[0].rect.y = y;
	this->elements[0].rect.w = w;
	this->elements[0].rect.h = h;

	// add size
	this->elements[0].sizeFont = size;

	// Add font
	this->elements[0].font = font;

	// Copy from #0 into #1
	this->elements[1] = this->elements[0];

	// call updating
	this->Updating();

	// Check if text auto size
	// Width size
	if (w < 0) {
		// Set Width into auto
		this->elements[1].rect.w = this->elements[0].w;
	}

	// Height size
	if (h < 0) {
		// Set Height into auto
		this->elements[1].rect.h = this->elements[0].h;
	}
}

// This function will used for changed from class Text
Text::Elements* Text::Get() {
	// return ref elements id #1
	return &this->elements[1];
}

// This function will updating elements from class Text
void Text::Updating() {
	// Change font
	this->fontface = this->core->FontFamily->Get(this->elements[0].font, 
		this->elements[0].sizeFont);

	// Make text
	this->surface = TTF_RenderText_Blended(this->fontface,
		this->elements[0].text.c_str(), this->elements[0].color);

	// Change w and h
	this->elements[0].w = this->surface->w;
	this->elements[0].h = this->surface->h;

	// Copy from elements #0 into #1
	this->elements[1] = this->elements[0];

	// Destroy Texture
	SDL_DestroyTexture(this->texture);

	// Convert into texture
	this->texture = SDL_CreateTextureFromSurface(this->core->render,
		this->surface);

	// Free surface
	SDL_FreeSurface(this->surface);
}

// This function will updating if have changed from class Text
void Text::Update() {
	// Setup variable for detect haved changed
	struct {
		bool font = false; // font
		bool text = false; // text
		bool color = false; // color
		bool size = false; // size
	} changed;

	// Check if have changed
	// Rect check and update
	if (this->elements[0].rect.x != this->elements[1].rect.x ||
		this->elements[0].rect.y != this->elements[1].rect.y ||
		this->elements[0].rect.x != this->elements[1].rect.w ||
		this->elements[0].rect.y != this->elements[1].rect.h) {
		// Copy rect from #1 into #0
		this->elements[0].rect = this->elements[1].rect;
	}


	// Font check and update
	if (this->elements[0].font != this->elements[1].font) {
		// copy #1 to #0
		this->elements[0].font = this->elements[1].font;

		// Set font to true
		changed.font = true;
	}

	// Text check and update
	if (this->elements[0].text != this->elements[1].text) {
		// copy #1 to #0
		this->elements[0].text = this->elements[1].text;

		// Set text to true
		changed.text = true;
	}

	// Color check and update
	if (this->elements[0].color.r != this->elements[1].color.r ||
		this->elements[0].color.g != this->elements[1].color.g ||
		this->elements[0].color.b != this->elements[1].color.b ||
		this->elements[0].color.a != this->elements[1].color.a) {
		// copy #1 to #0
		this->elements[0].color = this->elements[1].color;

		// Set color to true
		changed.color = true;
	}

	// Size check and update
	if (this->elements[0].sizeFont != this->elements[1].sizeFont) {
		// copy #1 to #0
		this->elements[0].sizeFont = this->elements[1].sizeFont;

		// Set size to true
		changed.size = true;
	}

	// if have changed
	if (changed.color || changed.font || changed.text || changed.size) {
		// call updating
		this->Updating();
	}
}

// This function will render text from class Text
void Text::Render() {
	// Call update
	this->Update();

	// Render
	SDL_RenderCopy(this->core->render, this->texture, 
		NULL, &this->elements[0].rect);
}