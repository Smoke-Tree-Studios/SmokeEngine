#pragma once
#include "Utility\Matrix\MatrixStack.h"

class Renderer
{
private:
	MatrixStack _matrixStack;
	void DrawNode();
public:
	void Draw();

	Renderer(void);
	~Renderer(void);
};

