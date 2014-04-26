#pragma once
#include "Utility/Matrix/Matrix4x4.h"
#include "Utility/Vector/Vector3.h"
#include "Utility/Quaternion.h"

class Node;
class Camera
{
private:
	Matrix4x4 _viewMatrix;

public:
	Vector3 Position;
	Quaternion Rotation;


	Camera(Matrix4x4 ViewMatrix);
	Camera(float fov,float aspect, float zNear, float zFar);
	Camera(float left, float top, float right, float bottom, float zNear,float zFar);

	~Camera(void);

	/** returns the transform matrix for the camera*/
	Matrix4x4 GetMatrix();
	Matrix4x4 GetTransformMatrixForNode(Node * node);
	Matrix4x4 GetViewMatrix();
};

