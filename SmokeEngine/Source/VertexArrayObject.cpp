#include "VertexObject\VertexArrayObject.h"
#include <stdlib.h>

VertexArrayObject::VertexArrayObject(const GLushort data[], int size) : VertexObject()
{

	_numberOfIndecies = size;
	_data = (GLushort*)malloc(sizeof(GLushort) * size);
	for(int i = 0; i < size; i++)
	{
		_data[i] = data[i];
	}
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,*_id);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER,sizeof(GLushort) * size,_data,GL_STATIC_DRAW);
}


void VertexArrayObject::Bind()
{
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,*_id);
}

int VertexArrayObject::GetNumberOfIndecies()
{
	return _numberOfIndecies;
}

VertexArrayObject::~VertexArrayObject(void)
{
	free( _data);
}
