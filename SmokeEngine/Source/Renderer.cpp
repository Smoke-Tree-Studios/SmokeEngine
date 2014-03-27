#include "Render\Renderer.h"
#include <list>
Renderer::Renderer(void)
{
}


Renderer::~Renderer(void)
{

}

void Renderer::Draw(SceneNode* scene)
{
	_matrixStack.Push(scene->mMainCamera->GetMatrix());
	DrawNode(scene->mRootSceneNode);
	_matrixStack.Pop();

	//DrawNode(scene->mRootOverlayNode);
}

void Renderer::DrawNode(Node * n)
{
	for(std::list<Node*>::iterator iter = n->GetChildren()->begin(); iter !=  n->GetChildren()->end();++iter)
	{
		(*iter)->GetMatrix();
		DrawNode((*iter));
	}
}