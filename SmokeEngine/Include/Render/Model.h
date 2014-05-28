#pragma once
#include "Render\RenderObject.h"

class Matrix4x4;
class Shader;
class VertexBufferObjectWithSubData;
class VertexArrayObject;
class Source;
class SceneNode;
class Texture;
class Shader;
class Model :public RenderObject
{
private:
	VertexBufferObjectWithSubData * _vertexBufferObject;
	VertexArrayObject * _vertexArrayObject;

public:


	/**
	*objects need to be imput from the storage in sceneNode
	*these objects else will have to be destroyed manually
	**/
	Model(SceneNode* sceneNode,VertexBufferObjectWithSubData* vertexBufferObject,VertexArrayObject* vertexArrayObject,Source* vertexSource, Source* Fragmentsource);
	virtual ~Model(void);

	
	virtual void Draw(Matrix4x4 transform, Matrix4x4 view);
	virtual void DepthDraw(Matrix4x4 transform, Matrix4x4 view);
};

