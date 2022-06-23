#include "com_zqf_jniseries_JNIImpl.h"
JNIEXPORT jint JNICALL Java_com_zqf_jniseries_JNIImpl_add
        (JNIEnv * env, jobject obj, jint x, jint y){
    return x+y;
}