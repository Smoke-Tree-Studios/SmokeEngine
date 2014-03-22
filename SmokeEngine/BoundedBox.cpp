#include "BoundedBox.h"


BoundedBox::BoundedBox(Vector3 position, Vector3 size)
{
	Position = position;
	Size = size;
}


BoundedBox::~BoundedBox(void)
{
}


bool BoundedBox::BoundedBoxIntersection(BoundedBox boundedBox)
{
	if(!(Position.X < boundedBox.Position.X + boundedBox.Size.X || Position.X + Size.X < boundedBox.Position.X||
		Position.Y < boundedBox.Position.Y + boundedBox.Size.Y || Position.Y + Size.Y < boundedBox.Position.Y||
		Position.Z < boundedBox.Position.Z + boundedBox.Size.Z || Position.Z + Size.Z < boundedBox.Position.Z))
	{
		return true;
	}
	return false;

}
bool BoundedBox::IsBoundBoxContainPoint(Vector3 point)
{
	if(Position.X > point.X && Position.X + Size.X < point.X &&
		Position.Y > point.Y && Position.Y + Size.Y < point.Y &&
		Position.Z > point.Z && Position.Z + Size.Z < point.Z)
	{
		return true;
	}
	return false;
}
