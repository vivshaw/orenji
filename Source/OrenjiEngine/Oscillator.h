#pragma once
#include <string>
#include <vector>
#include <map>

#include "JuceHeader.h"

#include "Waveform/Waveform.h"

#include "../Util/autoBindable.h"

class Oscillator : public AutoBindableListener
{
public:
	Oscillator(std::string oscName);
	~Oscillator() = default;

	// tune OSC to this frequence in HZ
	void tune(int midiNote);
	void setWaveform(int waveform);

	// generate one sample
	float sample(double time);

	void receiveBoundParameters(std::map<std::string, std::string> boundParams) override;

private:
	void parameterChanged(const String& parameterID, float newValue) override;

	double m_amplitude, m_frequency, m_phase, m_fine, m_coarse;

	std::map<std::string, std::string> m_boundParams;
	
	Waveform *m_waveform;
};