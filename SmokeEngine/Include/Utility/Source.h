#pragma once
#include <string>
#include <GLES2/gl2.h>
#include <GLES2/gl2ext.h>


class AAssetManager;
class Source
{
private:
	GLuint _source;
	GLenum _type;
	void _compile(const char* source);
public:
	Source(const char* source,GLenum Type);
	Source(const char* file,AAssetManager* assetManager);

	GLenum GetType();
	GLuint GetSourceID();
	~Source(void);
};

