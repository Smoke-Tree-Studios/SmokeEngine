#include "VertexObject\VertexArrayObject.h"


VertexArrayObject::VertexArrayObject(GLushort data[],int size) : VertexObject()
{
	_numberOfIndecies = sizeof(data);
	glBindBuffer(GL_ARRAY_BUFFER,*_id);
	glBufferData(GL_ARRAY_BUFFER,sizeof(GLushort) *size,data,GL_STATIC_DRAW);
}


void VertexArrayObject::Bind()
{
	glBindBuffer(GL_ARRAY_BUFFER,*_id);
}

int VertexArrayObject::GetNumberOfIndecies()
{
	return _numberOfIndecies;
}

VertexArrayObject::~VertexArrayObject(void)
{
}
