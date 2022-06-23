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
    // 方法编写
}

extern "C"
JNIEXPORT void JNICALL
Java_com_zqf_jniseries_MainActivity_stringFromJNI2(JNIEnv *env, jobject thiz) {
    // ndk 反射修改java层的变量textStr的数据
    jclass mainActivityClass = env->GetObjectClass(thiz);
    jfieldID jtext = env->GetFieldID(mainActivityClass, "textStr", "Ljava/lang/String;");
    jstring jstr = env->NewStringUTF("Native层修改java层初始化数据了");
    env->SetObjectField(thiz, jtext, jstr);
}

extern "C"
JNIEXPORT void JNICALL
Java_com_zqf_jniseries_MainActivity_stringFromJNI3(JNIEnv *env, jobject thiz) {
    // ndk 反射修改java层的变量textStr的数据
    jclass mainActivityClass = env->GetObjectClass(thiz);
    jmethodID jmethodId = env->GetMethodID(mainActivityClass, "fun3NativeToJava", "()V");
    env->CallVoidMethod(thiz, jmethodId);
}