#include "Render\RenderObject.h"
#include "Utility\Shader.h"
#include "Node\SceneNode.h"
#include "Utility\Source.h"

RenderObject::RenderObject(SceneNode * sceneNode)
{
	mShader = new Shader();
	if(!sceneNode->mShaderSourceStorage->IsSourceUsed(DEPTH_SHADER,GL_FRAGMENT_SHADER))
	{
		
		sceneNode->mShaderSourceStorage->AppendSource(DEPTH_SHADER,new Source(DEPTH_FRAGMENT_SHADER,GL_FRAGMENT_SHADER));
	}

	if(!sceneNode->mShaderSourceStorage->IsSourceUsed(DEPTH_SHADER,GL_VERTEX_SHADER))
	{
		sceneNode->mShaderSourceStorage->AppendSource(DEPTH_SHADER,new Source(DEPTH_VERTEX_SHADER,GL_VERTEX_SHADER));
	}


	mShader->AttachSource(sceneNode->mShaderSourceStorage->GetSource(DEPTH_SHADER,GL_FRAGMENT_SHADER));
	mShader->AttachSource(sceneNode->mShaderSourceStorage->GetSource(DEPTH_SHADER,GL_VERTEX_SHADER));
}


RenderObject::~RenderObject(void)
{
	delete(mShader);
}
