#include "../../JuceLibraryCode/JuceHeader.h"
#include "OscillatorView.h"

//==============================================================================
OscillatorView::OscillatorView(OrenjiAudioProcessor& p, std::string scope) : processor(p), scope(scope)
{
	oscOneMenu.addItem("Sine", 1);
	oscOneMenu.addItem("Saw", 2);
	oscOneMenu.addItem("Square", 3);
	oscOneMenu.addItem("Tri", 4);
	oscOneMenu.setJustificationType(Justification::centred);
	addAndMakeVisible(&oscOneMenu);
	oscOneVal.reset(new AudioProcessorValueTreeState::ComboBoxAttachment(processor.parameters, scope + "_wave", oscOneMenu));

	addAndMakeVisible(oscOneFine);
	fineAttachment.reset(new AudioProcessorValueTreeState::SliderAttachment(processor.parameters, scope + "_fine", oscOneFine));

	addAndMakeVisible(oscOneCoarse);
	coarseAttachment.reset(new AudioProcessorValueTreeState::SliderAttachment(processor.parameters, scope + "_coarse", oscOneCoarse));
}

OscillatorView::~OscillatorView()
{
}

void OscillatorView::paint (Graphics& g)
{
    g.fillAll (getLookAndFeel().findColour (ResizableWindow::backgroundColourId));   // clear the background

    g.setColour (Colours::grey);
    g.drawRect (getLocalBounds(), 1);   // draw an outline around the component

    g.setColour (Colours::white);
    g.setFont (14.0f);
    g.drawText ("OscillatorView", getLocalBounds(),
                Justification::centred, true);   // draw some placeholder text
}

void OscillatorView::resized()
{
	oscOneMenu.setBounds(10, 10, getWidth() - 10, 40);
	oscOneFine.setBounds(10, 100, getWidth() - 10, 40);
	oscOneCoarse.setBounds(10, 200, getWidth() - 10, 40);
}
