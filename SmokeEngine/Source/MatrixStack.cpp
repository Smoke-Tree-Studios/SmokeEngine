#include "Utility/Matrix/MatrixStack.h"


MatrixStack::MatrixStack(void)
{
	_matricies = std::list<Matrix4x4>();
}

MatrixStack::~MatrixStack(void)
{
}

void MatrixStack::Push(Matrix4x4 matrix)
{
	_matricies.push_back(matrix);
}

Matrix4x4 MatrixStack::GetTransform()
{
	Matrix4x4 lfinal = Matrix4x4();
	for (std::list<Matrix4x4>::iterator it=_matricies.begin(); it != _matricies.end(); ++it)
	{
		lfinal = lfinal * (*it);
	}
	return lfinal;

}

void MatrixStack::Pop()
{
	_matricies.pop_back();
}