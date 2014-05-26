#include "Node\AttachmentNode\LightAttachmentNode.h"


LightAttachmentNode::LightAttachmentNode(std::string id, SmokeEngine * Engine) : AttachmentNode(id,Engine)
{
}


LightAttachmentNode::~LightAttachmentNode(void)
{
}


 std::string LightAttachmentNode::GetTypeName()
 {
	 return "light_attachment_node";
 }