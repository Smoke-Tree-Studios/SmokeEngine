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
	std::string lid = id+std::string(VERTEX_BUFFER_OBJECT_WITH_SUBDATA);
	_vertexObjects.insert(std::pair<std::string,VertexObject*>(lid,vertexObject));

}
void VertexBufferStorage::AppendVertexObject(std::string id,VertexArrayObject* vertexObject)
{
	std::string lid = id+std::string(VERTEX_ARRAY_OBJECT);
	_vertexObjects.insert(std::pair<std::string,VertexObject*>(lid,vertexObject));
}

VertexBufferObjectWithSubData* VertexBufferStorage::GetVertexObjectWithSubData(std::string id)
{
	std::string lid = id+std::string(VERTEX_BUFFER_OBJECT_WITH_SUBDATA);
	return (VertexBufferObjectWithSubData*)_vertexObjects[lid];
}

VertexArrayObject* VertexBufferStorage::GetVertexArryObject(std::string id)
{
	std::string lid = id+std::string(VERTEX_ARRAY_OBJECT);
	return (VertexArrayObject*)_vertexObjects[lid];
}

bool VertexBufferStorage::IsVertexArrayObjectExist(std::string id)
{
	std::string lid = id+std::string(VERTEX_ARRAY_OBJECT);
	if(_vertexObjects.count(lid))
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool VertexBufferStorage::IsVertexObjectWithSubDataExist(std::string id)
{
	std::string lid = id+std::string(VERTEX_BUFFER_OBJECT_WITH_SUBDATA);
	if(_vertexObjects.count(lid))
	{
		return true;
	}
	else
	{
		return false;
	}
}

	
void VertexBufferStorage::DeleteVertexObjectWithSubData(std::string id)
{
	delete(_vertexObjects[id+VERTEX_BUFFER_OBJECT_WITH_SUBDATA]);
	_vertexObjects.erase(id+VERTEX_BUFFER_OBJECT_WITH_SUBDATA);
}

void VertexBufferStorage::DeleteVertexArryObject(std::string id)
{
	delete(_vertexObjects[id+VERTEX_ARRAY_OBJECT]);
	_vertexObjects.erase(id+VERTEX_ARRAY_OBJECT);

}