#include "VertexObject\VertexBufferObjectWithSubData.h"
#include <android\log.h>
#include <string>

VertexBufferObjectWithSubData::SubData::SubData(GLfloat data[],int size,int vectorType) 
{
		_data = new GLfloat[size];
		 for(int x =0; x < size; x++)
		 {
			 _data[x] = data[x];
		 }

		 _size = size * sizeof(GLfloat);
		 _vectorType = vectorType;
}
VertexBufferObjectWithSubData::SubData::SubData(Vector2 data[],int size) 
{
		_data = new GLfloat[size* 2];
		 for(int x =0; x < size; x++)
		 {
			 _data[(x * 2)+ 0] = data[x].X;
			 _data[(x * 2)+ 1] = data[x].Y;
		 }
		 _size = size * 2* sizeof(GLfloat);
		 _vectorType = 2;
}
VertexBufferObjectWithSubData::SubData::SubData(Vector3 data[],int size)
{
		_data = new GLfloat[size* 3];
		 for(int x =0; x < size; x++)
		 {
			 _data[(x * 3)+ 0] = data[x].X;
			 _data[(x * 3)+ 1] = data[x].Y;
			 _data[(x * 3)+ 2] = data[x].Z;
		 }
		 _size = size * 3* sizeof(GLfloat);
		 _vectorType = 3;
}
VertexBufferObjectWithSubData::SubData::SubData(Vector4 data[],int size) 
{
		_data = new GLfloat[size* 4];
		 for(int x =0; x < size; x++)
		 {
			 _data[(x * 4)+ 0] = data[x].X;
			 _data[(x * 4)+ 1] = data[x].Y;
			 _data[(x * 4)+ 2] = data[x].Z;
			 _data[(x * 4)+ 3] = data[x].W;
		 }
		 _size = size * 4* sizeof(GLfloat);
		 _vectorType = 4;
	
}

VertexBufferObjectWithSubData::SubData::~SubData()
{
	delete[] _data;
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
	_data = std::vector<SubData*>();
}


VertexBufferObjectWithSubData::~VertexBufferObjectWithSubData(void)
{
	for(int i = 0; i < _data.size(); i++)
	{
		delete(_data[i]);
	}
}

void VertexBufferObjectWithSubData::IntalizeBuffer()
{

	GLsizeiptr lsize = 0;
	for(int x =0; x < _data.size(); x++)
	{
		lsize += _data[x]->GetSize();
	}
	glBindBuffer(GL_ARRAY_BUFFER,*_id);
	glBufferData(GL_ARRAY_BUFFER,lsize,NULL, GL_STATIC_DRAW );

	GLsizeiptr loffset = 0;
	for(int x =0; x < _data.size(); x++)
	{
		glBufferSubData(GL_ARRAY_BUFFER,loffset,_data[x]->GetSize(),_data[x]->GetData());
		loffset += _data[x]->GetSize();
	}
}

void VertexBufferObjectWithSubData::AddSubData(SubData* subData)
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
		glVertexAttribPointer(x,_data[x]->GetVectorType(),GL_FLOAT,GL_FALSE,0,(void*)loffset);
		loffset += _data[x]->GetSize();
	}

}