#include "Node\AttachmentNode\AttachmentNode.h"
#include "BulletCollision\CollisionDispatch\btGhostObject.h"
#include <btBulletDynamicsCommon.h>
#include "SmokeEngine.h"

AttachmentNode::AttachmentNodeCallback::AttachmentNodeCallback(){

}
void AttachmentNode::AttachmentNodeCallback::Callback(ObjectNode* objectNode, std::list<AttachmentNode*> attachmentNodes)
{
}



AttachmentNode::AttachmentNode(std::string ID, SmokeEngine * Engine): Node::Node(ID)
{
	
}


std::string AttachmentNode::GetType()
{
	return "attachment_node";
}

AttachmentNode::~AttachmentNode(void)
{
}


std::string AttachmentNode::GetTypeName()
{
	return "";
}

void AttachmentNode::SetMask(std::string mask)
{
	_mask = mask;
}