#pragma once
#include "Vector2.h"
class S_Rectangle
{
public:
	Vector2 Position;
	Vector2 Size;

	S_Rectangle(Vector2 position, Vector2 size);
	~S_Rectangle(void);

	bool RectangleIntersection(S_Rectangle r);
	bool IsPointContainedInRectangle(Vector2 point);
};

