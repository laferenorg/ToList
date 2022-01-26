// Include standard header
#include <iostream>
#include <ctime>

// Include header
#include "../include/Log.h"

// LogMessage function inline
// Get Time
std::string getTime() {
	// Get current time on system
	std::time_t Time = std::time(0);

	// Time Local
	char* timeLocal = new char[26];
	ctime_s(timeLocal, 26, &Time);

	// return result
	return std::string((const char*)timeLocal);
}

// Default
inline void LogMessageDefault(const std::string& project, const std::string& msg) {
	std::cout << "|  {" << project << "} " << getTime();
	std::cout << "| \n| " << msg << "\n" << std::endl;
}

// Constructor function from class Log
Log::Log(std::string projectName) 
	: projectID(projectName) {}

// Run function from class Log
// TODO: This will be show message using rule type
void Log::Run(Log::Type type, std::string logText) const {
	// Switch type
	switch (type) {
		// Default Log
		case Log::Type::Default: {
			std::cout << "| \"" << "Default" << '"' << std::endl;
		} break;

		// Warning Log
		case Log::Type::Warning: {
			std::cout << "| \"" << "Warning" << '"' << std::endl;
		} break;

		// Error Log
		case Log::Type::Error: {
			std::cout << "| \"" << "Error" << '"' << std::endl;
		} break;
	}

	// Log
	LogMessageDefault(this->projectID, logText);
}