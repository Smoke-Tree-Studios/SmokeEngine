#pragma once
#include "Render\Renderer.h"
#include "SceneManager.h"
#include "android\asset_manager.h"

class Renderer;
class SceneManager;
class SmokeEngine
{
private:


public:
	int * Width;
	int * Height;

	SceneManager * mSceneManager;
	Renderer* mRenderer;

	SmokeEngine();
	~SmokeEngine(void);
};

