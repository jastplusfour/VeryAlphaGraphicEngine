#version 330
																					
attribute vec3 Position;
attribute vec2 texCoord;	

varying vec2 texCoord0;																											
																					
void main() {																		
	gl_Position = vec4(Position, 1.0);
	texCoord0 = texCoord;	
}