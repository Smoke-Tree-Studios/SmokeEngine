#pragma once
#include "Render\Renderer.h"
#include "SceneManager.h"
#include "android\asset_manager.h"
#include <time.h>
class btDiscreteDynamicsWorld;
class AAssetManager;
class SceneManager;
class ShaderSourceStorage;
class TextureStorage;
class VertexBufferStorage;
class SmokeEngine
{
private:
	 clock_t _time;
public:
	int * Width;
	int * Height;

	ShaderSourceStorage * mShaderSourceStorage;
	TextureStorage * mTextureStorage;
	VertexBufferStorage * mVertexBufferStorage;

	SceneManager * mSceneManager;
	AAssetManager * mAssetManager;
	Renderer* mRenderer;
	

	void Step();

	SmokeEngine(AAssetManager * assetManager);
	~SmokeEngine(void);
};

