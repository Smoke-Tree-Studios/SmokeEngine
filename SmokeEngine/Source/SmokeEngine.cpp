#include "SmokeEngine.h"
#include <btBulletDynamicsCommon.h>
#include "Storage/ShaderSourceStorage.h"
#include "Storage/TextureStorage.h"
#include "Storage/VertexBufferStorage.h"
#include "Audio/AudioManager.h"
#include "Storage/AudioSourceStorage.h"

SmokeEngine::SmokeEngine(AAssetManager * assetManager)
{
	
	mShaderSourceStorage = new ShaderSourceStorage();
	mTextureStorage = new TextureStorage();
	mVertexBufferStorage = new VertexBufferStorage();
	mAudioManager = new AudioManager();

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
	float ldiff = (((float)( clock() - _time))/CLOCKS_PER_SEC) * 1000.0;
	mSceneManager->Update(ldiff);
	mRenderer->Draw(mSceneManager->GetActiveSceneNode());
	_time = clock();

}
