#include "Utility\Source.h"
#include <android\asset_manager.h>
#include <android\log.h>


Source::Source(const char* source,GLenum Type)
{
	_type = Type;
	_source = glCreateShader(Type);
	_compile(source);

}
Source::Source(const char* file,AAssetManager* assetManager)
{
	__android_log_print(ANDROID_LOG_INFO,"SMOKE_ENGINE",(char*)("loading shader file:" +std::string(file)).c_str());

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
		__android_log_print(ANDROID_LOG_INFO,"SMOKE_ENGINE",(char*)("unknown shader file type:" +std::string(file)).c_str());
	}

	AAsset* lasset = AAssetManager_open(assetManager,file,AASSET_MODE_UNKNOWN);

	if(NULL == lasset)
	{
		 __android_log_print(ANDROID_LOG_INFO,"SMOKE_ENGINE",(char*)("Failed to open: " + std::string(file)).c_str());
	}

	int lsize = AAsset_getLength(lasset);

	char * ldata = (char*)malloc(lsize * sizeof(char));
	AAsset_read(lasset,ldata,lsize);

	_compile(ldata);
	delete[] ldata;

}

GLuint Source::GetSourceID()
{
	return _source;
}

GLenum Source::GetType()
{
	return _type;
}

void Source::_compile(const char* source)
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
					 __android_log_print(ANDROID_LOG_ERROR,"SMOKE_ENGINE","Could not compile shader %s\n",lbuffer);
					free(lbuffer);
				}
				glDeleteShader(_source);
				_source = 0;
			 }

		}
	}
}

Source::~Source(void)
{

		glDeleteShader(_source);
}
