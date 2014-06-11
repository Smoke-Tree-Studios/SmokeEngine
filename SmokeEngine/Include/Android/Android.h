#pragma once
#include "stdint.h"
#include <EGL/egl.h>
#include <gles2/gl2.h>
class android_app;
class SmokeEngine;

class Android
{
public:

	EGLDisplay _display;
	EGLSurface _surface;
	EGLContext _context;
	android_app* _android;
	int _width;
	int _height;
	SmokeEngine * smokeEngine;

	//function intalizer
	void (*Initialize_Engine)(SmokeEngine * engine);
	Android(struct android_app* android);
	void Start();
	~Android(void);
};

