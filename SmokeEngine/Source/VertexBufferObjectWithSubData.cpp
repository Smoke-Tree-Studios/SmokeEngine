#include "VertexObject\VertexBufferObjectWithSubData.h"
#include <android\log.h>
#include <string>

VertexBufferObjectWithSubData::SubData::SubData(GLfloat data[],int size,int vectorType)
{
		 GLfloat ldata[size];
		 for(int x =0; x < size; x++)
		 {
			 ldata[x] = data[x];
		 }

		 _data = ldata;
		 _size = size;
		 _vectorType = vectorType;
}
VertexBufferObjectWithSubData::SubData::SubData(Vector2 data[],int size)
{
		 GLfloat ldata[size* 2];
		 for(int x =0; x < size; x++)
		 {
			 ldata[(x * 2)+ 0] = data[x].X;
			 ldata[(x * 2)+ 1] = data[x].Y;
		 }
		 _data = ldata;
		 _size = size * 2;
		 _vectorType = 2;
}
VertexBufferObjectWithSubData::SubData::SubData(Vector3 data[],int size)
{
		 GLfloat ldata[size * 3];
		 for(int x =0; x < size; x++)
		 {
			 ldata[(x * 3)+ 0] = data[x].X;
			 ldata[(x * 3)+ 1] = data[x].Y;
			 ldata[(x * 3)+ 2] = data[x].Z;
		 }
		 _data = ldata;
		 _size = size * 3;
		 _vectorType = 3;
}
VertexBufferObjectWithSubData::SubData::SubData(Vector4 data[],int size)
{
		 GLfloat ldata[sizeof(data) * 4];
		 for(int x =0; x < sizeof(data); x++)
		 {
			 ldata[(x * 4)+ 0] = data[x].X;
			 ldata[(x * 4)+ 1] = data[x].Y;
			 ldata[(x * 4)+ 2] = data[x].Z;
			 ldata[(x * 4)+ 3] = data[x].W;
		 }
		 _data = ldata;
		 _size = size * 4;
		 _vectorType = 4;
	
}

VertexBufferObjectWithSubData::SubData::~SubData()
{
}

int VertexBufferObjectWithSubData::SubData::GetVectorType()
{
	return _vectorType;
}

int VertexBufferObjectWithSubData::SubData::GetLength()
{
	return _size;
}

int VertexBufferObjectWithSubData::SubData::GetSize()
{
	return _size * sizeof(GLfloat);
}

GLfloat* VertexBufferObjectWithSubData::SubData::GetData()
{
	return _data;
}


VertexBufferObjectWithSubData::VertexBufferObjectWithSubData(void) : VertexObject()
{
	
	_data = std::vector<SubData>();
}


VertexBufferObjectWithSubData::~VertexBufferObjectWithSubData(void)
{
}

void VertexBufferObjectWithSubData::IntalizeBuffer()
{
	GLsizeiptr lsize = 0;
	for(int x =0; x < _data.size(); x++)
	{
		lsize += _data[x].GetSize();
	}
	glBindBuffer(GL_ARRAY_BUFFER,*_id);
	glBufferData(GL_ARRAY_BUFFER,lsize,NULL, GL_STATIC_DRAW );

	GLsizeiptr loffset = 0;
	for(int x =0; x < _data.size(); x++)
	{
		glBufferSubData(GL_ARRAY_BUFFER,loffset,_data[x].GetSize(),_data[x].GetData());
		loffset += _data[x].GetSize();
	}
}

void VertexBufferObjectWithSubData::AddSubData(SubData subData)
{
	
	_data.push_back(subData);

}


void VertexBufferObjectWithSubData::Bind()
{
	glBindBuffer(GL_ARRAY_BUFFER,*_id);
	GLsizeiptr loffset = 0;
	for(int x =0; x < _data.size(); x++)
	{
		glEnableVertexAttribArray(x);
		glVertexAttribPointer(x,_data[x].GetVectorType(),GL_FLOAT,GL_FALSE,0,(void*)loffset);
		loffset += _data[x].GetSize();
	}

}