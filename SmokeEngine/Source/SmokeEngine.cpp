#include "SmokeEngine.h"


SmokeEngine::SmokeEngine()
{
	mSceneManager = new SceneManager(this);
	mRenderer = new Renderer();

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
