#pragma once
#include <GLES2/gl2.h>
#include <GLES2/gl2ext.h>
#include <string>
#include <android\log.h>
#include <opencv2\core\core.hpp>
#include <android\asset_manager.h>

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

