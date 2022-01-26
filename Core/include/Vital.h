#ifndef VITAL_H
#define VITAL_H

// Requirement
// Include header standard
#include <inttypes.h>

// Include header SDL2
#include <SDL.h>

class Vital
{
public:
	// Static struct can be using without init
	// Settings
	struct Settings
	{
		// This variable is using for finish of looping
		bool finish;

		// This variable is using for limit frame
		uint16_t fps;
	};
public:
	// Setup settings variable
	Settings *settings = new Settings;
public:
	// Constructor
	Vital();

	// Deconstructor
	~Vital();
private:
	// This function using for limit frame
	inline void FPS(uint32_t& ticks, uint16_t& fps);
public:
	// Run function for start loop
	void Run();
};

#endif // VITAL_H