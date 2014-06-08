#include "TestScene.h"
#include <android\log.h>
#include "Node\ObjectNode.h"
#include "Node\Node.h"

#include "Render\RenderObject.h"
#include "Render\Model.h"
#include "Utility\Source.h"
#include "Utility\Quaternion.h"

#include "Utility\Vector\Vector3.h"
#include "Utility\WaveFrontLoad.h"
#include "VertexObject\VertexBufferObjectWithSubData.h"
#include "VertexObject\VertexArrayObject.h"
#include "Utility\Shader.h"

#include "Utility\Camera.h"

#include "Utility\Texture.h"
#include "Audio\AudioSource.h"
#include "Audio\AudioManager.h"
#include "Audio\AudioPlayer.h"

#include "math.h"



TestScene::TestScene(SmokeEngine* smokeEngine,Camera * camera) : SceneNode(smokeEngine,camera)
{
	 this->mSmokeEngine->mAudioManager->PlayTrack( new AudioSource("W1_Level_01.ogg",this->mSmokeEngine->mSceneManager->mSmokeEngine->mAssetManager));

	Source * frag = new Source("phongshading.fs",this->mSmokeEngine->mAssetManager);
	Source * vertex = new Source("basic.vs",this->mSmokeEngine->mAssetManager);
	VertexBufferObjectWithSubData * _subData = new VertexBufferObjectWithSubData();
	VertexArrayObject * _vertexArray = WaveFrontLoad::Load("Teapot.wobj",this->mSmokeEngine->mAssetManager,_subData);

	_lightNode = new Node("Light");
	
	Model* m =new Model(this,_subData,_vertexArray,vertex ,frag);
	_testObject = new ObjectNode("test",m);

	this->mRootSceneNode->AppendNode(_testObject);
	this->mRootSceneNode->AppendNode(_lightNode);
	_testObject->Position = Vector3(0,-3,-30);

	Texture * t = new Texture("test-pattern.png",this->mSmokeEngine->mSceneManager->mSmokeEngine->mAssetManager); 
	_testObject->mRenderObject->mShader->SetTexture("in_BaseImage",t,0);

	x = 0;

}



TestScene::~TestScene(void)
{
}

void TestScene::Update(float deltaT) 
{


	_testObject->mRenderObject->mShader->SetMatrix4x4("in_light",this->mMainCamera->GetTransformMatrixRelativeToNode(_lightNode));
	Matrix4x4 t = this->mMainCamera->GetTransformMatrixRelativeToNode(_lightNode);
	x += (deltaT*.002f);
	//this->mMainCamera->Position = Vector3(sin(x) * 5,0,0);
	_lightNode->Position = Vector3( 100,0,0);
	
	_testObject->Rotation = Quaternion(x,3.14f,0);
	 //__android_log_print(ANDROID_LOG_INFO,"SMOKE_ENGINE","DELTA: %f\n",deltaT);
}
