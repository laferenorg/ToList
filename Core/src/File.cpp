// Include standard header
#include <iostream>
#include <string>
#include <fstream>
#include <ios>

// Include header
#include "../include/File.h"

// Constructor from class File
File::File(std::string pPathfile)
	: pathfile(pPathfile) {}

// This function will open file from class File
void File::Open(std::ios_base::openmode mode) {
	// open file
	this->file.open(this->pathfile, mode);
}

// This function will close file from class File
void File::Close() {
	// close file
	this->file.close();
}

// This function will return ref fstream from class File
std::fstream& File::Get() {
	// return ref file
	return this->file;
}