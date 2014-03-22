#include "Utility\Source.h"
#include "android\log.h"
Source::Source(const char* source,GLenum Type)
{
	_type = Type;
	_source = glCreateShader(Type);
	_compile(source);

}
Source::Source(const char* file)
{
	if(file[sizeof(file) -1] == 's' && file[sizeof(file) -2] == 'v')
	{
		_type = GL_VERTEX_SHADER;
		_source = glCreateShader(GL_VERTEX_SHADER);
	}
	else if(file[sizeof(file) -1] == 'f' && file[sizeof(file) -2] == 's')
	{
		_type = GL_FRAGMENT_SHADER;
		_source = glCreateShader(GL_FRAGMENT_SHADER);
	}
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
					//LOGE("Could not compile shader %s\n", lbuffer);
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
}
