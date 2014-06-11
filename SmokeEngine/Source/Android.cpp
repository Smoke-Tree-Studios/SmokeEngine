#include "Android/Android.h"
#include "Android/android_native_app_glue.h"
#include "SmokeEngine.h"
#include "S_Debug.h"




static void Intalize_Display(struct android_app* app,Android * container)
{
	  EGLConfig lconfig;
	  EGLint lnumConfigs;
	  EGLint lformat;

	 const EGLint attribs[] = {
	    EGL_SURFACE_TYPE, EGL_WINDOW_BIT,
        EGL_BLUE_SIZE, 8,
        EGL_GREEN_SIZE, 8,
        EGL_RED_SIZE, 8,
		EGL_DEPTH_SIZE,8,
        EGL_NONE
    };
	 
    container->_display = eglGetDisplay(EGL_DEFAULT_DISPLAY);

    eglInitialize(container->_display, 0, 0);

    /* Here, the application chooses the configuration it desires. In this
     * sample, we have a very simplified selection process, where we pick
     * the first EGLConfig that matches our criteria */
    eglChooseConfig(container->_display, attribs, &lconfig, 1, &lnumConfigs);

    /* EGL_NATIVE_VISUAL_ID is an attribute of the EGLConfig that is
     * guaranteed to be accepted by ANativeWindow_setBuffersGeometry().
     * As soon as we picked a EGLConfig, we can safely reconfigure the
     * ANativeWindow buffers to match, using EGL_NATIVE_VISUAL_ID. */
    eglGetConfigAttrib(container->_display, lconfig, EGL_NATIVE_VISUAL_ID, &lformat);
	
   // ANativeWindow_setBuffersGeometry(engine->app->window, 0, 0, format);

    container->_surface = eglCreateWindowSurface(container->_display, lconfig, app->window, NULL);

	EGLint contextAttrs[] = { EGL_CONTEXT_CLIENT_VERSION, 2, EGL_NONE };
	
    container->_context = eglCreateContext(container->_display, lconfig, NULL, contextAttrs);
	
    if (eglMakeCurrent(container->_display, container->_surface, container->_surface, container->_context) == EGL_FALSE) {
        ERROR("Unable to eglMakeCurrent");
       // return -1;
    }
	
    eglQuerySurface(container->_display, container->_surface, EGL_WIDTH, &container->_width);
    eglQuerySurface(container->_display, container->_surface, EGL_HEIGHT, &container->_height);
}


static void android_handle_cmd(struct android_app* app, int32_t cmd) {
     Android* landroid = ((Android*)app->userData);
	switch (cmd) {
        case APP_CMD_SAVE_STATE:

            break;
        case APP_CMD_INIT_WINDOW:
            // The window is being shown, get it ready.
			
            if (app->window != NULL) {
				Intalize_Display(app,landroid);

				landroid->smokeEngine = new SmokeEngine(app->activity->assetManager);
				if(landroid->Initialize_Engine != NULL)
				 landroid->Initialize_Engine(landroid->smokeEngine);
				landroid->smokeEngine->Draw();
                //engine_draw_frame(engine);
            }
            break;
        case APP_CMD_TERM_WINDOW:
            // The window is being hidden or closed, clean it up.
           // engine_term_display(engine);
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

/**
 * Tear down the EGL context currently associated with the display.
 */
static void engine_term_display(Android * container) {

	if (container->_display != EGL_NO_DISPLAY) {
        eglMakeCurrent(container->_display, EGL_NO_SURFACE, EGL_NO_SURFACE, EGL_NO_CONTEXT);
		
        if (container->_context != EGL_NO_CONTEXT) {
			eglDestroyContext(container->_display, container->_context);
        }
		if (container->_surface != EGL_NO_SURFACE) {
            eglDestroySurface(container->_display, container->_surface);
        }
        eglTerminate(container->_display);
    }
    container->_display = EGL_NO_DISPLAY;
    container->_context = EGL_NO_CONTEXT;
    container->_surface = EGL_NO_SURFACE;
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
				source->process(this->_android, source);
            }

			  // Check if we are exiting.
            if (this->_android->destroyRequested != 0) {
                engine_term_display(this);
                return;
            }
		 }


		if(this->smokeEngine != NULL && this->_display != NULL)
		 {
			this->smokeEngine->Step();
			eglSwapBuffers(this->_display, this->_surface);
	
		 }
	}
}

Android::Android(struct android_app* android)
{
	_android = android;
	android->userData = this;
	_android->onAppCmd = android_handle_cmd;

	this->smokeEngine = NULL;
	this->Initialize_Engine = NULL;
}


Android::~Android(void)
{
}
