#include "Node\SceneNode.h"
#include "Node\Node.h"
#include "Utility\Camera.h"
#include "Storage\ShaderSourceStorage.h"
#include "Storage\VertexBufferStorage.h"
#include "Storage\ViewStorage.h"
#include "Storage\VertexBufferStorage.h"
#include "Storage\TextureStorage.h"
#include "Storage\ShaderSourceStorage.h"
#include "SceneManager.h"
#include "SmokeEngine.h"
#include "Node\SharedNodeInfo.h"


SceneNode::RootNode::RootNode(SceneNode * sceneNode,SharedNodeInfo* sharedNodeInfo, std::string ID) : Node(ID) 
{
	_sceneNode = sceneNode;
	_sharedNodeInfo = sharedNodeInfo;

}
std::string SceneNode::RootNode::GetType()
{
	return "root_node";
}

SceneNode::SceneNode(SmokeEngine* smokeEngine,Camera * camera)
{
	_isLoaded = false;

	_sharedNodeInfo = new SharedNodeInfo();

	mSmokeEngine = smokeEngine;

	mRootSceneNode = new RootNode(this,_sharedNodeInfo,"ROOT_SCENE");
	mRootOverlayNode  = new RootNode(this,_sharedNodeInfo,"ROOT_OVERLAY");

	mViewStorage = new ViewStorage();

	mMainCamera = camera;

	mViewStorage->AddCamera("MAIN_CAMERA",mMainCamera);
}
void SceneNode::Load()
{
	_isLoaded = true;
}

void SceneNode::UnLoad()
{
	_isLoaded = false;
}


bool SceneNode::IsLoad()
{
	return _isLoaded;
}

SceneNode::~SceneNode(void)
{
	delete(mRootSceneNode);
	delete(mRootOverlayNode);
	delete(_sharedNodeInfo);
}
