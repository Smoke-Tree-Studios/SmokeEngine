#pragma once
#include "Render\Renderer.h"
#include "SceneManager.h"
#include "android\asset_manager.h"

#include <time.h>
class AAssetManager;
class SceneManager;
class SmokeEngine
{
private:
	 clock_t _time;
public:
	int * Width;
	int * Height;

	SceneManager * mSceneManager;
	AAssetManager * mAssetManager;
	Renderer* mRenderer;

	void Step();

	SmokeEngine(AAssetManager * assetManager);
	~SmokeEngine(void);
};

