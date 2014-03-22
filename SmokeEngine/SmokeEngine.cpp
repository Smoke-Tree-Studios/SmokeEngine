#include "SmokeEngine.h"


SmokeEngine::SmokeEngine(int* Width, int* Height,AAssetManager * AAsetmanager)
{
	Width = SmokeEngine::Width;
	Height = SmokeEngine::Height;
	assetManager = AAsetmanager;

	SceneMgr = new SceneManager();
	renderMgr = new Renderer();
}



SmokeEngine::~SmokeEngine(void)
{
}
