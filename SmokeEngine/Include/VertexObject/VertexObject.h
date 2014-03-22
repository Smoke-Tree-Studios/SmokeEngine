#pragma once
#include <gles2\gl2.h>
class VertexObject
{
protected:

	GLuint* _id;
public:
	VertexObject(void);
	virtual ~VertexObject(void);

	virtual void Bind() = 0;

};
