package com.android.Engine;
import android.content.res.AssetManager;
public class Lib {
	static{
		System.load("Test");
	}
	public static native void OnSurfaceChange(int width,int height);
	public static native void Initate(AssetManager Assetmanager);
	public static native void Step();
}
