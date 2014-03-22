#include "ObjectNode.h"


ObjectNode::ObjectNode(std::string ID) : Node::Node(ID)
{
}

Matrix4x4 ObjectNode::GetMatrix()
{
	return Matrix4x4();
}
ObjectNode::~ObjectNode(void)
{
}
