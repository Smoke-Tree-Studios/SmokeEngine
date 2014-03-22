#include "Node\SceneNode.h"

SceneNode::RootNode::RootNode(SceneNode * sceneNode,std::map< std::string, Node* >* nodes, std::string ID) : Node(ID) 
{
	_sceneNode = sceneNode;
	_nodes = nodes;
	
}

SceneNode::SceneNode(void)
{
	_nodes = new std::map< std::string, Node* >();
	RootSceneNode = new RootNode(this,_nodes,"ROOT_SCENE");
	RootOverlayNode  = new RootNode(this,_nodes,"ROOT_OVERLAY");
}


SceneNode::~SceneNode(void)
{
	delete(RootSceneNode);
	delete(RootOverlayNode);

}
