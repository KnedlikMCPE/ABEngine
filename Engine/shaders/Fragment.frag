#version 330 core

in vec2 TexCoord;

layout (location = 0) out vec4 FragColor;

uniform sampler2D tex1;
uniform sampler2D tex2;

void main() {
    FragColor = mix(texture(tex1, TexCoord), texture(tex2, TexCoord), 0.2);
}