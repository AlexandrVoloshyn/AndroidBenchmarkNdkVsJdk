#include <jni.h>
#include "Fibonacci.h"

//extern "C"
//JNIEXPORT jstring JNICALL
//Java_com_example_admin_testandroidapp_MainActivity_stringFromJNI(
//        JNIEnv* env,
//        jobject /* this */) {
//    std::string hello = "Hello from C++";
//    return env->NewStringUTF(hello.c_str());
//}

//extern "C"

extern "C" {
//    JNIEXPORT jlong JNICALL
//    Java_com_example_admin_testandroidapp_MainActivity_fibonacci(
//            JNIEnv *env,
//            jobject jobj,
//            jstring num){
//        Fibonacci *fibonacci = new Fibonacci();
//        return 1;// fibonacci->getFibonacci(num);
//    }

    JNIEXPORT jint Java_com_example_admin_testandroidapp_MainActivity_fibo(JNIEnv * env, jobject obj, jint num){
        jint result=num;
        Fibonacci *fibonacci = new Fibonacci();
        result = fibonacci->getFibonacci(result);

        return result;
}

}
