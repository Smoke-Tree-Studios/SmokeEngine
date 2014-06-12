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

	struct timespec d;
    clock_gettime(CLOCK_MONOTONIC, &d);
	_time = (double)( d.tv_sec+ (d.tv_nsec / 1000000000.0));

}



SmokeEngine::~SmokeEngine(void)
{

}


void SmokeEngine::Step()
{
	
	struct timespec d;


    clock_gettime(CLOCK_MONOTONIC, &d);
	double ldiff = ((double)(( d.tv_sec + (d.tv_nsec / 1000000000.0)) - _time));
	_time = (double)( d.tv_sec+ (d.tv_nsec / 1000000000.0));
	//updates the AudioManager
	mAudioManager->Update();
	mSceneManager->Update(ldiff);
	Draw();

}

void SmokeEngine::Draw()
{
	glEnable(GL_DEPTH_TEST);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(0.0f,0.0f,0.0f,1.0f);
	mRenderer->Draw(mSceneManager->GetActiveSceneNode());
}

