#pragma once
#include "VertexObject\VertexObject.h"
#include "VertexObject\VertexBufferObjectWithSubData.h"
#include "VertexObject\VertexArrayObject.h"
#include <map>
#include <string>

#define VERTEX_BUFFER_OBJECT_WITH_SUBDATA "_SUBDATA"
#define VERTEX_ARRAY_OBJECT "_ARRAY_OBJECT"

/**
*vertex buffer storage is used to store buffer object. i.e(vertex array objects, vertex sub data objects)
**/
class VertexBufferStorage
{
private:
	std::map<std::string, VertexObject*> _vertexObjects;
public:
	VertexBufferStorage(void);
	~VertexBufferStorage(void);

	/**
	*appends a vertex subdata object to the map
	*
	**/
	void AppendVertexObject(std::string id,VertexBufferObjectWithSubData* vertexObject);
	
	/**
	*appends a vertex array object to the map
	**/
	void AppendVertexObject(std::string id,VertexArrayObject* vertexObject);

	VertexBufferObjectWithSubData* GetVertexObjectWithSubData(std::string id);
	VertexArrayObject* GetVertexArryObject(std::string id);

	/**
	*tells if the vertex array object with the given id exist
	**/
	bool IsVertexArrayObjectExist(std::string id);
	
	/**
	*tells if the vertex sub data object with the given id exist
	**/
	bool IsVertexObjectWithSubDataExist(std::string id);
	
	/**
	*deletes the vertex sub data object from storage
	**/
	void DeleteVertexObjectWithSubData(std::string id);
	
	/**
	*deletes the vertex array object from storage
	**/
	void DeleteVertexArryObject(std::string id);
};

