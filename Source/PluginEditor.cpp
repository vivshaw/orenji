/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
OrenjiAudioProcessorEditor::OrenjiAudioProcessorEditor (OrenjiAudioProcessor& p)
    : AudioProcessorEditor (&p), processor (p)
{
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    setSize (600, 300);

	oscOneMenu.addItem("Sine", 1);
	oscOneMenu.addItem("Saw", 2);
	oscOneMenu.addItem("Square", 3);
	oscOneMenu.addItem("Tri", 4);
	oscOneMenu.setJustificationType(Justification::centred);
	addAndMakeVisible(&oscOneMenu);
	oscOneVal = new AudioProcessorValueTreeState::ComboBoxAttachment(processor.parameters, "osc1_wave", oscOneMenu);

	oscTwoMenu.addItem("Sine", 1);
	oscTwoMenu.addItem("Saw", 2);
	oscTwoMenu.addItem("Square", 3);
	oscTwoMenu.addItem("Tri", 4);
	oscTwoMenu.setJustificationType(Justification::centred);
	addAndMakeVisible(&oscTwoMenu);
	oscTwoVal = new AudioProcessorValueTreeState::ComboBoxAttachment(processor.parameters, "osc2_wave", oscTwoMenu);

	addAndMakeVisible(oscOneFine);
	fineAttachment.reset(new AudioProcessorValueTreeState::SliderAttachment(processor.parameters, "osc1_fine", oscOneFine));
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
	oscOneMenu.setBounds(10, 10, getWidth() / 2 - 10, 40);
	oscTwoMenu.setBounds(getWidth() / 2, 10, getWidth() / 2 - 10, 40);
	oscOneFine.setBounds(100, 100, getWidth() / 2 - 10, 40);
}
