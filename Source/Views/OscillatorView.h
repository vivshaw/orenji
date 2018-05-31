#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include <string>

#include "../PluginProcessor.h"

//==============================================================================
/*
*/
class OscillatorView    : public Component
{
public:
    OscillatorView(OrenjiAudioProcessor& p, std::string scope);
    ~OscillatorView();

    void paint (Graphics&) override;
    void resized() override;

	std::string scope;

private:
	OrenjiAudioProcessor& processor;

	ComboBox oscOneMenu;
	std::unique_ptr<AudioProcessorValueTreeState::ComboBoxAttachment> oscOneVal;

	Slider oscOneFine;
	std::unique_ptr<AudioProcessorValueTreeState::SliderAttachment> fineAttachment;

	Slider oscOneCoarse;
	std::unique_ptr<AudioProcessorValueTreeState::SliderAttachment> coarseAttachment;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (OscillatorView)
};
