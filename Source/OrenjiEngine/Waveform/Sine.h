#pragma once

#include "Waveform.h"

class Sine : public Waveform
{
public:
	Sine() = default;
	~Sine() = default;

	float sample(double time, double frequency);
};