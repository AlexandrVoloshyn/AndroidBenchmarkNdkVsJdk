package com.example.admin.testandroidapp;

/**
 * Created by Admin on 19.01.2018.
 */

public class GL2JNILib {

    static {
        System.loadLibrary("gl2jni");
    }

    /**
     * @param width the current view width
     * @param height the current view height
     */
    public static native void init(int width, int height);
    public static native void step();
}