#include <cmath>

#include "Square.h"

float Square::sample(double time, double frequency)
{
	double fullPeriodTime = 1.0 / frequency;
	double halfPeriodTime = fullPeriodTime / 2.0;
	double localTime = fmod(time, fullPeriodTime);

	return (localTime < halfPeriodTime) ? 1.0 : -1.0;
}