package com.example.admin.testandroidapp;

import android.content.Context;
import android.opengl.GLSurfaceView;
import android.util.AttributeSet;

import java.util.concurrent.TimeUnit;

/**
 * Created by Admin on 09.12.2017.
 */

public class OpenGLView extends GLSurfaceView {

    private OpenGLRenderer openGLRenderer = new OpenGLRenderer();

    public OpenGLView(Context context) {
        super(context);
        init();
    }

    public OpenGLView(Context context, AttributeSet attrs) {
        super(context, attrs);
        init();
    }

    private void init(){
        setEGLContextClientVersion(2);
        setPreserveEGLContextOnPause(true);
        setRenderer(openGLRenderer);
    }

    public void clearTimes(){
        openGLRenderer.clearTimes();
    }

    public int getTimes(){
        return openGLRenderer.getTimes();
    }
}
