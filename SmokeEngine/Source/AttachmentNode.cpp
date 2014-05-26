#include "Node\AttachmentNode\AttachmentNode.h"
#include "BulletCollision\CollisionDispatch\btGhostObject.h"
#include <btBulletDynamicsCommon.h>
#include "SmokeEngine.h"
#include "Node\SharedNodeInfo.h"
#include <map>
#include <string>
AttachmentNode::AttachmentNodeCallback::AttachmentNodeCallback(){

}
void AttachmentNode::AttachmentNodeCallback::Callback(ObjectNode* objectNode, std::list<AttachmentNode*> attachmentNodes)
{
}


AttachmentNode::AttachmentNode(std::string ID, SmokeEngine * Engine): Node::Node(ID)
{
	
}


void AttachmentNode::_onNodeAppend(){
	(*_sharedNodeInfo->mAttachmentNodes)[GetType()].push_back(this);
	
}


std::string AttachmentNode::GetType()
{
	return "attachment_node";
}

AttachmentNode::~AttachmentNode(void)
{
	for(std::list<AttachmentNode*>::iterator it = (*_sharedNodeInfo->mAttachmentNodes)[GetType()].begin(); it != (*_sharedNodeInfo->mAttachmentNodes)[GetType()].end(); it++)
	{
		if((*it) == this)
		{
			AttachmentNode* lnode = (*it);
			(*_sharedNodeInfo->mAttachmentNodes)[GetType()].erase(it);
			delete(lnode);
			break;
		}
	}
}


std::string AttachmentNode::GetTypeName()
{
	return "";
}

void AttachmentNode::SetMask(std::string mask)
{
	_mask = mask;
}

