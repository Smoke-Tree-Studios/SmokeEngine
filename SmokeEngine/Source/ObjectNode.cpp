#include "Node\ObjectNode.h"
#include "Utility\Matrix\Matrix4x4.h"
#include "Render\RenderObject.h"
#include "Node\SceneNode.h"
ObjectNode::ObjectNode(std::string ID, RenderObject * renderObject) : Node::Node(ID)
{
	mRenderObject = renderObject;
	Origin = Vector3(0,0,0);
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

void ObjectNode::Update()
{
}


void ObjectNode::Draw(Matrix4x4 transform, Matrix4x4 view)
{
	mRenderObject->Draw(transform,_sceneNode->mMainCamera->GetViewMatrix());
}