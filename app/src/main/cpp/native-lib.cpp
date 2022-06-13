#include <jni.h>
#include <string>

extern "C" JNIEXPORT jstring JNICALL
Java_com_zqf_jniseries_MainActivity_stringFromJNI(
        JNIEnv *env,
        jobject /* this */) {
    std::string hello = "Hello from C++";
    return env->NewStringUTF(hello.c_str());
}

/**
 * Native 声明方法  Java_包名_类名_函数名
 */
extern "C" JNIEXPORT void JNICALL
Java_com_zqf_jniseries_MainActivity_jniVariableStateMent(JNIEnv *env, jobject thiz) {


}