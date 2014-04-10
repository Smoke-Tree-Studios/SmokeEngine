#pragma once
#include "VertexObject.h"
#include <gles2\gl2.h>

class VertexArrayObject : public VertexObject
{
private:
	int _numberOfIndecies;
	GLushort * _data;
public:

	/**
	*declares a vertex array of indecies
	*
	**/
	VertexArrayObject(const GLushort data[], int size) ;
	~VertexArrayObject(void);

	/**
	*binders the vertex array Object
	**/
	virtual void Bind();

	/**
	*returns the number of indecies
	**/
	int GetNumberOfIndecies();
};

