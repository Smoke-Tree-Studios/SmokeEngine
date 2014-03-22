#pragma once
#include "VertexObject\VertexObject.h"
#include "VertexObject\VertexBufferObjectWithSubData.h"
#include "VertexObject\VertexArrayObject.h"
#include <map>
#include <string>

#define VERTEX_BUFFER_OBJECT_WITH_SUBDATA "VERTEX_BUFFER_OBJECT_WITH_SUBDATA"
#define VERTEX_ARRAY_OBJECT "VERTEX_ARRAY_OBJECT"

class VertexBufferStorage
{
private:
	std::map<std::string, VertexObject*> _vertexObjects;
public:
	VertexBufferStorage(void);
	~VertexBufferStorage(void);

	void AppendVertexObject(std::string id,VertexBufferObjectWithSubData* vertexObject);
	void AppendVertexObject(std::string id,VertexArrayObject* vertexObject);

	VertexBufferObjectWithSubData* GetVertexObjectWithSubData(std::string id);
	VertexArrayObject* GetVertexArryObject(std::string id);

	
	void DeleteVertexObjectWithSubData(std::string id);
	void DeleteVertexArryObject(std::string id);
};

