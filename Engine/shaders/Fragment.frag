#version 330 core

layout (location = 0) out vec4 FragColor;

uniform vec3 ourColor;

void main() {
    FragColor = vec4(ourColor.xyz, 1.0);
}