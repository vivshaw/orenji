#include <cmath>

#include "Square.h"

float Square::sample(double time, double frequency)
{
	double full_period = 1.0 / frequency;
	double local_time = fmod(time, full_period);

	return (local_time < full_period / 2) ? 1.0 : -1.0;
}