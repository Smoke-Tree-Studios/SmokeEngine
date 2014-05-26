#pragma once
#include "Node\AttachmentNode\AttachmentNode.h"
#include "Utility\Vector\Vector3.h"
class LightAttachmentNode :
	public AttachmentNode
{
public:
	Vector3 mColor;
	float mIntesnity;

	LightAttachmentNode(std::string id, SmokeEngine * Engine);
	~LightAttachmentNode(void);

	virtual std::string GetTypeName();
};

