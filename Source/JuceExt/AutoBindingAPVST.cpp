#include <string>
#include <map>
#include <vector>

#include "AutoBindingAPVST.h"

JuceExt::AutoBindingAPVST::AutoBindingAPVST(AudioProcessor& processorToConnectTo, UndoManager* undoManagerToUse)
	: AudioProcessorValueTreeState(processorToConnectTo, undoManagerToUse)
{}

void JuceExt::AutoBindingAPVST::autobind(JuceExt::AutoBindableListener* toBind)
{
	DBG("autobinding " << toBind->scope);

	std::map<std::string, std::string> bound_params;

	for (const std::string& param_to_bind : toBind->scoped_parameters)
	{
		DBG("binding " << param_to_bind << " to " << toBind->scope);

		std::string bound_param = toBind->scope + "_" + param_to_bind;
		bound_params.insert({ param_to_bind, bound_param });
		DBG("bound! " << bound_param);

		addParameterListener(bound_param, toBind);
	}

	toBind->receiveBoundParameters(bound_params);
}