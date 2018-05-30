/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "PluginProcessor.h"

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

	ComboBox oscOneMenu;
	ScopedPointer<AudioProcessorValueTreeState::ComboBoxAttachment> oscOneVal;

	ComboBox oscTwoMenu;
	ScopedPointer<AudioProcessorValueTreeState::ComboBoxAttachment> oscTwoVal;

	Slider oscOneFine;
	std::unique_ptr<AudioProcessorValueTreeState::SliderAttachment> fineAttachment;

	Slider oscOneCoarse;
	std::unique_ptr<AudioProcessorValueTreeState::SliderAttachment> coarseAttachment;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (OrenjiAudioProcessorEditor)
};
