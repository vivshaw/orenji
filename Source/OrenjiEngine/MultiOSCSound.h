#pragma once

#include "../JuceLibraryCode/JuceHeader.h"

class MultiOSCSound : public SynthesiserSound
{
public:
	MultiOSCSound() {}
	bool appliesToNote(int) override { return true; }
	bool appliesToChannel(int) override { return true; }
};