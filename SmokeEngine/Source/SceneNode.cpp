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

	_sharedNodeInfo = new SharedNodeInfo();

	mSmokeEngine = smokeEngine;

	mRootSceneNode = new RootNode(this,_sharedNodeInfo,"ROOT_SCENE");
	mRootOverlayNode  = new RootNode(this,_sharedNodeInfo,"ROOT_OVERLAY");

	mViewStorage = new ViewStorage();

	mMainCamera = camera;

	mViewStorage->AddCamera("MAIN_CAMERA",mMainCamera);

}


SceneNode::~SceneNode(void)
{
	delete(mRootSceneNode);
	delete(mRootOverlayNode);
	delete(_sharedNodeInfo);
}
