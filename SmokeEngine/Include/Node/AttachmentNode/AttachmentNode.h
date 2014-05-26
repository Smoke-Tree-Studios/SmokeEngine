#pragma once
#include "Node\Node.h"
class SmokeEngine;
class btGhostObject;
class ObjectNode;
class AttachmentNode : public Node
{
private:
	std::string _mask;
public:
	class AttachmentNodeCallback{

		public:
			AttachmentNodeCallback();

			void Callback(ObjectNode* objectNode, std::list<AttachmentNode*> attachmentNodes);


	};

	virtual std::string GetType();

	AttachmentNode(std::string ID, SmokeEngine * Engine) ;
	~AttachmentNode(void);
	
	void SetMask(std::string mask);
	std::string GetMask();

	virtual std::string GetTypeName();
};

