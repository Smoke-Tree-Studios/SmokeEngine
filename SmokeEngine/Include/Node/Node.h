#pragma once
#include <list>
#include <map>
#include <string>
#include "Utility\Vector\Vector3.h"
#include "Utility\Quaternion.h"
#include "Utility\Matrix\Matrix4x4.h"

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
		std::map<std::string, Node*>* _nodes;

		Node * _parentNode;
		SceneNode * _sceneNode;
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
		void AppendNode(Node * n);

		std::list<Node*>* GetChildren();
		Node* GetParent();
		Node* GetNode(std::string id);

		//delete's all the children nodes
		void DeleteAllChildren();

		Matrix4x4 GetLocationOfNode(Camera* cam);
        

		virtual void Update();
		virtual void Draw(Matrix4x4 transform, Matrix4x4 view);
};

