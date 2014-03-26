#pragma once
#include "Utility\Matrix\MatrixStack.h"
#include "Node\SceneNode.h"

class SceneNode;
class Renderer
{
private:
	MatrixStack _matrixStack;
	
	void DrawNode();
public:
	void Draw(SceneNode *scene);

	Renderer(void);
	~Renderer(void);
};

