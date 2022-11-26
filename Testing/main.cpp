#include "Renderer.h"

int main()
{
	Renderer* renderer = new Renderer(800, 600, "ABEngine Test");
	while (!renderer->shouldClose)
	{
		renderer->Render();
	}
	delete renderer;
}