// Include standard header
#include <iostream>
#include <string>
#include <vector>

// Include SDL2
#include <SDL.h>
#include <SDL_ttf.h>

// Include header
#include "../include/Font.h"
#include "../include/File.h"

// This function used for check exist file from class Font
bool Font::Exist(std::string& path) {
	// Setup file variable
	File file = File(path);

	// Open file
	file.Open(std::ios::in | std::ios::binary);

	// Get exist
	bool isExist = file.Get().is_open();

	// Close file
	file.Close();

	// return isExist
	return isExist;
}

// This function will be adding new font face from class Font
void Font::Add(std::string name, std::string path) {
	// Check if file not exist
	if (!this->Exist(path)) {
		// Make message
		std::string message = "Name Font: " + name + " \n";
		message += "Path: " + path + " \n";
		message += "Not Found";

		// if not exist show message error
		this->log->Run(this->log->Error, message.c_str());
	}

	// Setup variable FontFace
	Font::FontFace* font = new Font::FontFace();
	
	// Setup name
	font->name = name;

	// Setup font
	font->path = path;
	font->size = 20;
	font->font = TTF_OpenFont(font->path.c_str(), font->size);

	// Add into vector
	this->fonts.push_back(font);
}

TTF_Font* Font::Get(std::string name, int size) {
	// Search font name same as parameter
	for (auto& font : this->fonts) {
		// Check
		// Changed
		if (font->size != size) {
			// Close TTF
			TTF_CloseFont(font->font);

			// Set size from font into parameter
			font->size = size;

			// Open New Font
			font->font = TTF_OpenFont(font->path.c_str(), font->size);
		}

		// Return
		if (font->name == name) {
			// if same return the font
			return font->font;
		}
	}

	// If not define
	return this->fonts[0]->font;
}

// Deconstructor from class Font
Font::~Font() {
	// Delete all font
	for (auto& font : this->fonts) {
		// Close font
		TTF_CloseFont(font->font);

		// Free font
		free(font);

		// Erase #0
		this->fonts.erase(this->fonts.begin());
	}
}