#include <stdio.h>
#include <string.h>
#include <jni.h>
#include "android\log.h"
#include "Utility\Texture.h"
#include "android\asset_manager.h"
#include "android\asset_manager_jni.h"
#include "Utility\WaveFrontLoad.h"
#include "SmokeEngine.h"
#include "VertexObject\VertexArrayObject.h"
#include "VertexObject\VertexBufferObjectWithSubData.h"
#include "S_Debug.h"
#include "TestScene.h"

namespace boost
{
	void throw_exception(std::exception const&)
	{
	}
};

extern "C" {
	JNIEXPORT void JNICALL Java_com_android_Engine_Lib_OnSurfaceChange(  JNIEnv* env, jobject obj,  jint width, jint height);
	JNIEXPORT void JNICALL Java_com_android_Engine_Lib_Step(  JNIEnv* env, jobject obj);
	JNIEXPORT void JNICALL Java_com_android_Engine_Lib_Initate(  JNIEnv* env, jobject obj,jobject assetmanager);
	JNIEXPORT void JNICALL Java_com_android_Engine_Lib_OpenglInitiate(  JNIEnv* env, jobject obj);
}

AAssetManager * mAssetManager;
SmokeEngine * s;
bool load = false;
JNIEXPORT void JNICALL Java_com_android_Engine_Lib_Initate(JNIEnv* env, jobject obj,jobject assetmanager)
{
	mAssetManager = AAssetManager_fromJava(env,assetmanager);
	s = new SmokeEngine(mAssetManager);
	 //__android_log_print(ANDROID_LOG_INFO,"SMOKE_ENGINE","testing source");
	//Texture* t = new Texture("lice1.png",mAssetManager);
	//VertexBufferObjectWithSubData * v = new VertexBufferObjectWithSubData();
	//WaveFrontLoad::Load("drag.wobj",mAssetManager,v);

	 
}

JNIEXPORT void JNICALL Java_com_android_Engine_Lib_OpenglInitiate(  JNIEnv* env, jobject obj)
{
	s->mSceneManager->AppendScene("main",new TestScene(s,new Camera(3.14f/2.0f,1,.5f,20)));
	s->mSceneManager->SetActiveScene("main");
}

JNIEXPORT void JNICALL Java_com_android_Engine_Lib_Step(JNIEnv* env, jobject obj)
{
	glEnable(GL_DEPTH_TEST);

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(0.0f,0.0f,0.0f,1.0f);
	s->Step(); 
}

JNIEXPORT void JNICALL Java_com_android_Engine_Lib_OnSurfaceChange(JNIEnv* env, jobject obj,  jint width, jint height)
{
	
}

