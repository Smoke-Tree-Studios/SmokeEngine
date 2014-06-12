#pragma once
#include "stdint.h"
#include <EGL/egl.h>
#include <gles2/gl2.h>
class android_app;
class SmokeEngine;

class Android
{
public:

	EGLDisplay mDisplay;
	EGLSurface mSurface;
	EGLContext mContext;
	android_app* mAndroid;
	int mWidth;
	int mHeigh;
	SmokeEngine * mSmokeEngine;

	//function intalizer
	void (*Initialize_Engine)(SmokeEngine * engine);
	Android(struct android_app* android);
	void Start();
	~Android(void);
};

