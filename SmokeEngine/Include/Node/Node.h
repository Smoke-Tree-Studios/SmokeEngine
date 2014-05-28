#pragma once
#include <list>
#include <map>
#include <string>
#include "Utility/Vector/Vector3.h"
#include "Utility/Quaternion.h"
#include "Utility/Matrix/Matrix4x4.h"

class SharedNodeInfo;
class Camera;
class SceneNode; 
class Node
{
	private:

	protected:

		std::string _id;

		//the children nodes related to the set
		std::list<Node*>* _children;

		//list of all the nodes in a scene. used for the scenemanager
		SharedNodeInfo* _sharedNodeInfo;

		Node * _parentNode;
		SceneNode * _sceneNode;

		virtual void _onNodeAppend();
	
	public:

		Vector3 Position;
		Vector3 Scale;
		Quaternion Rotation;

		Node(std::string ID);
		virtual ~Node(void);

		virtual Matrix4x4 GetMatrix();

		//gets the id of the node
		std::string GetID();

		//appends a node to the set
		virtual void AppendNode(Node * n);

		std::list<Node*>* GetChildren();
		Node* GetParent();
		Node* GetNode(std::string id);

		//delete's all the children nodes
		void DeleteAllChildren();

		//gets the location of the node relative to the camera
		Matrix4x4 GetLocationOfNode(Camera* cam);
        
		//gets the node type
		virtual std::string GetType();

		//update for the node 
		virtual void Update();
};

