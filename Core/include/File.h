#ifndef FILE_H
#define FILE_H

// Requirements
// Include standard header
#include <string>
#include <fstream>
#include <ios>

class File {
public:
	// Static enum for type
	enum Type {
		OK,
		ERROR
	};
private:
	// Setup variable fstream
	std::fstream file;
	std::string pathfile;
public:
	// Constructor
	File(std::string pPathfile);
public:
	// This function will open file
	void Open(std::ios_base::openmode mode);

	// This function will close file
	void Close();
public:
	// This function will return ref fstream
	std::fstream& Get();
};

#endif // FILE_H