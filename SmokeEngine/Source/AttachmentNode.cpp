#include "Node\AttachmentNode\AttachmentNode.h"
#include "SmokeEngine.h"
#include "Node\SharedNodeInfo.h"
#include <map>
#include <string>


AttachmentNodeCallback::AttachmentNodeCallback(){

}
AttachmentNodeCallback::~AttachmentNodeCallback()
{

}
void AttachmentNodeCallback::Callback(ObjectNode* objectNode, std::list<AttachmentNode*> attachmentNodes)
{
}

AttachmentNode::AttachmentNode(std::string ID, SmokeEngine * Engine): Node::Node(ID)
{
	
}



void AttachmentNode::_onNodeAppend(){
	//adds the node to the share space
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



void AttachmentNode::SetMask(std::string mask)
{
	_mask = mask;
}

