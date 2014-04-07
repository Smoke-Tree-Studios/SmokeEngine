package com.android.Engine;

import android.content.Context;
import android.graphics.PixelFormat;
import android.opengl.GLES20;
import android.opengl.GLSurfaceView;
import android.util.AttributeSet;
import android.util.Log;
import android.view.KeyEvent;
import android.view.MotionEvent;

import javax.microedition.khronos.egl.EGL10;
import javax.microedition.khronos.egl.EGLConfig;
import javax.microedition.khronos.egl.EGLContext;
import javax.microedition.khronos.egl.EGLDisplay;
import javax.microedition.khronos.opengles.GL10;

import android.opengl.GLES20;

public class GLRenderer implements GLSurfaceView.Renderer {

	public GLRenderer() {

	}

	@Override
	public void onDrawFrame(GL10 arg0) {

		Lib.Step();
	}

	@Override
	public void onSurfaceChanged(GL10 gl, int width, int height) {
		Lib.OnSurfaceChange(width, height);
	}

	@Override
	public void onSurfaceCreated(GL10 gl, EGLConfig config) {
	}

}