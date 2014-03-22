#include "VertexBufferObjectWithSubData.h"

VertexBufferObjectWithSubData::SubData::SubData(GLfloat data[])
{
		 GLfloat ldata[sizeof(data)];
		 for(int x =0; x < sizeof(data); x++)
		 {
			 ldata[x] = data[x];
		 }
		 _data = ldata;
		 _size = sizeof(data);
}
VertexBufferObjectWithSubData::SubData::SubData(Vector2 data[])
{
		 GLfloat ldata[sizeof(data) * 2];
		 for(int x =0; x < sizeof(data); x++)
		 {
			 ldata[(x * 2)+ 0] = data[x].X;
			 ldata[(x * 2)+ 1] = data[x].Y;
		 }
		 _data = ldata;
		 _size = sizeof(data) * 2;
}
VertexBufferObjectWithSubData::SubData::SubData(Vector3 data[])
{
		 GLfloat ldata[sizeof(data) * 3];
		 for(int x =0; x < sizeof(data); x++)
		 {
			 ldata[(x * 3)+ 0] = data[x].X;
			 ldata[(x * 3)+ 1] = data[x].Y;
			 ldata[(x * 3)+ 2] = data[x].Z;
		 }
		 _data = ldata;
		 _size = sizeof(data) * 3;
}
VertexBufferObjectWithSubData::SubData::SubData(Vector4 data[])
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
		 _size = sizeof(data) * 4;
	
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