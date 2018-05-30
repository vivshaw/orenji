#include <cmath>

#include "Sine.h"

float Sine::sample(double time, double frequency)
{
	return (float)std::sin(m_twoPi * frequency * time);
}