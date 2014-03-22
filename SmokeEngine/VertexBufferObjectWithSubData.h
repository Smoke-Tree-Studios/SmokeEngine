#pragma once
#include <gles2\gl2.h>
#include "VertexObject.h"
#include "Vector2.h"
#include "Vector3.h"
#include "Vector4.h"
#include <vector>
#include "VertexObject.h"
class VertexBufferObjectWithSubData : public VertexObject
{
public:
	class SubData
	{
		private:
			int _vectorType;
			GLfloat * _data;
			int _size;
		public:
			SubData(GLfloat data[]);
			SubData(Vector2 data[]);
			SubData(Vector3 data[]);
			SubData(Vector4 data[]);
			~SubData();

			GLfloat* GetData();

			//returns the vector type
			int GetVectorType();
			//get the number of elements
			int GetLength();
			//get the total size
			int GetSize();

	};

private:
	std::vector<SubData> _data;

public:


	VertexBufferObjectWithSubData(void);
	~VertexBufferObjectWithSubData(void);
	void AddSubData(SubData subData);
	void IntalizeBuffer();
	virtual void Bind();
};

