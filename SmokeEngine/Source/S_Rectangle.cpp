#include "Utility\S_Rectangle.h"

S_Rectangle::S_Rectangle()
{
}


S_Rectangle::S_Rectangle(Vector2 position, Vector2 size)
{
	Position = position;
	Size = size;

}

bool S_Rectangle::RectangleIntersection(S_Rectangle r)
{
	if(!(Position.X < r.Position.X  + r.Size.X || Position.X + Size.X > r.Position.X || Position.Y < r.Position.Y + r.Size.Y || Position.Y + Size.Y  > r.Position.Y))
	{
		return true;
	}
	return false;
}

bool S_Rectangle::IsPointContainedInRectangle(Vector2 point)
{
	if(Position.X > point.X && Position.X + Size.X < point.X && Position.Y > point.Y && Position.Y + Size.Y < point.Y)
	{
		return true;
	}
	return false;
}


S_Rectangle::~S_Rectangle(void)
{
}
