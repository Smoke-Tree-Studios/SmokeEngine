#pragma once
#include "Utility\Matrix\MatrixStack.h"
class Node;
class SceneNode;
class Renderer
{
private:
	MatrixStack _matrixStack;
	
	void DrawNode(Node * n,SceneNode *scene);
public:
	void Draw(SceneNode *scene);

	Renderer(void);
	~Renderer(void);
};

