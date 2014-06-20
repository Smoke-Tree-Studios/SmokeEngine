#include "Android/Android.h"
#include "Android/android_native_app_glue.h"
#include "SmokeEngine.h"
#include "S_Debug.h"
#include "Input/InputEvent.h"
#include "S_Debug.h"
#include "Node/SceneNode.h"
#include "Audio/AudioManager.h"
#include "Storage/Storage.h"
/**
 * Tear down the EGL context currently associated with the display.
 */
static void TerminateDisplay(UserData* container) {

	if (container->mDisplay != EGL_NO_DISPLAY) {
        eglMakeCurrent(container->mDisplay, EGL_NO_SURFACE, EGL_NO_SURFACE, EGL_NO_CONTEXT);
		
        if (container->mContext != EGL_NO_CONTEXT) {
			eglDestroyContext(container->mDisplay, container->mContext);
        }
		if (container->mSurface != EGL_NO_SURFACE) {
            eglDestroySurface(container->mDisplay, container->mSurface);
        }
        eglTerminate(container->mDisplay);
    }
    container->mDisplay = EGL_NO_DISPLAY;
    container->mContext = EGL_NO_CONTEXT;
    container->mSurface = EGL_NO_SURFACE;
}

static void IntalizeDisplay(struct android_app* app,UserData * container)
{
	  EGLConfig lconfig;
	  EGLint lnumConfigs;
	  EGLint lformat;

	 const EGLint attribs[] = {
	    EGL_RENDERABLE_TYPE, EGL_OPENGL_ES2_BIT ,
        EGL_BLUE_SIZE, 8,
        EGL_GREEN_SIZE, 8,
        EGL_RED_SIZE, 8,
		EGL_ALPHA_SIZE, 0,
		EGL_DEPTH_SIZE,16,
        EGL_NONE
    };
	 
    container->mDisplay = eglGetDisplay(EGL_DEFAULT_DISPLAY);

    eglInitialize(container->mDisplay, 0, 0);

    /* Here, the application chooses the configuration it desires. In this
     * sample, we have a very simplified selection process, where we pick
     * the first EGLConfig that matches our criteria */
    eglChooseConfig(container->mDisplay, attribs, &lconfig, 1, &lnumConfigs);

    /* EGL_NATIVE_VISUAL_ID is an attribute of the EGLConfig that is
     * guaranteed to be accepted by ANativeWindow_setBuffersGeometry().
     * As soon as we picked a EGLConfig, we can safely reconfigure the
     * ANativeWindow buffers to match, using EGL_NATIVE_VISUAL_ID. */
    eglGetConfigAttrib(container->mDisplay, lconfig, EGL_NATIVE_VISUAL_ID, &lformat);

	ANativeWindow_setBuffersGeometry(app->window, 0, 0, lformat);

	EGLint contextAttrs[] = { EGL_CONTEXT_CLIENT_VERSION, 2, EGL_NONE };
	
	container->mSurface = eglCreateWindowSurface(container->mDisplay, lconfig, app->window, NULL);
    container->mContext = eglCreateContext(container->mDisplay, lconfig, NULL, contextAttrs);
	
    if (eglMakeCurrent(container->mDisplay, container->mSurface, container->mSurface, container->mContext) == EGL_FALSE) {
        ERROR("Unable to eglMakeCurrent");
       // return -1;
    }
	
    eglQuerySurface(container->mDisplay, container->mSurface, EGL_WIDTH, &container->mWidth);
	eglQuerySurface(container->mDisplay, container->mSurface, EGL_HEIGHT, &container->mHeigh);

}


