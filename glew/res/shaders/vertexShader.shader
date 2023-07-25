#version 330 core

layout (location = 0) in vec4 position;

uniform float xOffset;

void main(){
    gl_Position = vec4(position.x+xOffset,position.y,position.z,position.w);
};
