#pragma once
#include "Node.h"

//class Node;
class SceneNode
{
private:

	std::map<std::string, Node*>* _nodes;

protected:
	class RootNode : public Node
	{
		public:
			RootNode(SceneNode * sceneNode,std::map< std::string, Node* >* nodes, std::string ID);
	};


public:
	RootNode * RootSceneNode;
	RootNode * RootOverlayNode;

	virtual void Update(float deltaT) =0;

	SceneNode(void);
	~SceneNode(void);
};

