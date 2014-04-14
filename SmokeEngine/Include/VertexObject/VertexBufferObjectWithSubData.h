#pragma once
#include <gles2\gl2.h>
#include "VertexObject.h"
#include "Utility\Vector\Vector2.h"
#include "Utility\Vector\Vector3.h"
#include "Utility\Vector\Vector4.h"
#include <vector>
#include "VertexObject.h"
#include <string>
#include <android\log.h>



#define VERTEX "VERTEX"
#define NORMALS "NORMALS"
#define TEX_COORDS "TEX_COORDS"

class VertexBufferObjectWithSubData : public VertexObject
{
public:
	class SubData
	{
		private:
			int _vectorType;
			GLfloat * _data;
			GLsizeiptr _size;
			std::string _listedType;
		public:
			SubData(GLfloat data[],int size,int vectorType);
			SubData(Vector2 data[],int size);
			SubData(Vector3 data[],int size);
			SubData(Vector4 data[],int size);

			SubData(GLfloat data[],int size,int vectorType,std::string listed);
			SubData(Vector2 data[],int size,std::string listed);
			SubData(Vector3 data[],int size,std::string listed);
			SubData(Vector4 data[],int size,std::string listed);

			~SubData();

			GLfloat* GetData();

			//returns the vector type
			int GetVectorType();
			//get the total size
			GLsizeiptr GetSize();

			//allows the subdata object to have an id value attached to it
			void SetListed(std::string type);

			//get what the subdata is listed as
			std::string GetListedType();

	};

private:
	std::vector<SubData*> _data;

public:


	VertexBufferObjectWithSubData(void);
	~VertexBufferObjectWithSubData(void);
	void AddSubData(SubData* subData);
	int GetSize();
	SubData* operator [] (const int index);
	void IntalizeBuffer();
	virtual void Bind();
};

