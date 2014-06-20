#pragma once
#include "Utility\Vector\Vector2.h"
class S_Rectangle
{
public:
	Vector2 Position;
	Vector2 Size;

	S_Rectangle();
	S_Rectangle(Vector2 position, Vector2 size);
	~S_Rectangle(void);
	/**
	*check if two rectangles are intersecting
	**/
	bool RectangleIntersection(S_Rectangle r);
	/**
	*tells if a point is in a rectangle
	**/
	bool IsPointContainedInRectangle(Vector2 point);
};

