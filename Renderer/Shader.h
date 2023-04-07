#ifndef SHADER_H
#define SHADER_H

namespace ABRenderer {
	class Shader {
	public:
		Shader();
		Shader(char* vertex, char* fragment);
		void load(char* vertex, char* fragment);
		void reset();
		unsigned int program;
	private:
		unsigned int vertexShader;
		unsigned int fragmentShader;
		char* vertexCode;
		char* fragmentCode;
	};
}

#endif