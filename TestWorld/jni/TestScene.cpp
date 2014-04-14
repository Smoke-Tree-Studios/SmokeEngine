#include "TestScene.h"
#include <android\log.h>
#include "Node\ObjectNode.h"

#include "Render\RenderObject.h"
#include "Render\Model.h"
#include "Utility\Source.h"

#include "Utility\Vector\Vector3.h"
#include "Utility\WaveFrontLoad.h"
#include "VertexObject\VertexBufferObjectWithSubData.h"
#include "VertexObject\VertexArrayObject.h"
#include "Utility\Shader.h"

TestScene::TestScene(SmokeEngine* smokeEngine,Camera * camera) : SceneNode(smokeEngine,camera)
{
	Source * frag = new Source("phongshading.fs",this->mSmokeEngine->mAssetManager);
	Source * vertex = new Source("basic.vs",this->mSmokeEngine->mAssetManager);
	VertexBufferObjectWithSubData * _subData = new VertexBufferObjectWithSubData();
	VertexArrayObject * _vertexArray = WaveFrontLoad::Load("drag.wobj",this->mSmokeEngine->mAssetManager,_subData);

	Model* m =new Model(this,_subData,_vertexArray,vertex ,frag);
	m->mShader->SetUniform3("in_light",Vector3(0,0,0));
	_testObject = new ObjectNode("test",m);
	

	this->mRootSceneNode->AppendNode(_testObject);
	_testObject->Position = Vector3(0,-3,-10);

}



TestScene::~TestScene(void)
{
}

void TestScene::Update(float deltaT) 
{
	 //__android_log_print(ANDROID_LOG_INFO,"SMOKE_ENGINE","DELTA: %f\n",deltaT);
}
