#pragma once

class RenderObject
{
public:
	RenderObject(void);
	~RenderObject(void);

	 virtual void Draw() = 0;
	 virtual void DepthDraw() = 0;
};

