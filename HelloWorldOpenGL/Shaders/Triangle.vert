#version 450 core

layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 aColor;


out vec3 ourColor;
out vec4 ourPosition;

uniform float xOffset;

void main()
{
	 gl_Position = vec4(aPos.x , aPos.y,aPos.z+xOffset, 1.0);
	 
	 ourPosition = gl_Position;

	 ourColor = aColor;
};
