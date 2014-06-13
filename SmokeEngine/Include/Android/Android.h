#pragma once
#include "stdint.h"
#include <EGL/egl.h>
#include <gles2/gl2.h>
class android_app;
class SmokeEngine;

struct SavedData
{
	SmokeEngine * mSmokeEngine;
};


struct UserData
{
	EGLDisplay mDisplay;
	EGLSurface mSurface;
	EGLContext mContext;
	int mWidth;
	int mHeigh;
	//function intalizer
	void (*Initialize_Engine)(SmokeEngine * engine);
	SavedData mSavedData;
};

class Android
{
private:
public:
	UserData * _userData;
	
	android_app* mAndroid;

	Android(struct android_app* android);
	void Start();
	~Android(void);
};

