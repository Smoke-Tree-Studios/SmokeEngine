#include "TestScene.h"
#include <android\log.h>
#include "Node\ObjectNode.h"
#include "Render\RenderObject.h"
#include "Render\Sprite.h"
#include "Utility\Source.h"

#include "Utility\Vector\Vector3.h"
#include "Utility\WaveFrontLoad.h"

TestScene::TestScene(SmokeEngine* smokeEngine,Camera * camera) : SceneNode(smokeEngine,camera)
{
	
	Source * frag = new Source("red.fs",this->mSmokeEngine->mAssetManager);
	Sprite * s = new Sprite(this,frag);
	_testObject = new ObjectNode("test",s);
	this->mRootSceneNode->AppendNode(_testObject);
	_testObject->Position = Vector3(-1,-1,0);

}



TestScene::~TestScene(void)
{
}

void TestScene::Update(float deltaT) 
{
	 //__android_log_print(ANDROID_LOG_INFO,"SMOKE_ENGINE","DELTA: %f\n",deltaT);
}
