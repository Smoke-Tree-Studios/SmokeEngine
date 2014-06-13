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
#include "android\input.h"
#include "Input\InputEvent.h"
#include "Storage\Storage.h"

TestScene::TestScene(SmokeEngine* smokeEngine,Camera * camera) : SceneNode(smokeEngine,camera)
{


}

TestScene::~TestScene(void)
{
}

void TestScene::Load()
{
	SceneNode::Load();

	this->mSmokeEngine->mShaderSourceStorage->AppendSource("PhongShading",new Source("phongshading.fs",this->mSmokeEngine->mAssetManager));
	this->mSmokeEngine->mShaderSourceStorage->AppendSource("BasicVertex",new Source("basic.vs",this->mSmokeEngine->mAssetManager));
	
	VertexBufferObjectWithSubData * lsubData = new VertexBufferObjectWithSubData();
	VertexArrayObject * lVertexArray = WaveFrontLoad::Load("Teapot.wobj",this->mSmokeEngine->mAssetManager,lsubData);
	
	this->mSmokeEngine->mVertexBufferStorage->AppendVertexObject("Teapot",lsubData);
	this->mSmokeEngine->mVertexBufferStorage->AppendVertexObject("Teapot",lVertexArray);

	this->mSmokeEngine->mTextureStorage->AppendTexture( new Texture("test-pattern.png",this->mSmokeEngine->mSceneManager->mSmokeEngine->mAssetManager));

	this->mSmokeEngine->mAudioSourceStorage->AppendAudioSource("TestAudio",new AudioSource("W1_Level_01.ogg",this->mSmokeEngine->mAssetManager));
	
}

void TestScene::UnLoad()
{
	SceneNode::UnLoad();

	this->mSmokeEngine->mShaderSourceStorage->DeleteSource("PhongShading",GL_FRAGMENT_SHADER);
	this->mSmokeEngine->mShaderSourceStorage->DeleteSource("BasicVertex",GL_VERTEX_SHADER);

	this->mSmokeEngine->mVertexBufferStorage->DeleteVertexArryObject("Teapot");
	this->mSmokeEngine->mVertexBufferStorage->DeleteVertexObjectWithSubData("Teapot");

	this->mSmokeEngine->mTextureStorage->DeleteTexture("test-pattern.png");

	this->mSmokeEngine->mAudioSourceStorage->RemoveAudioSource("TestAudio");
}

void TestScene::Initialize()
{
	this->mSmokeEngine->mAudioManager->PlayTrack( this->mSmokeEngine->mAudioSourceStorage->GetSource("TestAudio"));
	 
	_lightNode = new Node("Light");
	
	Model* m =new Model(this,
		this->mSmokeEngine->mVertexBufferStorage->GetVertexObjectWithSubData("Teapot"),
		this->mSmokeEngine->mVertexBufferStorage->GetVertexArryObject("Teapot"),
		this->mSmokeEngine->mShaderSourceStorage->GetSource("BasicVertex",GL_VERTEX_SHADER) ,
		this->mSmokeEngine->mShaderSourceStorage->GetSource("PhongShading",GL_FRAGMENT_SHADER));
	
	_testObject = new ObjectNode("test",m);

	this->mRootSceneNode->AppendNode(_testObject);
	this->mRootSceneNode->AppendNode(_lightNode);
	_testObject->Position = Vector3(0,-3,-30);

	_testObject->mRenderObject->mShader->SetTexture("in_BaseImage",
	this->mSmokeEngine->mTextureStorage->GetTexture("test-pattern.png"),0);

	x = 0;
}

void TestScene::Update(float deltaT) 
{
	_testObject->mRenderObject->mShader->SetMatrix4x4("in_light",this->mMainCamera->GetTransformMatrixRelativeToNode(_lightNode));
	Matrix4x4 t = this->mMainCamera->GetTransformMatrixRelativeToNode(_lightNode);
	x += (deltaT);
	//this->mMainCamera->Position = Vector3(sin(x) * 5,0,0);
	_lightNode->Position = Vector3( 100,0,0);
	
	_testObject->Rotation = Quaternion(x,3.14f,0);

	
	 //__android_log_print(ANDROID_LOG_INFO,"SMOKE_ENGINE","DELTA: \n");
}

void TestScene::Input(InputEvent* Event)
{

}
