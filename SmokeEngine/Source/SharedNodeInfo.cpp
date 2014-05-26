#include "Node/SharedNodeInfo.h"
#include "Node\Node.h"
#include "Node\AttachmentNode\AttachmentNode.h"

SharedNodeInfo::SharedNodeInfo(void)
{
	mNodes = new std::map<std::string, Node*>();
	mAttachmentNodes = new std::map<std::string, std::list<AttachmentNode*> >;
}


SharedNodeInfo::~SharedNodeInfo(void)
{

}
