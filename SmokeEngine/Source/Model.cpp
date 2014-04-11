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
#include "VertexObject\VertexBufferObjectWithSubData.h"
#include "VertexObject\VertexArrayObject.h"

#include "S_Debug.h"

Model::Model(SceneNode* sceneNode,VertexBufferObjectWithSubData* vertexBufferObject,VertexArrayObject* vertexArrayObject,Source* vertexSource, Source* Fragmentsource) : RenderObject::RenderObject(sceneNode)
{
	
	mShader->AttachSource(vertexSource);
	mShader->AttachSource(Fragmentsource);
	mShader->IntalizeShader();

	for(int x = 0; x < vertexBufferObject->GetSize(); x++)
	{
		if((*vertexBufferObject)[x]->GetListedType() == VERTEX)
		{
			mShader->SetAttrib(x,"in_Verts");
		}
		else if((*vertexBufferObject)[x]->GetListedType() == NORMALS)
		{
			mShader->SetAttrib(x,"in_Normals");
		}
		else if((*vertexBufferObject)[x]->GetListedType() == TEX_COORDS)
		{
			mShader->SetAttrib(x,"in_TexCoords");
		}
	}

	mShader->SetMatrix4x4("in_Transform",Matrix4x4::Idenity());
	mShader->SetMatrix4x4("in_View",Matrix4x4::Idenity());

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
