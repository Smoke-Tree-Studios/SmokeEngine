#include "Render\Renderer.h"
#include "Node\SceneNode.h"
#include <list>
#include "Node\Node.h"

Renderer::Renderer(void)
{

}


Renderer::~Renderer(void)
{

}



void Renderer::Draw(SceneNode* scene)
{

	DrawNode(scene->mRootSceneNode,scene);

	//DrawNode(scene->mRootOverlayNode);
}

void Renderer::DrawNode(Node * n,SceneNode *scene)
{
	for(std::list<Node*>::iterator iter = n->GetChildren()->begin(); iter !=  n->GetChildren()->end();++iter)
	{
		_matrixStack.Push((*iter)->GetMatrix());
		(*iter)->Draw(_matrixStack.GetTransform(),scene->mMainCamera->GetMatrix());
			DrawNode((*iter),scene);
		_matrixStack.Pop();
	}
}