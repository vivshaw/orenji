#include "PluginProcessor.h"
#include "PluginEditor.h"

#include "OrenjiEngine/DualOSCVoice.h"
#include "OrenjiEngine/DualOSCSound.h"

OrenjiAudioProcessor::OrenjiAudioProcessor()
#ifndef JucePlugin_PreferredChannelConfigurations
     : AudioProcessor (BusesProperties()
                     #if ! JucePlugin_IsMidiEffect
                      #if ! JucePlugin_IsSynth
                       .withInput  ("Input",  AudioChannelSet::stereo(), true)
                      #endif
                       .withOutput ("Output", AudioChannelSet::stereo(), true)
                     #endif
                       ),
	parameters(*this, nullptr)

#endif
{
	parameters.createAndAddParameter("osc1_wave",
		"OSC 1 Wave",
		String(),
		NormalisableRange<float>(0.0f, 3.0f, 1.0f),
		0.0f,
		nullptr,
		nullptr);

	parameters.createAndAddParameter("osc1_fine",
		"OSC 1 Fine",
		String(),
		NormalisableRange<float>(0.9f, 1.1f),
		1.0f,
		nullptr,
		nullptr);

	parameters.createAndAddParameter("osc1_coarse",
		"OSC 1 Coarse",
		String(),
		NormalisableRange<float>(-12.0f, 12.0f),
		0.0f,
		nullptr,
		nullptr);

	parameters.createAndAddParameter("osc2_wave",
		"OSC 2 Wave",
		String(),
		NormalisableRange<float>(0.0f, 3.0f, 1.0f),
		0.0f,
		nullptr,
		nullptr);

	parameters.createAndAddParameter("osc2_fine",
		"OSC 2 Fine",
		String(),
		NormalisableRange<float>(0.9f, 1.1f),
		1.0f,
		nullptr,
		nullptr);

	parameters.createAndAddParameter("osc2_coarse",
		"OSC 2 Coarse",
		String(),
		NormalisableRange<float>(-12.0f, 12.0f),
		0.0f,
		nullptr,
		nullptr);

	parameters.createAndAddParameter("osc3_wave",
		"OSC 3 Wave",
		String(),
		NormalisableRange<float>(0.0f, 3.0f, 1.0f),
		0.0f,
		nullptr,
		nullptr);

	parameters.createAndAddParameter("osc3_fine",
		"OSC 3 Fine",
		String(),
		NormalisableRange<float>(0.9f, 1.1f),
		1.0f,
		nullptr,
		nullptr);

	parameters.createAndAddParameter("osc3_coarse",
		"OSC 3 Coarse",
		String(),
		NormalisableRange<float>(-12.0f, 12.0f),
		0.0f,
		nullptr,
		nullptr);

	parameters.state = ValueTree(Identifier("DefaultParams"));

	synth.addVoice(new DualOSCVoice());
	synth.addSound(new DualOSCSound());

	DualOSCVoice* synthVoice = dynamic_cast<DualOSCVoice*> (synth.getVoice(0));

	parameters.autobind(&synthVoice->m_OSCOne);
	parameters.autobind(&synthVoice->m_OSCTwo);
	parameters.autobind(&synthVoice->m_OSCThree);
}

void OrenjiAudioProcessor::prepareToPlay(double sampleRate, int samplesPerBlock)
{
	synth.setCurrentPlaybackSampleRate(sampleRate);
}

void OrenjiAudioProcessor::processBlock(AudioBuffer<float>& buffer, MidiBuffer& midiMessages)
{
	ScopedNoDenormals noDenormals;
	auto totalNumInputChannels = getTotalNumInputChannels();
	auto totalNumOutputChannels = getTotalNumOutputChannels();

	for (auto i = totalNumInputChannels; i < totalNumOutputChannels; ++i)
		buffer.clear(i, 0, buffer.getNumSamples());

	synth.renderNextBlock(buffer, midiMessages, 0, buffer.getNumSamples());
}



// JUCE Boilerplate
//==============================================================================
OrenjiAudioProcessor::~OrenjiAudioProcessor()
{
}

const String OrenjiAudioProcessor::getName() const
{
    return JucePlugin_Name;
}

bool OrenjiAudioProcessor::acceptsMidi() const
{
   #if JucePlugin_WantsMidiInput
    return true;
   #else
    return false;
   #endif
}

bool OrenjiAudioProcessor::producesMidi() const
{
   #if JucePlugin_ProducesMidiOutput
    return true;
   #else
    return false;
   #endif
}

bool OrenjiAudioProcessor::isMidiEffect() const
{
   #if JucePlugin_IsMidiEffect
    return true;
   #else
    return false;
   #endif
}

double OrenjiAudioProcessor::getTailLengthSeconds() const
{
    return 0.0;
}

int OrenjiAudioProcessor::getNumPrograms()
{
    return 1;   // NB: some hosts don't cope very well if you tell them there are 0 programs,
                // so this should be at least 1, even if you're not really implementing programs.
}

int OrenjiAudioProcessor::getCurrentProgram()
{
    return 0;
}

void OrenjiAudioProcessor::setCurrentProgram (int index)
{
}

const String OrenjiAudioProcessor::getProgramName (int index)
{
    return {};
}

void OrenjiAudioProcessor::changeProgramName (int index, const String& newName)
{
}

void OrenjiAudioProcessor::releaseResources()
{
    // When playback stops, you can use this as an opportunity to free up any
    // spare memory, etc.
}

#ifndef JucePlugin_PreferredChannelConfigurations
bool OrenjiAudioProcessor::isBusesLayoutSupported (const BusesLayout& layouts) const
{
  #if JucePlugin_IsMidiEffect
    ignoreUnused (layouts);
    return true;
  #else
    // This is the place where you check if the layout is supported.
    // In this template code we only support mono or stereo.
    if (layouts.getMainOutputChannelSet() != AudioChannelSet::mono()
     && layouts.getMainOutputChannelSet() != AudioChannelSet::stereo())
        return false;

    // This checks if the input layout matches the output layout
   #if ! JucePlugin_IsSynth
    if (layouts.getMainOutputChannelSet() != layouts.getMainInputChannelSet())
        return false;
   #endif

    return true;
  #endif
}
#endif

//==============================================================================
bool OrenjiAudioProcessor::hasEditor() const
{
    return true; // (change this to false if you choose to not supply an editor)
}

AudioProcessorEditor* OrenjiAudioProcessor::createEditor()
{
    return new OrenjiAudioProcessorEditor (*this);
}

//==============================================================================
void OrenjiAudioProcessor::getStateInformation (MemoryBlock& destData)
{
    // You should use this method to store your parameters in the memory block.
    // You could do that either as raw data, or use the XML or ValueTree classes
    // as intermediaries to make it easy to save and load complex data.
}

void OrenjiAudioProcessor::setStateInformation (const void* data, int sizeInBytes)
{
    // You should use this method to restore your parameters from this memory block,
    // whose contents will have been created by the getStateInformation() call.
}

//==============================================================================
// This creates new instances of the plugin..
AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new OrenjiAudioProcessor();
}
