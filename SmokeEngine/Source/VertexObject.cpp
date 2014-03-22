#include "VertexObject\VertexObject.h"

VertexObject::VertexObject(void)
{
	glGenBuffers(1,_id);
}

VertexObject::~VertexObject(void)
{
}
