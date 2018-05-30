#include "Oscillator.h"
#include "Waveform/Waveform.h"
#include "Waveform/Sine.h"
#include "Waveform/Saw.h"
#include "Waveform/Square.h"
#include "Waveform/Triangle.h"

Oscillator::Oscillator(std::string oscName)
{
	m_amplitude = 0.125;
	m_frequency = 440;
	m_fine = 1.0;
	m_coarse = 0.0;
	m_phase = 0.0;
	m_waveform = new Sine();


	//------ Autobind parameters --------//
	//what is our OSC called?
	name = oscName;
	//what parameters do Oscillators care about?
	bindableParameters.push_back("wave");
	bindableParameters.push_back("fine");
	bindableParameters.push_back("coarse");
}

float Oscillator::sample(double time)
{
	return m_waveform->sample((m_frequency * m_fine), time) * m_amplitude;
}

void Oscillator::tune(int midiNote)
{
	m_frequency = MidiMessage::getMidiNoteInHertz(midiNote + m_coarse);
}

void Oscillator::setWaveform(int waveform)
{
	if (waveform == 0) {
		m_waveform = new Sine();
	}

	if (waveform == 1) {
		m_waveform = new Saw();
	}

	if (waveform == 2) {
		m_waveform = new Square();
	}

	if (waveform == 3) {
		m_waveform = new Triangle();
	}
}

void Oscillator::parameterChanged(const String& parameterID, float newValue)
{
	DBG(name << " received a param change: " << parameterID);

	if (parameterID.toStdString() == m_boundParams["wave"])
	{
		DBG("matched: " << m_boundParams["wave"]);
		this->setWaveform(newValue);
	}

	if (parameterID.toStdString() == m_boundParams["fine"])
	{
		DBG("matched: " << m_boundParams["fine"]);
		m_fine = newValue;
	}

	if (parameterID.toStdString() == m_boundParams["coarse"])
	{
		DBG("matched: " << m_boundParams["coarse"]);
		m_coarse = newValue;
	}
}

void Oscillator::receiveBoundParameters(std::map<std::string, std::string> boundParams)
{
	m_boundParams = boundParams;
}