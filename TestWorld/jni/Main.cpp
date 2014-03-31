#include <stdio.h>
#include <string.h>
#include <jni.h>
#include "android\log.h"
#include "Utility\Texture.h"
#include "android\asset_manager.h"
#include "android\asset_manager_jni.h"
#include "VertexObject\WaveFrontLoad.h"
#include "SmokeEngine.h"
#include "VertexObject\VertexArrayObject.h"
#include "VertexObject\VertexBufferObjectWithSubData.h"

extern "C" {
	JNIEXPORT void JNICALL Java_com_android_Engine_Lib_OnSurfaceChange(  JNIEnv* env, jobject obj,  jint width, jint height);
	JNIEXPORT void JNICALL Java_com_android_Engine_Lib_Step(  JNIEnv* env, jobject obj);
	JNIEXPORT void JNICALL Java_com_android_Engine_Lib_Initate(  JNIEnv* env, jobject obj,jobject assetmanager);
}

AAssetManager * mAssetManager;
SmokeEngine * s;
JNIEXPORT void JNICALL Java_com_android_Engine_Lib_Initate(JNIEnv* env, jobject obj,jobject assetmanager)
{
	s = new SmokeEngine();
	mAssetManager = AAssetManager_fromJava(env,assetmanager);
	// __android_log_print(ANDROID_LOG_INFO,"SMOKE_ENGINE","testing source");
	//Texture* t = new Texture("lice1.png",mAssetManager);
	WaveFrontLoad::Load("drag.wobj",mAssetManager,new VertexBufferObjectWithSubData());
	 
}

JNIEXPORT void JNICALL Java_com_android_Engine_Lib_Step(JNIEnv* env, jobject obj)
{
	 
}

JNIEXPORT void JNICALL Java_com_android_Engine_Lib_OnSurfaceChange(JNIEnv* env, jobject obj,  jint width, jint height)
{

}

