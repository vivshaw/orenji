#include "PluginProcessor.h"
#include "PluginEditor.h"

#include "Views/OscillatorView.h"

//==============================================================================
OrenjiAudioProcessorEditor::OrenjiAudioProcessorEditor (OrenjiAudioProcessor& p)
    : AudioProcessorEditor (&p), processor (p), osc_1_view(p, "osc1"), osc_2_view(p, "osc2"), osc_3_view(p, "osc3")
{
    setSize (900, 800);

	addAndMakeVisible(&osc_1_view);
	addAndMakeVisible(&osc_2_view);
	addAndMakeVisible(&osc_3_view);
}

OrenjiAudioProcessorEditor::~OrenjiAudioProcessorEditor()
{
}

//==============================================================================
void OrenjiAudioProcessorEditor::paint (Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (ResizableWindow::backgroundColourId));
}

void OrenjiAudioProcessorEditor::resized()
{
	auto area = getLocalBounds();

	osc_1_view.setBounds(area.removeFromLeft(300).removeFromTop(300));
	osc_2_view.setBounds(area.removeFromLeft(300).removeFromTop(300));
	osc_3_view.setBounds(area.removeFromLeft(300).removeFromTop(300));
}
