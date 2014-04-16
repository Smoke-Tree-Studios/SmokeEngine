#include "Utility\Camera.h"
#include "math.h"

Camera::Camera(Matrix4x4 ViewMatrix)
{
	_viewMatrix= ViewMatrix;

	Position = Vector3(0,0,0);
	Rotation  = Quaternion();
}

Camera::Camera(float fov,float aspect, float zNear, float zFar)
{
	double lh = 1.0f/tan(fov/2.0f);
	_viewMatrix = Matrix4x4(
			lh/aspect,0,0,0,
			0,lh,0,0,
			0,0,(zFar+zNear)/(zNear-zFar),(2.0f*zFar*zNear)/( zNear-zFar ),
			0,0,-1,0);
	
	Position = Vector3(0,0,0);
	Rotation  = Quaternion();
}

Camera::Camera(float left, float top, float right, float bottom, float zNear,float zFar)
{
	_viewMatrix = Matrix4x4((2.0f/(right-left)),0,0,-((right+left)/(right-left)),
	0,(2.0f/(top-bottom)),0,-((top+bottom)/(top-bottom)),
	0,0,-(2.0f/(zFar-zNear)),-((zFar+zNear)/(zFar-zNear)),
	0,0,0,1);

	Position = Vector3(0,0,0);
	Rotation  = Quaternion();
}

Camera::~Camera(void)
{

}

Matrix4x4 Camera::GetMatrix()
{
	return _viewMatrix;
}
