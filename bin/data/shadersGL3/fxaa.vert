#version 150

//
// Implementation of FXAA for GLSL 1.5
// See: https://github.com/mrdoob/three.js/blob/master/examples/js/shaders/FXAAShader.js
//      https://github.com/neilmendoza/ofxPostProcessing/blob/master/src/FxaaPass.cpp
//      http://www.glge.org/demos/fxaa/
//
// Ivaylo Getov
// www.ivaylogetov.com
//


uniform mat4 modelViewProjectionMatrix;
uniform mat4 textureMatrix;

in vec4 position;
in vec2 texcoord;
in vec4 normal;
in vec4 color;

out vec2 texCoordVarying;

void main()
{
    texCoordVarying = texcoord;
	gl_Position = modelViewProjectionMatrix * position;
}