static void Android_Handle_Cmd(struct android_app* app, int32_t cmd) {
	UserData* lUserData = ((UserData*)app->userData);
	
	switch (cmd) {
        case APP_CMD_SAVE_STATE:
			{
		
				//unloads all the scenes
				std::list<std::string> lSceneIds = lUserData->mSavedData.mSmokeEngine->mSceneManager->GetSceneIds();
				for (std::list<std::string>::const_iterator iterator = lSceneIds.begin(); iterator != lSceneIds.end(); ++iterator) {
					lUserData->mSavedData.mSmokeEngine->mSceneManager->GetSceneNode(*iterator)->UnLoad();
				}
				lUserData->mSavedData.mSmokeEngine->mTextureStorage->~TextureStorage();
				lUserData->mSavedData.mSmokeEngine->mShaderSourceStorage->~ShaderSourceStorage();
				lUserData->mSavedData.mSmokeEngine->mAudioSourceStorage->~AudioSourceStorage();
				lUserData->mSavedData.mSmokeEngine->mVertexBufferStorage->~VertexBufferStorage();

				lUserData->mSavedData.mSmokeEngine->mAudioManager->ClearAudioBuffer();

				
				app->savedState = malloc(sizeof(struct SavedData));
				*((struct SavedData*)app->savedState) = lUserData->mSavedData;
				app->savedStateSize = sizeof(struct SavedData);
			}

            break;

		case APP_CMD_RESUME:
   			 ERROR("Loading From UserData");
			 if(app->savedState != NULL)
			 {
				lUserData->mSavedData = *((struct SavedData*)app->savedState);
			 }

         break;
        case APP_CMD_INIT_WINDOW:
            // The window is being shown, get it ready.
			
            if (app->window != NULL)
				IntalizeDisplay(app,lUserData);

				lUserData->mSavedData.mSmokeEngine->Width = &lUserData->mWidth;
				lUserData->mSavedData.mSmokeEngine->Height = &lUserData->mHeigh;
	

				if(lUserData->Initialize_Engine != NULL )
				{
					lUserData->Initialize_Engine(lUserData->mSavedData.mSmokeEngine);
					lUserData->mSavedData.mSmokeEngine->Draw();
				}
				else
				{
					 if(lUserData->mSavedData.mSmokeEngine->mSceneManager->GetActiveSceneNode() != NULL)
					 {
						lUserData->mSavedData.mSmokeEngine->mSceneManager->GetActiveSceneNode()->Load();
						lUserData->mSavedData.mSmokeEngine->mSceneManager->GetActiveSceneNode()->InintalizeScene();
					 }
				}
				lUserData->Initialize_Engine =NULL;
           
            break;
        case APP_CMD_TERM_WINDOW:
			
            // The window is being hidden or closed, clean it up.
            TerminateDisplay(lUserData);
		
			
            break;
        case APP_CMD_GAINED_FOCUS:
            // When our app gains focus, we start monitoring the accelerometer.
          /* if (engine->accelerometerSensor != NULL) {
                ASensorEventQueue_enableSensor(engine->sensorEventQueue,
                        engine->accelerometerSensor);
                // We'd like to get 60 events per second (in us).
                ASensorEventQueue_setEventRate(engine->sensorEventQueue,
                        engine->accelerometerSensor, (1000L/60)*1000);
            }*/
            break;
        case APP_CMD_LOST_FOCUS:
            // When our app loses focus, we stop monitoring the accelerometer.
            // This is to avoid consuming battery while not being used.
          /*  if (engine->accelerometerSensor != NULL) {
                ASensorEventQueue_disableSensor(engine->sensorEventQueue,
                        engine->accelerometerSensor);
            }
            // Also stop animating.
            engine->animating = 0;
            engine_draw_frame(engine);*/
            break;
    }
}

static int32_t Android_Handle_input(struct android_app* app, AInputEvent* event) {
	//SavedData* lSavedData = ((SavedData*)app->savedState);
	UserData lUserData = *((UserData*)app->userData);

	InputEvent * levent = new InputEvent(event);
	lUserData.mSavedData.mSmokeEngine->mSceneManager->Input(levent);
	delete(levent); 

    return 1;
}





void Android::Start()
{
	// Read all pending events.
    int ident;
    int events;
    struct android_poll_source* source;

	while(1)
	{

		 while ((ident=ALooper_pollAll(0, NULL, &events,(void**)&source)) >= 0) {
			  // Process this event.
            if (source != NULL) {
				source->process(this->mAndroid, source);
            }

			  // Check if we are exiting.
            if (this->mAndroid->destroyRequested) {
				TerminateDisplay(this->_userData);
                return;
            }
		 }
		if( this->_userData->mDisplay != NULL)
		{
			this->_userData->mSavedData.mSmokeEngine->Step();
			eglSwapBuffers(this->_userData->mDisplay, this->_userData->mSurface);

		}

	}
}

Android::Android(struct android_app* android)
{
	this->_userData = new UserData();
	android->userData = this->_userData;
	
	 if (android->savedState != NULL) {
		 ERROR("Loading From UserData");
        // We are starting with a previous saved state; restore from it.
		 this->_userData->mSavedData = *((struct SavedData*)android->savedState);
		 this->_userData->mSavedData.mSmokeEngine->mSceneManager->GetActiveSceneNode()->Load();
		 this->_userData->mSavedData.mSmokeEngine->mSceneManager->GetActiveSceneNode()->InintalizeScene();
		 
    }
	else
	{
		ERROR("new");
		 this->_userData->mSavedData.mSmokeEngine = new SmokeEngine(android->activity->assetManager);

	}

	this->_userData->Initialize_Engine = NULL;

	mAndroid = android;
	mAndroid->onAppCmd = Android_Handle_Cmd;
	mAndroid->onInputEvent = Android_Handle_input;
}


Android::~Android(void)
{
}
