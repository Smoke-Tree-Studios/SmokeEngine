#include "Utility\Source.h"
#include <android\asset_manager.h>
#include "S_Debug.h"

Source::Source(const char* source,GLenum Type)
{
	_type = Type;
	_source = glCreateShader(Type);
	_compile(source);

}
Source::Source(const char* file,AAssetManager* assetManager)
{
	INFO("loading shader file: %s",file);

	if(file[ strlen(file) -1] == 's' && file[ strlen(file) -2] == 'v')
	{
		_type = GL_VERTEX_SHADER;
		_source = glCreateShader(GL_VERTEX_SHADER);
	}
	else if(file[ strlen(file) -2] == 'f' && file[ strlen(file) -1] == 's')
	{
		_type = GL_FRAGMENT_SHADER;
		_source = glCreateShader(GL_FRAGMENT_SHADER);
	}
	else
	{
		ERROR("Invalid shader file type: %s",file);
	}

	AAsset* lasset = AAssetManager_open(assetManager,file,AASSET_MODE_UNKNOWN);

	if(NULL == lasset)
	{
		ERROR("Failed to open: %s", file);
	}

	int lsize = AAsset_getLength(lasset);

	char * ldata = (char*)calloc(lsize +1, sizeof(char));
	AAsset_read(lasset,ldata,lsize);
	ldata[lsize] = 0;
	if(!_compile(ldata))
	{
		ERROR("Failed to compile shader: %s",file);
	}
	free(ldata);

}

GLuint Source::GetSourceID()
{
	return _source;
}

GLenum Source::GetType()
{
	return _type;
}

bool Source::_compile(const char* source)
{
	if(_source)
	{
		glShaderSource(_source,1,&source,NULL);
		glCompileShader(_source);
		GLint lcompile = 0;
		glGetShaderiv(_source, GL_COMPILE_STATUS, &lcompile);
		if (!lcompile) {
			GLint linfoLen = 0;
			 glGetShaderiv(_source, GL_INFO_LOG_LENGTH, &linfoLen);
			 if (linfoLen) {
				char* lbuffer = (char*) malloc(linfoLen);
				if (lbuffer) {
					glGetShaderInfoLog(_source, linfoLen, NULL, lbuffer);
					ERROR("could not compile shader");
					ERROR(source);
					ERROR("\n");
					ERROR(lbuffer);
					free(lbuffer);
				}
				glDeleteShader(_source);
				_source = 0;
				return false;
			 }

		}
	}
	return true;
}

Source::~Source(void)
{

		glDeleteShader(_source);
}
