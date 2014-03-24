package com.android.Engine;

import android.app.Activity;
import android.widget.TextView;
import android.os.Bundle;


public class MainActivity extends Activity 
{
	private View _view;

    @Override protected void onCreate(Bundle bundle) {
        super.onCreate(bundle);
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
