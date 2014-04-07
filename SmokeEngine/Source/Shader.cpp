#include "Utility\Shader.h"
#include "Utility\Source.h"
#include "Utility\Texture.h"
#include "Utility\Vector\Vector2.h"
#include "Utility\Vector\Vector3.h"
#include "Utility\Vector\Vector4.h"
#include "Utility\Matrix\Matrix4x4.h"

Shader::Shader(void)
{
	_shaderProgram = glCreateProgram();

	_textures = std::map<int,GLuint>();
}

void Shader::_useShader()
{
	if(_shaderProgram == Shader::ActiveProgram )
		glUseProgram(_shaderProgram);
	else
		Shader::ActiveProgram = _shaderProgram;
}

Shader::~Shader(void)
{
	glDeleteProgram(_shaderProgram);
}

void Shader::AttachSource(Source* source)
{
	glAttachShader(_shaderProgram,source->GetSourceID());
}

void Shader::IntalizeShader()
{
	glLinkProgram(_shaderProgram);
	glUseProgram(_shaderProgram);
}

void Shader::SetAttrib(int index, const GLchar* attrib)
{
	glBindAttribLocation(_shaderProgram,index,attrib);
}

//UNIFORM 1
void Shader::SetUniform1(const GLchar* UniformID, GLint value)
{
	_useShader();
	glUniform1i(glGetUniformLocation(_shaderProgram,UniformID),value);
}

void Shader::SetUniform1(const GLchar* UniformID,GLint value[])
{
	_useShader();
	glUniform1iv(glGetUniformLocation(_shaderProgram,UniformID),sizeof(value),value);
}

void Shader::SetUniform1(const GLchar* UniformID, GLfloat value)
{
	_useShader();
	glUniform1f(glGetUniformLocation(_shaderProgram,UniformID),value);
}

void Shader::SetUniform1(const GLchar* UniformID,const GLfloat value[])
{
	_useShader();
	glUniform1fv(glGetUniformLocation(_shaderProgram,UniformID),sizeof(value),value);
}

//uniform 2
void Shader::SetUniform2(const GLchar* UniformID, Vector2 value)
{
	_useShader();
	glUniform2f(glGetUniformLocation(_shaderProgram,UniformID),value.X,value.Y);

}

void Shader::SetUniform2(const GLchar* UniformID, Vector2 value[])
{
	GLfloat lvalue[sizeof(value) *2];
	for(int x = 0; x < sizeof(value) ; x++)
	{
		lvalue[(x*2)] = value[x].X;
		lvalue[(x*2)+1] = value[x].Y;
	}
	_useShader();
	glUniform2fv(glGetUniformLocation(_shaderProgram,UniformID),sizeof(value),lvalue);
}

//uniform 3
void Shader::SetUniform3(const GLchar* UniformID, Vector3 value)
{
	_useShader();
	glUniform3f(glGetUniformLocation(_shaderProgram,UniformID),value.X,value.Y,value.Z);
}

void Shader::SetUniform3(const GLchar* UniformID, Vector3 value[])
{
	GLfloat lvalue[sizeof(value) *3];
	for(int x = 0; x < sizeof(value) ; x++)
	{
		lvalue[(x*3)] = value[x].X;
		lvalue[(x*3)+1] = value[x].Y;
		lvalue[(x*3)+2] = value[x].Z;
	}
	_useShader();
	glUniform3fv(glGetUniformLocation(_shaderProgram,UniformID),sizeof(value),lvalue);

}

//uniform 4
void Shader::SetUniform4(const GLchar* UniformID, Vector4 value)
{
	_useShader();
	glUniform4f(glGetUniformLocation(_shaderProgram,UniformID),value.X,value.Y,value.Z,value.W);
}

void Shader::SetUniform4(const GLchar* UniformID, Vector4 value[])
{
	GLfloat lvalue[sizeof(value) *4];
	for(int x = 0; x < sizeof(value) ; x++)
	{
		lvalue[(x*4)] = value[x].X;
		lvalue[(x*4)+1] = value[x].Y;
		lvalue[(x*4)+2] = value[x].Z;
		lvalue[(x*4)+4] = value[x].W;
	}
	_useShader();
	glUniform4fv(glGetUniformLocation(_shaderProgram,UniformID),sizeof(value),lvalue);

}

void Shader::SetTexture(const GLchar* UniformID,Texture* texture,int index)
{
	_useShader();
	if(_textures.count(index))
	{
		_textures[index] = texture->GetResourceID();
	}
	else
	{
		_textures.insert(std::pair<int,GLuint>(index,texture->GetResourceID()) );
	}
	glUniform1i(glGetUniformLocation(_shaderProgram,UniformID),index);
}

void Shader::SetMatrix4x4(const GLchar* UniformID, Matrix4x4 m)
{
	GLfloat lvalue[16] ;
	lvalue[0] = m.m11;
	lvalue[1] = m.m21;
	lvalue[2] = m.m31;
	lvalue[3] = m.m41;

	lvalue[4] = m.m12;
	lvalue[5] = m.m22;
	lvalue[6] = m.m32;
	lvalue[7] = m.m42;

	lvalue[8] = m.m13;
	lvalue[9] = m.m23;
	lvalue[10] = m.m34;
	lvalue[11] = m.m41;

	lvalue[12] = m.m14;
	lvalue[13] = m.m24;
	lvalue[14] = m.m34;
	lvalue[15] = m.m44;
	_useShader();
	glUniformMatrix4fv(glGetUniformLocation(_shaderProgram,UniformID),1,false,lvalue);
}

void Shader::SetMatrix4x4(const GLchar* UniformID,Matrix4x4 m[])
{
	GLfloat lvalue[sizeof(m) *16];
	for(int x = 0; x < sizeof(m) ; x++)
	{
		
		lvalue[(x*16)] = m[x].m11;
		lvalue[(x*16)+1] = m[x].m21;
		lvalue[(x*16)+2] = m[x].m31;
		lvalue[(x*16)+3] = m[x].m41;

		lvalue[(x*16)+4] = m[x].m12;
		lvalue[(x*16)+5] = m[x].m22;
		lvalue[(x*16)+6] = m[x].m32;
		lvalue[(x*16)+7] = m[x].m42;

		lvalue[(x*16)+8] = m[x].m13;
		lvalue[(x*16)+9] = m[x].m23;
		lvalue[(x*16)+10] = m[x].m34;
		lvalue[(x*16)+11] = m[x].m41;

		lvalue[(x*16)+12] = m[x].m14;
		lvalue[(x*16)+13] = m[x].m24;
		lvalue[(x*16)+14] = m[x].m34;
		lvalue[(x*16)+15] = m[x].m44;
	}
	_useShader();
	glUniform4fv(glGetUniformLocation(_shaderProgram,UniformID),sizeof(m),lvalue);


}

void Shader::BindShader()
{
	_useShader();
	for(std::map<int,GLuint>::iterator iter = _textures.begin(); iter != _textures.end(); iter++)
	{
		glActiveTexture(GL_TEXTURE0 + iter->first);
		glBindTexture(GL_TEXTURE_2D,iter->second);
	}
}

void Shader::Unbind()
{
	glUseProgram(0);
	Shader::ActiveProgram = 0;

}


int Shader::ActiveProgram = 0;