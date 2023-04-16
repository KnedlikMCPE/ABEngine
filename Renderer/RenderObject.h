#ifndef RENDER_OBJECT_H
#define RENDER_OBJECT_H

namespace ABRenderer {
	class RenderObject {
	public:
		virtual void render();
		virtual ~RenderObject();
	};
}

#endif