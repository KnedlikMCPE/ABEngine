#include "Input.h"

int main()
{
	Renderer* renderer = new Renderer(800, 600, "ABEngine Test");
	while (!renderer->shouldClose)
	{
		renderer->Render();
		if (Input::IsPressed(KEY_ESCAPE, renderer))
		{
			renderer->Close();
		}
	}
	delete renderer;
}