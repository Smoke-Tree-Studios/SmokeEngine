#include <stdio.h>
#include <string.h>
#include <jni.h>
#include "android\log.h"
#include "Utility\Source.h"

extern "C" {
	JNIEXPORT void JNICALL Java_com_android_Engine_Lib_OnSurfaceChange(  JNIEnv* env, jobject obj,  jint width, jint height);
	JNIEXPORT void JNICALL Java_com_android_Engine_Lib_Step(  JNIEnv* env, jobject obj);
	JNIEXPORT void JNICALL Java_com_android_Engine_Lib_Initate(  JNIEnv* env, jobject obj);
}

JNIEXPORT void JNICALL Java_com_android_Engine_Lib_Initate(JNIEnv* env, jobject obj)
{
	 __android_log_print(ANDROID_LOG_INFO,"SMOKE_ENGINE","testing source");
	 Source* ls = new Source("/data/test.vs");
	 
}

JNIEXPORT void JNICALL Java_com_android_Engine_Lib_Step(JNIEnv* env, jobject obj)
{
	 
}

JNIEXPORT void JNICALL Java_com_android_Engine_Lib_OnSurfaceChange(JNIEnv* env, jobject obj,  jint width, jint height)
{

}

