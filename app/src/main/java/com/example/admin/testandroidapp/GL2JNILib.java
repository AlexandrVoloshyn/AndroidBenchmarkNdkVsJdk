package com.example.admin.testandroidapp;

public class GL2JNILib {

    static {
        System.loadLibrary("gl2jni");
    }

    public static native void init(int width, int height);
    public static native void step();
    public static native void clearTimer();
    public static native int getTimer();
}