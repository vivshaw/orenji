#include <cmath>

#include "Saw.h"

float Saw::sample(double time, double frequency)
{
	double fullPeriodTime = 1.0 / frequency;
	double localTime = fmod(time, fullPeriodTime);

	return (float)((localTime / fullPeriodTime) * 2 - 1.0);
}