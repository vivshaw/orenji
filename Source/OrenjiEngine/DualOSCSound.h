#pragma once

#include "../JuceLibraryCode/JuceHeader.h"

class DualOSCSound : public SynthesiserSound
{
public:
	DualOSCSound() {}
	bool appliesToNote(int) override { return true; }
	bool appliesToChannel(int) override { return true; }
};