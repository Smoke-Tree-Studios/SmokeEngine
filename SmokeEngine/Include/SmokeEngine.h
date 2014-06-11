#pragma once
#include "Render\Renderer.h"
#include "SceneManager.h"
#include "android\asset_manager.h"
#include <time.h>

#include <EGL/egl.h>
#include <GLES/gl.h>

#include <jni.h>
#include <android/sensor.h>
#include <android/log.h>
#include <ctime>
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
	 double _time;

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
	void Draw();

	SmokeEngine(AAssetManager * assetManager);
	~SmokeEngine(void);
};

