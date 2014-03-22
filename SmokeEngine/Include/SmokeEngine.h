#pragma once
#include "Renderer\Renderer.h"
#include "SceneManager.h"
#include "android\asset_manager.h"
class SmokeEngine
{
private:


public:
	int * Width;
	int * Height;

	SceneManager * SceneMgr;
	Renderer* renderMgr;
	AAssetManager * assetManager;

	SmokeEngine(int* Width, int* Height,AAssetManager * AAsetmanager);
	~SmokeEngine(void);
};

