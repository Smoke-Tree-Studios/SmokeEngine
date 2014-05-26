#include "Node\Node.h"
#include "Utility\Matrix\MatrixStack.h"
#include "Utility\Matrix\Matrix4x4.h"
#include "Utility\Camera.h"
#include "Node\SharedNodeInfo.h"

Node::Node(std::string ID)
{

	_parentNode = NULL;

	Position = Vector3();
	Scale = Vector3(1,1,1);
	Rotation = Quaternion();

	_children =new std::list<Node*>();
	_id = ID;
}

Node::~Node(void)
{
	_sharedNodeInfo->mNodes->erase(_id);
	
	//(*_nodes).erase(_id); 
}

std::string Node::GetID()
{
	return _id;
}

void Node::DeleteAllChildren()
{
	for(std::list<Node*>::iterator literator =  _children->begin(); literator != _children->end(); ++literator)
	{
		delete((*literator));
	}
	delete(_children);
}

std::string Node::GetType(){
	return "Node";
}

Matrix4x4 Node::GetMatrix()
{
	Matrix4x4 lscale = Matrix4x4::Scale(Scale);
	Matrix4x4 lposition = Matrix4x4::Translation(Position);
	Matrix4x4 lrotation =Rotation.ConvertToMatrix();
	return lscale  * lrotation * lposition;
}

void Node::AppendNode(Node * n)
{
	n->_parentNode = (this);
	n->_sceneNode = _sceneNode;
	n->_sharedNodeInfo = _sharedNodeInfo;
	
	(*_sharedNodeInfo->mNodes)[n->_id] = n;
	//(*_nodes)[n->_id] = n;
	
	_children->push_back(n);

	n->_onNodeAppend();

}

void Node::_onNodeAppend(){
}

Node* Node::GetParent()
{
	return _parentNode;
}

Node* Node::GetNode(std::string id)
{

	for (std::list<Node*>::iterator it=_children->begin(); it != _children->end(); ++it)
	{
		if((*it)->GetID() == id)
		{
			return (*it);
		}
	}

}

std::list<Node*>*  Node::GetChildren()
{
	return _children;
}

Matrix4x4 Node::GetLocationOfNode(Camera* cam)
{
	MatrixStack lstack = MatrixStack();
	Node* llastParent = this;
	while (llastParent != NULL)
	{
		lstack.Push(llastParent->GetMatrix());
		llastParent = llastParent->GetParent();
	}
	lstack.Push(cam->GetMatrix());
	return lstack.GetReverseTransformMatrix();
}

void Node::Update()
{
}

