package com.android.Engine;

import android.app.Activity;
import android.content.res.AssetManager;
import android.view.Window;
import android.view.WindowManager;
import android.widget.TextView;
import android.os.Bundle;


public class MainActivity extends Activity 
{
	private View _view;
	private AssetManager _assetManager;
    @Override protected void onCreate(Bundle bundle) {
        super.onCreate(bundle);
        
      //Remove title bar
        this.requestWindowFeature(Window.FEATURE_NO_TITLE);

        //Remove notification bar
        this.getWindow().setFlags(WindowManager.LayoutParams.FLAG_FULLSCREEN, WindowManager.LayoutParams.FLAG_FULLSCREEN);
        
		_assetManager = this.getAssets();
        Lib.Initate(_assetManager);
        
    	_view = new View(getApplication());
		setContentView(_view);
    }

    @Override protected void onPause() {
        super.onPause();
        _view.onPause();
    }


    
    @Override protected void onResume() {
        super.onResume();
        _view.onResume();
    }

}
