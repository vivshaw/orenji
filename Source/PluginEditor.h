/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "PluginProcessor.h"
#include "Views/OscillatorView.h"

//==============================================================================
/**
*/
class OrenjiAudioProcessorEditor  : public AudioProcessorEditor
{
public:
    OrenjiAudioProcessorEditor (OrenjiAudioProcessor&);
    ~OrenjiAudioProcessorEditor();

    //==============================================================================
    void paint (Graphics&) override;
    void resized() override;

private:
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    OrenjiAudioProcessor& processor;

	OscillatorView osc_1_view, osc_2_view, osc_3_view;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (OrenjiAudioProcessorEditor)
};
