#include "SmokeEngine.h"
#include "Storage/ShaderSourceStorage.h"
#include "Storage/TextureStorage.h"
#include "Storage/VertexBufferStorage.h"
#include "Audio/AudioManager.h"
#include "Storage/AudioSourceStorage.h"

#include "android/input.h"
#include "Input/InputEvent.h"


#include <EGL/egl.h>
#include <GLES/gl.h>

#include <jni.h>
#include <android/sensor.h>
#include <android/log.h>

SmokeEngine::SmokeEngine(AAssetManager * AssetManager)
{
	
	mAudioManager = new AudioManager();
	mShaderSourceStorage = new ShaderSourceStorage();
	mTextureStorage = new TextureStorage();
	mVertexBufferStorage = new VertexBufferStorage();

	mAudioSourceStorage = new AudioSourceStorage();
	mRenderer = new Renderer();
	mAssetManager =AssetManager;
	mSceneManager = new SceneManager(this);
	_time = clock();

}



SmokeEngine::~SmokeEngine(void)
{

}


void SmokeEngine::Step()
{
	
	double ldiff = ((((double)( clock() - _time))/CLOCKS_PER_SEC) * 1000.0);
	//updates the AudioManager
	this->Draw();
	mAudioManager->Update();
	mSceneManager->Update(ldiff);
	_time = clock();
	

	/*AInputEvent** events;
	AInputEvent* SingleEvent;
	int numberOfEvents = 0;
	while (AInputQueue_hasEvents(_queue)) {
		AInputQueue_getEvent(_queue, events);
		SingleEvent = events[0];

		InputEvent * levent = new InputEvent(SingleEvent);
		mSceneManager->Input(levent);
		delete(levent);

		AInputQueue_finishEvent(_queue,SingleEvent,1);
	}*/

}

void SmokeEngine::Draw()
{
	glEnable(GL_DEPTH_TEST);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(0.0f,0.0f,0.0f,1.0f);
	mRenderer->Draw(mSceneManager->GetActiveSceneNode());
}

