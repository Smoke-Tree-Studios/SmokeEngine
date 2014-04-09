#include "TestScene.h"
#include <android\log.h>
#include "Node\ObjectNode.h"
#include "Render\RenderObject.h"
#include "Render\Sprite.h"
#include "Utility\Source.h"

TestScene::TestScene(SmokeEngine* smokeEngine,Camera * camera) : SceneNode::SceneNode(smokeEngine,camera)
{
	
	Source * frag = new Source("julianset.fs",this->mSmokeEngine->mAssetManager);
	Sprite * s = new Sprite(this,frag);
	ltestObject = new ObjectNode("test",s);
	this->mRootSceneNode->AppendNode(ltestObject);
}



TestScene::~TestScene(void)
{
}

void TestScene::Update(float deltaT) 
{
	 //__android_log_print(ANDROID_LOG_INFO,"SMOKE_ENGINE","DELTA: %f\n",deltaT);
}
