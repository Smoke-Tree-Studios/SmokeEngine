#pragma once

#include <map>
#include <string>
#include <list>
class Node;
class AttachmentNode;
/*TODO: needs more structure*/
/**
*information that is shared between all the nodes
**/
class SharedNodeInfo
{
	public:
	//a collection of all the nodes in the set
	std::map<std::string, Node*>* mNodes;
	//a collection of all attachment nodes by type and every single association of that type
	std::map<std::string, std::list<AttachmentNode*> >* mAttachmentNodes;

	SharedNodeInfo(void);
	~SharedNodeInfo(void);
};

