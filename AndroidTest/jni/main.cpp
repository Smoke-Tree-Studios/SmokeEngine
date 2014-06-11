/*
 * Copyright (C) 2010 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 */

//BEGIN_INCLUDE(all)
#include <jni.h>
#include <errno.h>

//#include <EGL/egl.h>
#include <gles2/gl2.h>

#include <android/sensor.h>
#include <android/log.h>
#include "Android/android_native_app_glue.h"
#include "Android/Android.h"

#include "SmokeEngine.h"
#include "TestScene.h"
#include "Utility\Camera.h"

#define LOGI(...) ((void)__android_log_print(ANDROID_LOG_INFO, "native-activity", __VA_ARGS__))
#define LOGW(...) ((void)__android_log_print(ANDROID_LOG_WARN, "native-activity", __VA_ARGS__))




namespace boost
{
	void throw_exception(std::exception const&)
	{
	}
};


static Android* _android;


static void Initialize_Engine(SmokeEngine * engine)
{
		engine->mSceneManager->AppendScene("main",new TestScene(engine,new Camera(3.14f/2.0f,1,.5f,20)));
		engine->mSceneManager->SetActiveScene("main");
}

/**
 * This is the main entry point of a native application that is using
 * android_native_app_glue.  It runs in its own thread, with its own
 * event loop for receiving input events and doing other things.
 */
void android_main(struct android_app* state) {
   
	app_dummy();
	_android = new Android(state);
	_android->Initialize_Engine = Initialize_Engine;
	_android->Start();

}

