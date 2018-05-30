#include "DualOSCVoice.h"

DualOSCVoice::DualOSCVoice() : m_OSCOne("osc1"), m_OSCTwo("osc2")
{
	m_time = 0.0;
	m_deltaTime = 0.0;

	m_OSCInterval = 1.5;
};

bool DualOSCVoice::canPlaySound(SynthesiserSound* sound)
{
	return dynamic_cast<DualOSCSound*> (sound) != nullptr;
}

void DualOSCVoice::startNote(int midiNoteNumber, float velocity,
	SynthesiserSound*, int /*currentPitchWheelPosition*/)
{
	level = velocity * 0.15;
	tailOff = 0.0;

	m_frequency = MidiMessage::getMidiNoteInHertz(midiNoteNumber);
	m_deltaTime = 1 / getSampleRate();

	m_OSCOne.tune(m_frequency);
	m_OSCTwo.tune(m_frequency * m_OSCInterval);
}

void DualOSCVoice::stopNote(float /*velocity*/, bool allowTailOff)
{
	if (allowTailOff)
	{
		if (tailOff == 0.0)
			tailOff = 1.0;
	}
	else
	{
		clearCurrentNote();
		m_deltaTime = 0.0;
	}
}

void DualOSCVoice::parameterChanged(const String& parameterID, float newValue)
{
	DBG("Changed a parameter!");
	DBG(parameterID);
	
	if (parameterID == "osc1wave")
	{
		m_OSCOne.setWaveform(newValue);
	}

	if (parameterID == "osc2wave")
	{
		m_OSCTwo.setWaveform(newValue);
	}
}

void DualOSCVoice::renderNextBlock(AudioSampleBuffer& outputBuffer, int startSample, int numSamples)
{
	if (m_time >= std::numeric_limits<double>::max())
	{
		m_time = 0.0;
	}

	if (m_deltaTime != 0.0) {
		if (tailOff > 0.0) // [7]
		{
			while (--numSamples >= 0)
			{
				auto currentSample = (float)((m_OSCOne.sample(m_time) + m_OSCTwo.sample(m_time)) * tailOff);

				for (auto i = outputBuffer.getNumChannels(); --i >= 0;)
					outputBuffer.addSample(i, startSample, currentSample);

				m_time += m_deltaTime;
				++startSample;

				tailOff *= 0.99; // [8]

				if (tailOff <= 0.005)
				{
					clearCurrentNote(); // [9]
					m_deltaTime = 0.0;
					break;
				}
			}
		}
		else
		{
			while (--numSamples >= 0) // [6]
			{
				auto currentSample = (float)(m_OSCOne.sample(m_time) + m_OSCTwo.sample(m_time));

				for (auto i = outputBuffer.getNumChannels(); --i >= 0;)
					outputBuffer.addSample(i, startSample, currentSample);

				m_time += m_deltaTime;
				++startSample;
			}
		}
	}
}