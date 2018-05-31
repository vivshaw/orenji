#pragma once

#include <string>
#include <vector>
#include <map>

#include "../JuceLibraryCode/JuceHeader.h"

namespace JuceExt
{
	class AutoBindableListener : public AudioProcessorValueTreeState::Listener
	{
		public:
			AutoBindableListener() {};   // Constructor.

			void receiveBoundParameters(std::map<std::string, std::string> bound_params)
			{
				parameters = bound_params;
			};

			std::string scope;

			std::vector<std::string> scoped_parameters;
			std::vector<std::string> global_parameters;

			std::map<std::string, std::string> parameters;
	};
}