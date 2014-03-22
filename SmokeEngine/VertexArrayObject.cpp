#include "VertexArrayObject.h"


VertexArrayObject::VertexArrayObject(GLushort data[]) : VertexObject()
{
	_numberOfIndecies = sizeof(data);
	glBindBuffer(GL_ARRAY_BUFFER,*_id);
	glBufferData(GL_ARRAY_BUFFER,sizeof(GLushort) * sizeof(data),data,GL_STATIC_DRAW);
}

VertexArrayObject::VertexArrayObject(GLuint data[]) : VertexObject()
{
	_numberOfIndecies = sizeof(data);
	glBindBuffer(GL_ARRAY_BUFFER,*_id);
	glBufferData(GL_ARRAY_BUFFER,sizeof(GLuint) * sizeof(data),data,GL_STATIC_DRAW);
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
