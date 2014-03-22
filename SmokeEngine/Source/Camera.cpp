#include "Utility\Camera.h"


Camera::Camera(Matrix4x4 ViewMatrix)
{
	_viewMatrix= ViewMatrix;

	Position = Vector3(0,0,0);
	Rotation  = Quanterion();
	_viewMatrix = Matrix4x4();
}

Camera::Camera(float fov,float aspect, float zNear, float zFar)
{
	_viewMatrix = Matrix4x4::Perspective(fov,aspect,zNear,zFar);

	
	Position = Vector3(0,0,0);
	Rotation  = Quanterion();
	_viewMatrix = Matrix4x4();
}

Camera::Camera(float left, float top, float right, float bottom, float zNear,float zFar)
{
	_viewMatrix = Matrix4x4::Orthographic(left,right,top,bottom,zNear,zFar);

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
