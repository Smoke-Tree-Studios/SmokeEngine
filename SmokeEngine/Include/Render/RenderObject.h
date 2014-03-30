#pragma once
#include <GLES2/gl2.h>
#include <GLES2/gl2ext.h>

#define DEPTH_VERTEX_SHADER  "uniform mat4 in_Transform; \n uniform mat4 in_View; \n attribute vec3 in_Vert; \n void main(void) \n { \n gl_Position = in_View * in_Transform * Vec4(in_Verts.xyz,1.0); \n }"
#define DEPTH_FRAGMENT_SHADER  "void main() \n { \n gl_FragColor(0,0,0,1); \n }"
#define DEPTH_SHADER "SMOKE_SHADER"

class Shader;
class Matrix4x4;
class SceneNode;
class RenderObject
{
protected:
	Shader * _depthShader;
public:
	Shader * mShader;

	RenderObject(SceneNode * sceneNode);
	~RenderObject(void);

	 virtual void Draw(Matrix4x4 transform, Matrix4x4 view) = 0;
	 virtual void DepthDraw(Matrix4x4 transform, Matrix4x4 view) = 0;
};

