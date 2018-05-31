#pragma once
#include <string>
#include <vector>
#include <map>

#include "JuceHeader.h"

#include "Waveform/Waveform.h"

#include "../JuceExt/JuceExt.h"

class Oscillator : public JuceExt::AutoBindableListener
{
public:
	Oscillator(std::string oscName);
	~Oscillator() = default;

	// tune OSC to this frequence in HZ
	void tune(int midiNote);
	void setWaveform(int waveform);

	// generate one sample
	float sample(double time);

	static const std::string WAVE;
	static const std::string FINE;
	static const std::string COARSE;

private:
	void parameterChanged(const String& parameterID, float newValue) override;

	double m_amplitude, m_frequency, m_phase, m_fine, m_coarse;
	
	Waveform* m_waveform;
};