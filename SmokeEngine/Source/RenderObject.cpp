#include "Render\RenderObject.h"
#include "Utility\Shader.h"
#include "Node\SceneNode.h"
#include "Utility\Source.h"
#include "Storage\ShaderSourceStorage.h"

RenderObject::RenderObject(SceneNode * sceneNode)
{
	mShader = new Shader();
	_depthShader = new Shader();
	if(!sceneNode->mSmokeEngine->mShaderSourceStorage->IsSourceUsed(DEPTH_SHADER,GL_FRAGMENT_SHADER))
	{
		
		sceneNode->mSmokeEngine->mShaderSourceStorage->AppendSource(DEPTH_SHADER,new Source(DEPTH_FRAGMENT_SHADER,GL_FRAGMENT_SHADER));
	}

	if(!sceneNode->mSmokeEngine->mShaderSourceStorage->IsSourceUsed(DEPTH_SHADER,GL_VERTEX_SHADER))
	{
		sceneNode->mSmokeEngine->mShaderSourceStorage->AppendSource(DEPTH_SHADER,new Source(DEPTH_VERTEX_SHADER,GL_VERTEX_SHADER));
	}


	_depthShader->AttachSource(sceneNode->mSmokeEngine->mShaderSourceStorage->GetSource(DEPTH_SHADER,GL_FRAGMENT_SHADER));
	_depthShader->AttachSource(sceneNode->mSmokeEngine->mShaderSourceStorage->GetSource(DEPTH_SHADER,GL_VERTEX_SHADER));
	

}


RenderObject::~RenderObject(void)
{

}
