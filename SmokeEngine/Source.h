#pragma once
#include <GLES2/gl2.h>
#include <GLES2/gl2ext.h>
#include <string>

class Source
{
private:
	GLuint _source;

	void _compile(const char* source);
public:
	Source(const char* source,GLenum Type);
	Source(const char* file);

	GLuint GetSourceID();
	~Source(void);
};

