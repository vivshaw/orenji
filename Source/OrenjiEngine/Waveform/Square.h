#pragma once

#include "Waveform.h"

class Square : public Waveform
{
public:
	Square() = default;
	~Square() = default;

	float sample(double time, double frequency);
};