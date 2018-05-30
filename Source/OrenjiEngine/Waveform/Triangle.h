#pragma once

#include "Waveform.h"

class Triangle : public Waveform
{
public:
	Triangle() = default;
	~Triangle() = default;

	float sample(double time, double frequency);
};