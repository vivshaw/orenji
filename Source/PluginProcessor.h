#pragma once

#include "../JuceLibraryCode/JuceHeader.h"

#include "JuceExt/JuceExt.h"

class OrenjiAudioProcessor  : public AudioProcessor
{
public:
    //==============================================================================
    OrenjiAudioProcessor();
    ~OrenjiAudioProcessor();

    //==============================================================================
    void prepareToPlay (double sampleRate, int samplesPerBlock) override;
    void releaseResources() override;

   #ifndef JucePlugin_PreferredChannelConfigurations
    bool isBusesLayoutSupported (const BusesLayout& layouts) const override;
   #endif

    void processBlock (AudioBuffer<float>&, MidiBuffer&) override;

    //==============================================================================
    AudioProcessorEditor* createEditor() override;
    bool hasEditor() const override;

    //==============================================================================
    const String getName() const override;

    bool acceptsMidi() const override;
    bool producesMidi() const override;
    bool isMidiEffect() const override;
    double getTailLengthSeconds() const override;

    //==============================================================================
    int getNumPrograms() override;
    int getCurrentProgram() override;
    void setCurrentProgram (int index) override;
    const String getProgramName (int index) override;
    void changeProgramName (int index, const String& newName) override;

    //==============================================================================
    void getStateInformation (MemoryBlock& destData) override;
    void setStateInformation (const void* data, int sizeInBytes) override;

	JuceExt::AutoBindingAPVST parameters;

private:
    //==============================================================================
	Synthesiser synth;
	IIRFilter filter_r;
	IIRFilter filter_l;
	double samples;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (OrenjiAudioProcessor)
};
