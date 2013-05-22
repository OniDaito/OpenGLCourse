#version 150
in vec3 aVertexPosition;

void main(void) {
  gl_Position = vec4(aVertexPosition, 1.0);
}

#version 150
out vec4 finalColour;
void main(void) {
 finalColour= vec4(0.0, 1.0, 1.0, 1.0);
}