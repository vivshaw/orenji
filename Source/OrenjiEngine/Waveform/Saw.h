#pragma once

#include "Waveform.h"

class Saw : public Waveform
{
public:
	Saw() = default;
	~Saw() = default;

	float sample(double time, double frequency);
};