#include "Node\AttachmentNode\LightAttachmentNode.h"


LightAttachmentNode::LightAttachmentNode(std::string id, SmokeEngine * Engine) : AttachmentNode(id,Engine)
{
	mColor = Vector3(0,0,0);
	mIntesnity = 1;
}


LightAttachmentNode::~LightAttachmentNode(void)
{
}


 std::string LightAttachmentNode::GetTypeName()
 {
	 return "light_attachment_node";
 }