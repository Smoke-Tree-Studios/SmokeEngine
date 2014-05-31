#pragma once
#include "Node\Node.h"
class SmokeEngine;
class btGhostObject;
class ObjectNode;


class AttachmentNode : public Node
{
protected:
	virtual void _onNodeAppend();
private:
	std::string _mask;
public:
	
	virtual std::string GetType();

	AttachmentNode(std::string ID, SmokeEngine * Engine) ;
	~AttachmentNode(void);

	/**
	*not implemented
	**/

	void SetMask(std::string mask);
	/**
	*not implemented
	**/
	std::string GetMask();


};

class AttachmentNodeCallback{
	public:
		AttachmentNodeCallback();
		virtual ~AttachmentNodeCallback();
		/**
		*callback used on the processing of attachment nodes to shader
		**/
		virtual void Callback(ObjectNode* objectNode, std::list<AttachmentNode*> attachmentNodes);
};

