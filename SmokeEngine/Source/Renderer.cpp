#include "Render\Renderer.h"
#include "Node\SceneNode.h"
#include <list>
#include "Node\Node.h"
#include "Node\ObjectNode.h"
#include "Utility\Camera.h"


Renderer::Renderer(void)
{

}


Renderer::~Renderer(void)
{

}



void Renderer::Draw(SceneNode* scene)
{
	
	
	_matrixStack.Push(scene->mMainCamera->GetMatrix());
	DrawNode(scene->mRootSceneNode,scene);
	_matrixStack.Pop();
	//DrawNode(scene->mRootOverlayNode);
	
}

void Renderer::DrawNode(Node * n,SceneNode *scene)
{
	for(std::list<Node*>::iterator iter = n->GetChildren()->begin(); iter !=  n->GetChildren()->end();++iter)
	{
		_matrixStack.Push((*iter)->GetMatrix());
		if((*iter)->GetType() == "object_node")
		{
			static_cast<ObjectNode*>((*iter))->Draw(_matrixStack.GetTransformMatrix(),scene->mMainCamera->GetViewMatrix());
		}
		DrawNode((*iter),scene);
		_matrixStack.Pop();
	}
}