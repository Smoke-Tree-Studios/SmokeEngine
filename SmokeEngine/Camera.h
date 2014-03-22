#pragma once
#include "Matrix4x4.h"
#include "Vector3.h"
#include "Quanterion.h"
#include "Node.h"

class Camera
{
private:
	Matrix4x4 _viewMatrix;

public:
	Vector3 Position;
	Quanterion Rotation;


	Camera(Matrix4x4 ViewMatrix);
	~Camera(void);

	Matrix4x4 GetMatrix();
};

