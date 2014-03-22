#include "Camera.h"


Camera::Camera(Matrix4x4 ViewMatrix)
{
	_viewMatrix= ViewMatrix;

	Position = Vector3(0,0,0);
	Rotation  = Quanterion();
	_viewMatrix = Matrix4x4();
}


Camera::~Camera(void)
{

}

Matrix4x4 Camera::GetMatrix()
{
	return _viewMatrix;
}
