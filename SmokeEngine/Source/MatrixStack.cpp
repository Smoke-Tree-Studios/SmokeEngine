#include "Utility\Matrix\MatrixStack.h"
#include "Utility\Matrix\Matrix4x4.h"

MatrixStack::MatrixStack(void)
{
	_matricies = std::list<Matrix4x4>();
}

MatrixStack::~MatrixStack(void)
{
}

void MatrixStack::Push(const Matrix4x4& matrix)
{
	_matricies.push_back(matrix);
}

Matrix4x4 MatrixStack::GetTransformMatrix()
{
	Matrix4x4 lfinal = Matrix4x4();
	for (std::list<Matrix4x4>::iterator it=_matricies.begin(); it != _matricies.end(); ++it)
	{
		lfinal = lfinal * (*it);
	}
	return lfinal;

}

Matrix4x4 MatrixStack::GetReverseTransformMatrix()
{
	Matrix4x4 lfinal = Matrix4x4();
	
	for (std::list<Matrix4x4>::reverse_iterator it= _matricies.rbegin(); it != _matricies.rend(); ++it)
	{
		Matrix4x4 r = (*it);
		lfinal = lfinal * (*it);
	}
	return lfinal;
}

void MatrixStack::Pop()
{
	_matricies.pop_back();
}