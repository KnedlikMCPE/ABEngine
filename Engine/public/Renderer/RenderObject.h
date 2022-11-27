#pragma once
#include <vector>

struct RenderObject
{
	std::vector<float> vertices;
	RenderObject(std::vector<float> vertIn);
	RenderObject() {}
};
