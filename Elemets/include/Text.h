#ifndef TEXT_H
#define TEXT_H

// Requirements
// Include standard header
#include <string>

// Include SDL2
#include <SDL.h>
#include <SDL_ttf.h>

// Include header
#include "../../Core/include/Font.h"
#include "../../Core/include/Core.h"

// Setup text auto size macro
#define TEXT_AUTO_SIZE -0x01

class Text
{
public:
	// Statis struct using for if have changed
	struct Elements {
		std::string font; // font family of text
		std::string text; // text of text
		SDL_Color color; // color of text
		SDL_Rect rect; // rect of text
		int w, h; // size of text
		int sizeFont; // size of size font
	};
private:
	// Setup variable core
	Core* core = nullptr;
public:
	// Setup variable string for text
	Elements elements[2];
private:
	// Setup variable ttf font
	TTF_Font* fontface = nullptr;

	// Setup for rendering
	SDL_Surface* surface = nullptr;
	SDL_Texture* texture = nullptr;
private:
	// This function will updating if have changed
	inline void Update();

	// This function will updating elements
	inline void Updating();
public:
	// Constructor
	Text(Core* pCore, std::string text, SDL_Color color, 
		int x, int y, int w = TEXT_AUTO_SIZE, int h = TEXT_AUTO_SIZE,
		int size = 20, std::string font = "Default");
public:
	// This function will used for changed
	Text::Elements* Get();

	// This function will render text
	void Render();
};

#endif // TEXT_H