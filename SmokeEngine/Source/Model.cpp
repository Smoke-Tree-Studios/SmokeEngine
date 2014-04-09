#include "Render\Model.h"
#include "VertexObject\VertexArrayObject.h"
#include "VertexObject\VertexBufferObjectWithSubData.h"
#include "Utility\Source.h"
#include "Utility\Texture.h"
#include "Node\SceneNode.h"
#include "Utility\Shader.h"
#include "Utility\Matrix\Matrix4x4.h"
#include "Utility\Shader.h"
#include "Utility\Matrix\Matrix4x4.h"


Model::Model(SceneNode* sceneNode,VertexBufferObjectWithSubData* vertexBufferObject,VertexArrayObject* vertexArrayObject,Source* vertexSource, Source* Fragmentsource,Texture* texture) : RenderObject::RenderObject(sceneNode)
{
	
	mShader->AttachSource(vertexSource);
	mShader->AttachSource(Fragmentsource);

	mShader->SetAttrib(0,"in_Verts");
	mShader->SetAttrib(1,"in_TexCoords");
	mShader->SetAttrib(2,"in_Normals");

	mShader->SetMatrix4x4("in_Transform",Matrix4x4::Idenity());
	mShader->SetMatrix4x4("in_View",Matrix4x4::Idenity());

	mShader->SetTexture("in_BaseImage",texture,0);

	_vertexArrayObject = vertexArrayObject;
	_vertexBufferObject = vertexBufferObject;

}


Model::~Model(void)
{
}

void Model::Draw(Matrix4x4 transform, Matrix4x4 view)
{
	mShader->BindShader();

	mShader->SetMatrix4x4("in_Transform",transform);
	mShader->SetMatrix4x4("in_View",view);

	_vertexArrayObject->Bind();
	_vertexBufferObject->Bind();

	glDrawElements(GL_TRIANGLES,_vertexArrayObject->GetNumberOfIndecies(),GL_UNSIGNED_SHORT,0);
}

void Model::DepthDraw(Matrix4x4 transform, Matrix4x4 view)
{
	/*_depthShader->BindShader();

	_depthShader->SetMatrix4x4("in_Transform",transform);
	_depthShader->SetMatrix4x4("in_View",view);

	_vertexArrayObject->Bind();
	_vertexBufferObject->Bind();

	glDrawElements(GL_TRIANGLES,_vertexArrayObject->GetNumberOfIndecies(),GL_UNSIGNED_SHORT,0);
	*/
}
