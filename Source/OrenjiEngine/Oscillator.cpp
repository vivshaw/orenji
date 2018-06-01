#include "Oscillator.h"
#include "Waveform/Waveform.h"
#include "Waveform/Sine.h"
#include "Waveform/Saw.h"
#include "Waveform/Square.h"
#include "Waveform/Triangle.h"

const std::string Oscillator::WAVE = "wave";
const std::string Oscillator::FINE = "fine";
const std::string Oscillator::COARSE = "coarse";

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
	scope = oscName;
	//what parameters do Oscillators care about?
	scoped_parameters = { WAVE, FINE, COARSE };
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
	DBG(scope << " received a param change: " << parameterID);

	if (parameterID.toStdString() == parameters[WAVE])
	{
		DBG("matched: " << parameters[WAVE]);
		this->setWaveform(newValue);
	}

	if (parameterID.toStdString() == parameters[FINE])
	{
		DBG("matched: " << parameters[FINE]);
		m_fine = newValue;
	}

	if (parameterID.toStdString() == parameters[COARSE])
	{
		DBG("matched: " << parameters[COARSE]);
		m_coarse = newValue;
	}
}