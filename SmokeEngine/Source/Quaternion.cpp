#include "Utility\Quaternion.h"
#include "Utility\Matrix\Matrix4x4.h"
#include <math.h>
Quaternion::Quaternion(void)
{
	X = 0;
	Y = 0;
	Z = 0;
	W = 0;
}

Quaternion::Quaternion(float h, float b, float p)
{

	X = cos(h/2.0f)*cos(p/2.0f)*cos(b/2.0f)+ sin(h/2.0f)*sin(p/2.0f)*sin(b/2.0f);
	Y = cos(h/2.0f)*sin(p/2.0f)*cos(b/2.0f) + sin(h/2.0f)*cos(p/2.0f)*sin(b/2.0f);
	Z = sin(h/2.0f)*cos(p/2.0f)*cos(b/2.0f) - cos(h/2.0f)*sin(p/2.0f)*sin(b/2.0f);
	W = cos(h/2.0f)*cos(p/2.0f)*sin(b/2.0f) - sin(h/2.0f)*sin(p/2.0f)*cos(b/2.0f);

}

Quaternion::Quaternion(float x, float y, float z, float w)
{
	X = x;
	Y = y;
	Z = z;
	W = w;
}

Quaternion::~Quaternion(void)
{
}


Matrix4x4 Quaternion::ConvertToMatrix()
{
	return Matrix4x4(
		1-(2*this->Y * this->Y)-(2*this->Z * this->Z),(2 * this->X * this->Y)+(2*this->W * this->Z),(2*this->X*this->Z)-(2*this->W*this->Y),0,
		(2*this->X*this->Y)-(2*this->W*this->Z),1-(2*this->X*this->X)-(2*this->Z*this->Z),(2*this->Y*this->Z)+(2*this->W*this->X),0,
		(2*this->X*this->Z)+(2*this->W*this->Y),(2*this->Y*this->Z)-(2*this->W*this->X),1-(2*this->X*this->X)-(2*this->Y*this->Y),0,
		0,0,0,1.0f);
}