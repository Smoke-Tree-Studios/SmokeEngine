#include "Node\SceneNode.h"

SceneNode::RootNode::RootNode(SceneNode * sceneNode,std::map< std::string, Node* >* nodes, std::string ID) : Node(ID) 
{
	_sceneNode = sceneNode;
	_nodes = nodes;

	
}

SceneNode::SceneNode(SmokeEngine* smokeEngine,Camera * camera)
{
	mSceneManager = smokeEngine->mSceneManager;
	mSmokeEngine = smokeEngine;

	_nodes = new std::map< std::string, Node* >();
	mRootSceneNode = new RootNode(this,_nodes,"ROOT_SCENE");
	mRootOverlayNode  = new RootNode(this,_nodes,"ROOT_OVERLAY");

	mShaderSourceStorage = new ShaderSourceStorage();
	mTextureStorage = new TextureStorage();
	mVertexBufferStorage = new VertexBufferStorage();
	mViewStorage = new ViewStorage();

	mMainCamera = camera;

	mViewStorage->AddCamera("MAIN_CAMERA",mMainCamera);

}


SceneNode::~SceneNode(void)
{
	delete(mRootSceneNode);
	delete(mRootOverlayNode);

}
