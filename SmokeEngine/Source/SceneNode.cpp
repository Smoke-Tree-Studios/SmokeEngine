#include "Node\SceneNode.h"

SceneNode::RootNode::RootNode(SceneNode * sceneNode,std::map< std::string, Node* >* nodes, std::string ID) : Node(ID) 
{
	_sceneNode = sceneNode;
	_nodes = nodes;

	
}

SceneNode::SceneNode(SceneManager* sceneManager, SmokeEngine* smokeEngine)
{
	mSceneManager = sceneManager;
	mSmokeEngine = smokeEngine;

	_nodes = new std::map< std::string, Node* >();
	mRootSceneNode = new RootNode(this,_nodes,"ROOT_SCENE");
	RootOverlayNode  = new RootNode(this,_nodes,"ROOT_OVERLAY");

	mShaderSourceStorage = new ShaderSourceStorage();
	mTextureStorage = new TextureStorage();
	mVertexBufferStorage = new VertexBufferStorage();
	mStorageView = new ViewStorage();

}


SceneNode::~SceneNode(void)
{
	delete(mRootSceneNode);
	delete(RootOverlayNode);

}
