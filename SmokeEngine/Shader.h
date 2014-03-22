#pragma once
#include <GLES2\gl2.h>
#include "Source.h"
#include "Vector2.h"
#include "Vector3.h"
#include "Vector4.h"
#include "Matrix4x4.h"

#include <opencv2\photo\photo.hpp>
class Shader
{
private:
	GLuint _shaderProgram;

	void _useShader();

public:
	static int ActiveProgram;

	Shader(void);
	~Shader(void);

	void AttachShader(Source source);
	void IntalizeShader();

	void SetAttrib(int index, const GLchar* attrib);

	void SetUniform1(const GLchar* UniformID, GLint value);
	void SetUniform1(const GLchar* UniformID,GLint value[]);

	void SetUniform1(const GLchar* UniformID, GLfloat value);
	void SetUniform1(const GLchar* UniformID,const GLfloat value[]);

	void SetUniform2(const GLchar* UniformID, Vector2 value);
	void SetUniform2(const GLchar* UniformID, Vector2 value[]);

	void SetUniform3(const GLchar* UniformID, Vector3 value);
	void SetUniform3(const GLchar* UniformID, Vector3 value[]);

	void SetUniform4(const GLchar* UniformID, Vector4 value);
	void SetUniform4(const GLchar* UniformID, Vector4 value[]);

	void SetMatrix4x4(const GLchar* UniformID,Matrix4x4 m);
	void SetMatrix4x4(const GLchar* UniformID,Matrix4x4 m[]);
};

int Shader::ActiveProgram = 0;