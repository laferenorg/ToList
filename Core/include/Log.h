#ifndef LOG_H
#define LOG_H

// Requirement
// Include standard header
#include <string>

class Log
{
public:
	// Enum but can be using without init
	enum Type {
		Default,
		Warning,
		Error
	};
private:
	// Setup variable
	std::string projectID;
public:
	// Constructor
	Log(std::string projectName);

	// Run
	void Run(Log::Type type, std::string logText) const;
};

#endif // LOG_H