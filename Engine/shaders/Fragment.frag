#version 330 core

in vec2 TexCoord;

layout (location = 0) out vec4 FragColor;

uniform sampler2D tex;

void main() {
    FragColor = texture(tex, TexCoord);
}