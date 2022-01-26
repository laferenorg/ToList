#ifndef FONT_H
#define FONT_H

// Requirements
// Include standard header
#include <string>
#include <vector>

// Include SDL2
#include <SDL.h>
#include <SDL_ttf.h>

// Include header
#include "Log.h"

class Font
{
public:
	// Static struct for font face
	struct FontFace {
		std::string name;
		std::string path;
		TTF_Font* font;
		int size;
	};
private:
	// Setup variable Log
	Log* log = new Log("Font");

	// Setup variable vector<Font::FontFace>
	std::vector<Font::FontFace*> fonts;
private:
	// This function used for check exist file
	inline bool Exist(std::string& path);
public:
	// This function will be adding new font face
	void Add(std::string name, std::string path);

	// This function will be giving font
	TTF_Font* Get(std::string name, int size = 20);
private:
	// Deconstructor
	~Font();
};

#endif // FONT_H