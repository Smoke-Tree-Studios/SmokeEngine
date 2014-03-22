#include "Storage\VertexBufferStorage.h"

VertexBufferStorage::VertexBufferStorage(void)
{
	_vertexObjects = std::map<std::string, VertexObject*>();
}

VertexBufferStorage::~VertexBufferStorage(void)
{
	for(std::map<std::string,VertexObject*>::iterator iter = _vertexObjects.begin(); iter != _vertexObjects.end(); iter++)
	{
		delete(iter->second);
	}
}

void VertexBufferStorage::AppendVertexObject(std::string id,VertexBufferObjectWithSubData* vertexObject)
{
	_vertexObjects.insert(std::pair<std::string,VertexObject*>(id + VERTEX_BUFFER_OBJECT_WITH_SUBDATA,vertexObject));

}
void VertexBufferStorage::AppendVertexObject(std::string id,VertexArrayObject* vertexObject)
{
	_vertexObjects.insert(std::pair<std::string,VertexObject*>(id + VERTEX_ARRAY_OBJECT,vertexObject));
}

VertexBufferObjectWithSubData* VertexBufferStorage::GetVertexObjectWithSubData(std::string id)
{
	return (VertexBufferObjectWithSubData*)_vertexObjects[id+ VERTEX_BUFFER_OBJECT_WITH_SUBDATA];
}

VertexArrayObject* VertexBufferStorage::GetVertexArryObject(std::string id)
{
	return (VertexArrayObject*)_vertexObjects[id+ VERTEX_ARRAY_OBJECT];
}
	
void VertexBufferStorage::DeleteVertexObjectWithSubData(std::string id)
{
	VertexObject * lvertexObject = _vertexObjects[id+VERTEX_BUFFER_OBJECT_WITH_SUBDATA];
	_vertexObjects.erase(id);
	delete(lvertexObject);
}

void VertexBufferStorage::DeleteVertexArryObject(std::string id)
{
	VertexObject * lvertexObject = _vertexObjects[id+VERTEX_ARRAY_OBJECT];
	_vertexObjects.erase(id);
	delete(lvertexObject);
}