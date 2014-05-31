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
#include "Storage\VertexBufferStorage.h"
#include "Storage\ShaderSourceStorage.h"
#include "VertexObject/VertexBufferObjectWithSubData.h"

Sprite::Sprite(SceneNode * sceneNode,Source * fragmentShader) : RenderObject(sceneNode)
{

	if(!sceneNode->mSmokeEngine->mShaderSourceStorage->IsSourceUsed(SPRITE,GL_VERTEX_SHADER))
		sceneNode->mSmokeEngine->mShaderSourceStorage->AppendSource(SPRITE,new Source(SPRITE_VERTEX_SHADER,GL_VERTEX_SHADER));

	this->mShader->AttachSource(sceneNode->mSmokeEngine->mShaderSourceStorage->GetSource(SPRITE,GL_VERTEX_SHADER));
	this->mShader->AttachSource(fragmentShader);


	_initialize(sceneNode);
}

Sprite::Sprite(SceneNode * sceneNode) :  RenderObject(sceneNode)
{

	if(!sceneNode->mSmokeEngine->mShaderSourceStorage->IsSourceUsed(SPRITE,GL_VERTEX_SHADER))
		sceneNode->mSmokeEngine->mShaderSourceStorage->AppendSource(SPRITE,new Source(SPRITE_VERTEX_SHADER,GL_VERTEX_SHADER));
	if(!sceneNode->mSmokeEngine->mShaderSourceStorage->IsSourceUsed(SPRITE,GL_FRAGMENT_SHADER))
		sceneNode->mSmokeEngine->mShaderSourceStorage->AppendSource(SPRITE,new Source(SPRITE_FRAGMENT_SHADER,GL_FRAGMENT_SHADER));

	this->mShader->AttachSource(sceneNode->mSmokeEngine->mShaderSourceStorage->GetSource(SPRITE,GL_VERTEX_SHADER));
	this->mShader->AttachSource(sceneNode->mSmokeEngine->mShaderSourceStorage->GetSource(SPRITE,GL_FRAGMENT_SHADER));
	
	//this->mShader->IntalizeShader();

	//set up the other fixed variables for the sprite
	_initialize(sceneNode);
}

void Sprite::_initialize(SceneNode * sceneNode)
{

	if(!sceneNode->mSmokeEngine->mVertexBufferStorage->IsVertexArrayObjectExist(SPRITE))
	{
		GLushort ldata[] = SPRITE_INDECIES;
		sceneNode->mSmokeEngine->mVertexBufferStorage->AppendVertexObject(SPRITE,new VertexArrayObject(ldata, SPRITE_INDECIES_SIZE));
	}
	if(!sceneNode->mSmokeEngine->mVertexBufferStorage->IsVertexObjectWithSubDataExist(SPRITE))
	{
		VertexBufferObjectWithSubData * lvertexObject = new VertexBufferObjectWithSubData();
		{
			GLfloat ldata [] = SPRITE_VERTICIES;
			lvertexObject->AddSubData(new VertexBufferObjectWithSubData::SubData(ldata,SPRITE_VERTICIES_SIZE,3));
		}

		{
			GLfloat ldata [] = {0,1,2,3};
			lvertexObject->AddSubData(new VertexBufferObjectWithSubData::SubData(ldata,4,1));
		}
		lvertexObject->IntalizeBuffer();
		sceneNode->mSmokeEngine->mVertexBufferStorage->AppendVertexObject(SPRITE,lvertexObject);
	}

	this->mVertexArrayObject = sceneNode->mSmokeEngine->mVertexBufferStorage->GetVertexArryObject(SPRITE);
	this->mVertexSubData = sceneNode->mSmokeEngine->mVertexBufferStorage->GetVertexObjectWithSubData(SPRITE);
		
	this->mShader->SetAttrib(0,"in_Verts");
	this->mShader->SetAttrib(1,"in_Index");

	this->mShader->IntalizeShader();

	//sets uniforms
	this->mShader->SetMatrix4x4("in_View",Matrix4x4::Idenity());
	this->mShader->SetMatrix4x4("in_Transform",Matrix4x4::Idenity());

	SetClippingRectangle(Vector2(0,0),Vector2(1,1));

	
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

	this->mVertexSubData->Bind();
	this->mVertexArrayObject->Bind();

	this->mShader->SetMatrix4x4("in_Transform",transform);
	this->mShader->SetMatrix4x4("in_View",view);

	glDrawElements(GL_TRIANGLES,mVertexArrayObject->GetNumberOfIndecies(),GL_UNSIGNED_SHORT,NULL);
}

void Sprite::DepthDraw(Matrix4x4 transform, Matrix4x4 view)
{
}