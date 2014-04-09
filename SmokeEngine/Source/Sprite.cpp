#include "Render\Sprite.h"
#include "Utility\Matrix\Matrix4x4.h"
#include "Utility\Shader.h"
#include "Utility\Source.h"
#include <gles2\gl2.h>
#include "Node\SceneNode.h"
#include "Utility\Matrix\Matrix4x4.h"
#include "Utility\Vector\Vector2.h"
#include "VertexObject\VertexArrayObject.h"
#include "VertexObject\VertexBufferObjectWithSubData.h"

Sprite::Sprite(SceneNode * sceneNode,Source * fragmentShader) : RenderObject::RenderObject(sceneNode)
{

	if(!sceneNode->mShaderSourceStorage->IsSourceUsed(SPRITE,GL_VERTEX_SHADER))
		sceneNode->mShaderSourceStorage->AppendSource(SPRITE,new Source(SPRITE_VERTEX_SHADER,GL_VERTEX_SHADER));

	this->mShader->AttachSource(sceneNode->mShaderSourceStorage->GetSource(SPRITE,GL_VERTEX_SHADER));
	this->mShader->AttachSource(fragmentShader);

	_initialize(sceneNode);
}

Sprite::Sprite(SceneNode * sceneNode) : RenderObject::RenderObject(sceneNode)
{

	if(!sceneNode->mShaderSourceStorage->IsSourceUsed(SPRITE,GL_VERTEX_SHADER))
		sceneNode->mShaderSourceStorage->AppendSource(SPRITE,new Source(SPRITE_VERTEX_SHADER,GL_VERTEX_SHADER));
	if(!sceneNode->mShaderSourceStorage->IsSourceUsed(SPRITE,GL_FRAGMENT_SHADER))
		sceneNode->mShaderSourceStorage->AppendSource(SPRITE,new Source(SPRITE_FRAGMENT_SHADER,GL_FRAGMENT_SHADER));

	this->mShader->AttachSource(sceneNode->mShaderSourceStorage->GetSource(SPRITE,GL_VERTEX_SHADER));
	this->mShader->AttachSource(sceneNode->mShaderSourceStorage->GetSource(SPRITE,GL_FRAGMENT_SHADER));
	
	//set up the other fixed variables for the sprite
	_initialize(sceneNode);
}

void Sprite::_initialize(SceneNode * sceneNode)
{
	GLushort ldata[] = {1,2,3,4,4,1};
	new VertexArrayObject(ldata, 6);

	if(!sceneNode->mVertexBufferStorage->IsVertexArrayObjectExist(SPRITE))
	{
		GLushort ldata[] = SPRITE_INDECIES;
		sceneNode->mVertexBufferStorage->AppendVertexObject(SPRITE,new VertexArrayObject(ldata, SPRITE_INDECIES_SIZE));
	}
	if(!sceneNode->mVertexBufferStorage->IsVertexObjectWithSubDataExist(SPRITE))
	{
		VertexBufferObjectWithSubData * lvertexObject = new VertexBufferObjectWithSubData();
		{
			GLfloat ldata [] = SPRITE_VERTICIES;
			lvertexObject->AddSubData(new VertexBufferObjectWithSubData::SubData(ldata,SPRITE_VERTICIES_SIZE,3));
		}

		{
			GLfloat ldata [] = SPRITE_INDECIES;
			lvertexObject->AddSubData(new VertexBufferObjectWithSubData::SubData(ldata,SPRITE_INDECIES_SIZE,1));
		}

		sceneNode->mVertexBufferStorage->AppendVertexObject(SPRITE,new VertexBufferObjectWithSubData());
	}

	this->mVertexArrayObject = sceneNode->mVertexBufferStorage->GetVertexArryObject(SPRITE);
	this->mVertexSubData = sceneNode->mVertexBufferStorage->GetVertexObjectWithSubData(SPRITE);

	this->mShader->SetMatrix4x4("in_View",Matrix4x4::Idenity());
	this->mShader->SetMatrix4x4("in_Transform",Matrix4x4::Idenity());

	SetClippingRectangle(Vector2(0,0),Vector2(1,1));
	
	this->mShader->SetAttrib(0,"in_Verts");
	this->mShader->SetAttrib(1,"in_Index");
}

void Sprite::SetClippingRectangle(Vector2 pos, Vector2 size)
{
	this->mShader->SetUniform2("in_Clipping_Position",pos);
	this->mShader->SetUniform2("in_Clipping_Size",size);
}

Sprite::~Sprite(void)
{
}

void Sprite::Draw(Matrix4x4 transform, Matrix4x4 view)
{
	this->mShader->BindShader();

	this->mShader->SetMatrix4x4("in_View",view);
	this->mShader->SetMatrix4x4("in_Transform",transform);

	this->mVertexArrayObject->Bind();
	this->mVertexSubData->Bind();

	glDrawElements(GL_TRIANGLES,mVertexArrayObject->GetNumberOfIndecies(),GL_UNSIGNED_SHORT,NULL);


}

void Sprite::DepthDraw(Matrix4x4 transform, Matrix4x4 view)
{
}