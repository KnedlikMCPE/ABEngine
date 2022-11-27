#include "Utils.h"
#include <fstream>
#include <sstream>

std::string ABEngine::Utils::ReadFile(std::string path)
{
	std::ifstream t(path);
	std::stringstream buffer;
	buffer << t.rdbuf();
	return buffer.str();
}

std::vector<float> ABEngine::Utils::vectorFromArray(float arrayIn[])
{
	int n = sizeof(arrayIn) / sizeof(arrayIn[0]);
	return std::vector<float>(arrayIn, arrayIn + n);
}

