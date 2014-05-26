#pragma once

#include <map>
#include <string>
#include <list>
class Node;
class AttachmentNode;
class SharedNodeInfo
{
	public:
	std::map<std::string, Node*>* mNodes;
	std::map<std::string, std::list<AttachmentNode*> >* mAttachmentNodes;

	SharedNodeInfo(void);
	~SharedNodeInfo(void);
};

