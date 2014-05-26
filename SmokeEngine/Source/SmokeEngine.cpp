#include "SmokeEngine.h"
#include <btBulletDynamicsCommon.h>

SmokeEngine::SmokeEngine(AAssetManager * assetManager)
{
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
