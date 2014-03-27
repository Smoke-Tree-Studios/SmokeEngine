#pragma once
#include "Utility\Matrix\MatrixStack.h"
#include "Node\SceneNode.h"
#include "Node\Node.h"

class SceneNode;
class Renderer
{
private:
	MatrixStack _matrixStack;
	
	void DrawNode(Node * n);
public:
	void Draw(SceneNode *scene);

	Renderer(void);
	~Renderer(void);
};

