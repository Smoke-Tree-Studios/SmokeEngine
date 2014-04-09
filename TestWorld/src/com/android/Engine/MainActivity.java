package com.android.Engine;

import android.app.Activity;
import android.content.res.AssetManager;
import android.widget.TextView;
import android.os.Bundle;


public class MainActivity extends Activity 
{
	private View _view;
	private AssetManager _assetManager;
    @Override protected void onCreate(Bundle bundle) {
        super.onCreate(bundle);
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
