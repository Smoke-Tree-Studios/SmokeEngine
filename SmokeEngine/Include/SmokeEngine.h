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
class AudioSourceStorage;
class AudioManager;
class SmokeEngine
{
private:
	 clock_t _time;
public:
	int * Width;
	int * Height;

	AudioSourceStorage * mAudioSourceStorage;
	ShaderSourceStorage * mShaderSourceStorage;
	TextureStorage * mTextureStorage;
	VertexBufferStorage * mVertexBufferStorage;

	AudioManager * mAudioManager;
	SceneManager * mSceneManager;
	AAssetManager * mAssetManager;
	Renderer* mRenderer;
	

	void Step();

	SmokeEngine(AAssetManager * assetManager);
	~SmokeEngine(void);
};

