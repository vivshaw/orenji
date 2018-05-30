#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "../PluginProcessor.h"
#include "DualOSCSound.h"
#include "Oscillator.h"

class DualOSCVoice : public SynthesiserVoice, public AudioProcessorValueTreeState::Listener
{
public:
	DualOSCVoice();

	bool canPlaySound(SynthesiserSound* sound) override;

	void startNote(int midiNoteNumber, float velocity,
		SynthesiserSound*, int /*currentPitchWheelPosition*/) override;

	void stopNote(float /*velocity*/, bool allowTailOff) override;

	void pitchWheelMoved(int) override {};
	void controllerMoved(int, int) override { ; }

	void renderNextBlock(AudioSampleBuffer& outputBuffer, int startSample, int numSamples) override;

	Oscillator m_OSCOne, m_OSCTwo;

private:
	void parameterChanged(const String& parameterID, float newValue) override;

	double level = 0.0, tailOff = 0.0;
	double m_time, m_deltaTime, m_frequency, m_OSCInterval;
};