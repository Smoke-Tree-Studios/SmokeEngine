#pragma once
#include "VertexObject.h"
#include <gles2\gl2.h>

class VertexArrayObject : public VertexObject
{
private:
	int _numberOfIndecies;

public:

	VertexArrayObject(GLushort data[]);
	VertexArrayObject(GLuint data[]);
	~VertexArrayObject(void);

	//binders the vertex array Object
	 virtual void Bind();
	 //returns the number of indecies
	 int GetNumberOfIndecies();
};

