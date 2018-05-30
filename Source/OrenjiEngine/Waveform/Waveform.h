#pragma once

class Waveform
{
public:
	Waveform();
	~Waveform() = default;

	virtual float sample(double time, double frequency) = 0;

protected:
	double m_twoPi;
};