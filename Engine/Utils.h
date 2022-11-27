#pragma once
#include <string>
#include <vector>

#include "Macros.h"

namespace ABEngine
{
	class AB_EXPORT Utils
	{
		static std::string ReadFile(std::string path);
		static std::vector<float> vectorFromArray(float array[]);
		static std::vector<int> vectorFromArray(int array[]);
	};
}
