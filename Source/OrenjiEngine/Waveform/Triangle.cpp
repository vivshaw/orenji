#include <cmath>

#include "Triangle.h"

float Triangle::sample(double time, double frequency)
{
	double full_period = 1.0 / frequency;
	double localTime = fmod(time, full_period);

	double pos_in_period = localTime / full_period;

	if (pos_in_period < 0.25) {
		return pos_in_period * 4;
	}
	else if (pos_in_period < 0.75) {
		return 2.0 - (pos_in_period * 4.0);
	}
	else {
		return pos_in_period * 4 - 4.0;
	}
}