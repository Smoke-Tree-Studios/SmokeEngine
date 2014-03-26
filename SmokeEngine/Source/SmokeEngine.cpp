#include "SmokeEngine.h"


SmokeEngine::SmokeEngine()
{

	mSceneManager = new SceneManager(this);
	mRenderer = new Renderer();
}



SmokeEngine::~SmokeEngine(void)
{
	
}
