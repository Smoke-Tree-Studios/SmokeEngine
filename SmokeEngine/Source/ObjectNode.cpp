#include "Node/ObjectNode.h"
#include "Utility/Matrix/Matrix4x4.h"
#include "Node/SceneNode.h"
#include "Node/AttachmentNode/AttachmentNode.h"
#include "Render\RenderObject.h"

ObjectNode::ObjectNode(std::string ID) : Node::Node(ID)
{
	Origin = Vector3(0,0,0);
	_RenderObject = NULL;
}

Matrix4x4 ObjectNode::GetMatrix()
{
	Matrix4x4 lscale = Matrix4x4::Scale(Scale.X,Scale.Y,Scale.Z);
	Matrix4x4 lrotation = Rotation.ConvertToMatrix();
	Matrix4x4 lposition = Matrix4x4::Translation(Position);
	Matrix4x4 lorigin = Matrix4x4::Translation(Origin * -1.0f);
	return lorigin * lscale  * lrotation * lposition;
}
ObjectNode::~ObjectNode(void)
{
}

void ObjectNode::SetRenderObject(RenderObject * renderObject, bool DeletePreviousRenderObject)
{
	if(DeletePreviousRenderObject && _RenderObject != NULL)
	delete(_RenderObject);
	_RenderObject = renderObject;
}

void ObjectNode::Update()
{
}

RenderObject * ObjectNode::GetRenderObject()
{
	return _RenderObject;
}

void ObjectNode::AddAttchmentNodeCallback(std::string nodeType,AttachmentNodeCallback* attachmentNodeCallback)
{
	
	_attachmentNodeSet[nodeType] = attachmentNodeCallback;

}

void ObjectNode::RemoveAndDeleteAttachmentNodeCallback(std::string nodeType)
{
	AttachmentNodeCallback* cb = _attachmentNodeSet[nodeType];
	 delete cb;
	_attachmentNodeSet.erase(nodeType);
}

std::string ObjectNode::GetType()
{
	return "object_node";
}

void ObjectNode::Draw(Matrix4x4 transform, Matrix4x4 view)
{
	//draws the render object
	_RenderObject->Draw(transform,view);
}