#pragma once
#include "Renderer\Renderer.h"
#include "SceneManager.h"
#include "android\asset_manager.h"

class SceneManager;
class SmokeEngine
{
private:


public:
	int * Width;
	int * Height;

	SceneManager * SceneMgr;
	Renderer* renderMgr;

	SmokeEngine(int* Width, int* Height);
	~SmokeEngine(void);
};

