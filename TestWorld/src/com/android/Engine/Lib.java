package com.android.Engine;
import android.content.res.AssetManager;
public class Lib {
	static{
		System.loadLibrary("TestWorld");
	}
	public static native void OnSurfaceChange(int width,int height);
	public static native void Initate();
	public static native void Step();
}
