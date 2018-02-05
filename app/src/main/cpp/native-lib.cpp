#include <jni.h>
#include "Fibonacci.h"
#include <iostream>

extern "C" {

    JNIEXPORT jint Java_com_example_admin_testandroidapp_MainActivity_fibo(JNIEnv * env, jobject obj, jint num){
        int result=30;

        for( int i = num; i != 0; --i) {
            (new Fibonacci())->getFibonacci(result);
        }
        return (new Fibonacci())->getFibonacci(result);
}


JNIEXPORT void Java_com_example_admin_testandroidapp_MainActivity_write(JNIEnv * env, jobject obj){
        FILE *file = fopen("/sdcard/newFile.txt","w+");

        for(int i = 0; i < 10000; ++i)
            fputs("Hello world!\n", file);
        fflush(file);
        fclose(file);
}
}
