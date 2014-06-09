#include "SmokeEngine.h"
#include <btBulletDynamicsCommon.h>
#include "Storage/ShaderSourceStorage.h"
#include "Storage/TextureStorage.h"
#include "Storage/VertexBufferStorage.h"
#include "Audio/AudioManager.h"
#include "Storage/AudioSourceStorage.h"

#include "android\input.h"

SmokeEngine::SmokeEngine(AAssetManager * assetManager)
{
	
	mAudioManager = new AudioManager();
	mShaderSourceStorage = new ShaderSourceStorage();
	mTextureStorage = new TextureStorage();
	mVertexBufferStorage = new VertexBufferStorage();

	mAudioSourceStorage = new AudioSourceStorage();
	mRenderer = new Renderer();
	mAssetManager = assetManager;
	mSceneManager = new SceneManager(this);
	_time = clock();

}



SmokeEngine::~SmokeEngine(void)
{

}

void SmokeEngine::Step()
{
	
	float ldiff = ((((double)( clock() - _time))/CLOCKS_PER_SEC) * 1000.0);
	//updates the AudioManager
	mAudioManager->Update();
	mSceneManager->Update(ldiff);
	mRenderer->Draw(mSceneManager->GetActiveSceneNode());
	_time = clock();

	//processes events
	AInputQueue* queue;
	AInputEvent** events;
	AInputEvent* SingleEvent;
	int numberOfEvents = 0;
	while (AInputQueue_hasEvents(queue)) {
		AInputQueue_getEvent(queue, events);
		SingleEvent = events[0];
		
		mSceneManager->Input(queue,SingleEvent);
		AInputQueue_finishEvent(queue,SingleEvent,1);
	}

}
