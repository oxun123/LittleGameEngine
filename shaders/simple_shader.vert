#version 450

layout(location = 0) in vec2 position;
layout(location = 1) in vec3 color;

layout(push_constant) uniform Push {
    vec2 offset;
    vec3 color;
    mat4 transform;
} push;

void main() {
    gl_Position = push.transform * vec4(position + push.offset, 0.0, 1.0);
}