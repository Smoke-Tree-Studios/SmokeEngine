#include "SmokeEngine.h"


SmokeEngine::SmokeEngine(int* Width, int* Height)
{
	Width = SmokeEngine::Width;
	Height = SmokeEngine::Height;

	SceneMgr = new SceneManager(this);
	renderMgr = new Renderer();
}



SmokeEngine::~SmokeEngine(void)
{
}
