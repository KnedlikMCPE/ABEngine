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

