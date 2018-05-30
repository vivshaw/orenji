#pragma once

#include <string>
#include <vector>
#include <map>

#include "../JuceLibraryCode/JuceHeader.h"

class AutoBindableListener : public AudioProcessorValueTreeState::Listener
{
public:
	AutoBindableListener() {};   // Constructor.

	virtual void receiveBoundParameters(std::map<std::string, std::string> boundParams) = 0;   // Pure virtual function.

	std::string name;
	std::vector<std::string> bindableParameters;
};