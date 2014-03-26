#include "Node\Node.h"


Node::Node(std::string ID)
{
	Position = Vector3();
	Scale = Vector3(1,1,1);
	Rotation = Quaternion();

	_children = std::list<Node*>();
	_id = ID;
}

Node::~Node(void)
{
	(*_nodes).erase(_id); 
}

std::string Node::GetID()
{
	return _id;
}

void Node::DeleteAllChildren()
{
	for(std::list<Node*>::iterator literator =  _children.begin(); literator != _children.end(); ++literator)
	{
		delete((*literator));
	}
}

Matrix4x4 Node::GetMatrix()
{
	Matrix4x4 lscale = Matrix4x4::Scale(Scale);
	Matrix4x4 lposition = Matrix4x4::Translation(Position);
	Matrix4x4 lrotation = Matrix4x4::Rotation(Rotation);
	return lscale * lrotation * lposition;
}

void Node::AppendNode(Node * n)
{
	n->_parentNode = (this);
	n->_sceneNode = _sceneNode;
	n->_nodes = _nodes;

	(*_nodes)[n->_id] = n;

	_children.push_back(n);
}

Node* Node::GetParent()
{
	return _parentNode;
}

Node* Node::GetNode(std::string id)
{
	for (std::list<Node*>::iterator it=_children.begin(); it != _children.end(); ++it)
	{
		if((*it)->GetID() == id)
		{
			return (*it);
		}
	}

}

std::list<Node*>  Node::GetChildren()
{
	return _children;
}



