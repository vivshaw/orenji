#include <cmath>

#include "Triangle.h"

float Triangle::sample(double time, double frequency)
{
	double res = 0.0;
	double fullPeriodTime = 1.0 / frequency;
	double localTime = fmod(time, fullPeriodTime);

	double value = localTime / fullPeriodTime;

	if (value < 0.25) {
		res = value * 4;
	}
	else if (value < 0.75) {
		res = 2.0 - (value * 4.0);
	}
	else {
		res = value * 4 - 4.0;
	}

	return res;
}