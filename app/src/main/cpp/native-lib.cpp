#include <jni.h>
#include <iostream>

int getFibonacci(int num){
    if (num == 1)
        return 1;
    if (num == 0)
        return 0;
    return getFibonacci(num - 1) + getFibonacci(num - 2);
}

extern "C" {

JNIEXPORT jint Java_com_example_admin_testandroidapp_MainActivity_fibo(JNIEnv * env, jobject obj, jint num){
        int result=40;
        int times = num;
        for( int i = times; i != 1; --i) {
            getFibonacci(result);
        }
        return getFibonacci(result);
}


JNIEXPORT void Java_com_example_admin_testandroidapp_MainActivity_write(JNIEnv * env, jobject obj){
        FILE *file = fopen("/sdcard/newFile.txt","w+");

        for(int i = 0; i < 1000000; ++i)
            fputs("Hello world!\n", file);
        fflush(file);
        fclose(file);
}
}
