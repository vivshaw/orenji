#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "AutoBindableListener.h"

namespace JuceExt
{
	class AutoBindingAPVST : public AudioProcessorValueTreeState
	{
	public:
		AutoBindingAPVST(AudioProcessor& processorToConnectTo, UndoManager* undoManagerToUse);
		void autobind(JuceExt::AutoBindableListener* toBind);
	};
}