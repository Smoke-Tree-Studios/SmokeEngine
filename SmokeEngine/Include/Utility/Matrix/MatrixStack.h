#pragma once
#include <list>

class Matrix4x4;
class MatrixStack
{
private:
	//a stack of matricies
	 std::list<Matrix4x4> _matricies;

public:
	//pushes on the stack
	void Push(const Matrix4x4& matrix);
	//pop from the matrix stack
	void Pop();
	
	//get the full transform set
	Matrix4x4 GetTransform();

	MatrixStack(void);
	~MatrixStack(void);
};
