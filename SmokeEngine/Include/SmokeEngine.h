#pragma once
#include "Render\Renderer.h"
#include "SceneManager.h"
#include "android\asset_manager.h"

#include <time.h>

class SceneManager;
class SmokeEngine
{
private:
	 clock_t _time;
public:
	int * Width;
	int * Height;

	SceneManager * mSceneManager;
	Renderer* mRenderer;

	void Step();

	SmokeEngine();
	~SmokeEngine(void);
};

