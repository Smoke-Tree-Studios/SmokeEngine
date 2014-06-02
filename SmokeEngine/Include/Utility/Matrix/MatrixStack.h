#pragma once
#include <list>

class Matrix4x4;
class MatrixStack
{
private:
	//a stack of matricies
	 std::list<Matrix4x4> _matricies;

public:

	MatrixStack(void);
	~MatrixStack(void);

	/**
	 *pushes on the stack
	 **/
	void Push(const Matrix4x4& matrix);
	/**
	 * pop from the matrix stack
	 **/
	void Pop();
	
	/**
	*get the full transform set from beginning of the set to the end
	**/
	Matrix4x4 GetTransformMatrix();
	
	/**
	 * get the full transform set from the end of the set to the beginning
	 **/
	Matrix4x4 GetReverseTransformMatrix();

};
