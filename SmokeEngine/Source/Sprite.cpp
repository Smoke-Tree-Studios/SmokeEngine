#include "Render\Sprite.h"
#include "Utility\Matrix\Matrix4x4.h"
#include "Utility\Shader.h"
#include "Utility\Source.h"
#include <gles2\gl2.h>
#include "Node\SceneNode.h"
#include "Utility\Matrix\Matrix4x4.h"
#include "Utility\Vector\Vector2.h"

Sprite::Sprite(SceneNode * sceneNode) : RenderObject::RenderObject(sceneNode)
{
	this->mShader = new Shader();

	if(!sceneNode->mShaderSourceStorage->IsSourceUsed(SPRITE_SHADER,GL_VERTEX_SHADER))
	sceneNode->mShaderSourceStorage->AppendSource(SPRITE_SHADER,new Source(SPRITE_VERTEX_SHADER,GL_VERTEX_SHADER));

	if(!sceneNode->mShaderSourceStorage->IsSourceUsed(SPRITE_SHADER,GL_FRAGMENT_SHADER))
	sceneNode->mShaderSourceStorage->AppendSource(SPRITE_SHADER,new Source(SPRITE_FRAGMENT_SHADER,GL_FRAGMENT_SHADER));
	
	this->mShader->AttachSource(sceneNode->mShaderSourceStorage->GetSource(SPRITE_SHADER,GL_VERTEX_SHADER));
	this->mShader->AttachSource(sceneNode->mShaderSourceStorage->GetSource(SPRITE_SHADER,GL_FRAGMENT_SHADER));

	this->mShader->SetMatrix4x4("in_View",Matrix4x4::Idenity());
	this->mShader->SetMatrix4x4("in_Transform",Matrix4x4::Idenity());

	this->mShader->SetUniform2("in_Clipping_Position",Vector2(0,0));
	
}


Sprite::~Sprite(void)
{
}

void Sprite::Draw(Matrix4x4 transform, Matrix4x4 view)
{
}

void Sprite::DepthDraw(Matrix4x4 transform, Matrix4x4 view)
{
}