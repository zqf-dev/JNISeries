#include <jni.h>
#include <string>
//c++ iostream
#include <iostream>
//导入ndk打印日志
#include <android/log.h>
//定义日志打印的参数
#define TAG "native-lib"
// __VA_ARGS__ 代表 ...的可变参数
#define LOGD(...) __android_log_print(ANDROID_LOG_DEBUG,TAG,__VA_ARGS__);
#define LOGE(...) __android_log_print(ANDROID_LOG_ERROR,TAG,__VA_ARGS__);
#define LOGI(...) __android_log_print(ANDROID_LOG_INFO,TAG,__VA_ARGS__);

extern "C" JNIEXPORT jstring JNICALL
Java_com_zqf_jniseries_MainActivity_stringFromJNI(JNIEnv *env, jobject /* this */) {
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

// 数据类型展示
extern "C" JNIEXPORT void JNICALL
Java_com_zqf_jniseries_MainActivity_dataTypeToNative(JNIEnv *env, jobject thiz, jboolean bl,
                                                     jbyte bt, jchar c, jshort s, jint i, jlong l,
                                                     jfloat f, jdouble d, jstring str,
                                                     jintArray int_array, jobjectArray str_array,
                                                     jbooleanArray boolean_array, jobject user) {
    //1. 接收 Java 传递过来的 boolean 值
    unsigned char n_boolean = bl;
    LOGD("jboolean-> %d", n_boolean);

    //1. 接收 Java 传递过来的 byte 值
    char n_byte = bt;
    LOGD("jbyte-> %d", n_byte)

    //3. 接收 Java 传递过来的 char 值
    unsigned short n_char = c;
    LOGD("jchar-> %d", n_char)

    //4. 接收 Java 传递过来的 short 值
    short n_short = s;
    LOGD("jshort-> %d", n_short)

    //5、接收 Java 传递过来的 int 值
    int int_java = i;
    LOGD("jint-> %d", int_java)

    //6、接收 Java 传递过来的 long 值
    long long_java = l;
    LOGD("jlong-> %ld", long_java)

    //7、接收 Java 传递过来的 float 值
    float f_float = f;
    LOGD("float-> %f", f_float);

    //8、接收 Java 传递过来的 double 值
    double d_java = d;
    LOGD("double-> %f", d_java);

    //9、接收 Java 传递过来的 String 值
    const char *n_str = env->GetStringUTFChars(str, nullptr);
    LOGD("string-> %s", n_str);

    //10、接收 Java 传递过来的 int[] 值
    jint *n_intArray = env->GetIntArrayElements(int_array, nullptr);
    jsize n_size = env->GetArrayLength(int_array);
    for (int m = 0; m < n_size; ++m) {
        LOGD("n_intArray-> %d", n_intArray[m])
    }
    //释放数组
    env->ReleaseIntArrayElements(int_array, n_intArray, 0);

    //11、打印 Java 传递过来的 String[]
    jsize strArrayLength = env->GetArrayLength(str_array);
    for (int sk = 0; sk < strArrayLength; ++sk) {
        jobject obj = env->GetObjectArrayElement(str_array, sk);
        jstring stringArrayData = static_cast<jstring>(obj);
        const char *log_str = env->GetStringUTFChars(stringArrayData, nullptr);
        LOGD("String[%d]: -> %s", sk, log_str)
        //释放string[]
        env->ReleaseStringUTFChars(stringArrayData, log_str);
    }

    //12、打印 Java 传递过来的 booleanArray
    jboolean *bArray = env->GetBooleanArrayElements(boolean_array, nullptr);
    jsize blArrayLength = env->GetArrayLength(boolean_array);
    for (int la = 0; la < blArrayLength; ++la) {
        jboolean b2 = bArray[la];
        LOGD("jboolean:%d", b2)
    }
    env->ReleaseBooleanArrayElements(boolean_array, bArray, 0);

    //13、打印 Java 传递过来的 Object 对象
    // 拿到User类引用
    jclass userCls = env->GetObjectClass(user);
    if (userCls == nullptr) {
        LOGE("GetObjectClass obj_stu failed")
        return;
    }
    // 获得属性ID
    jfieldID idFieldID = env->GetFieldID(userCls, "id", "J");
    jfieldID nameFieldID = env->GetFieldID(userCls, "name", "Ljava/lang/String;");
    jfieldID ageFieldID = env->GetFieldID(userCls, "age", "I");
    jfieldID stayFieldID = env->GetFieldID(userCls, "stay", "Z");
    jlong id = env->GetLongField(user, idFieldID);
    LOGD("user id->: %lld", id);
    jstring name = static_cast<jstring>(env->GetObjectField(user, nameFieldID));
    const char *n_name = env->GetStringUTFChars(name, nullptr);
    LOGD("user name->: %s", n_name);
    jint age = env->GetIntField(user, ageFieldID);
    LOGD("user age->: %d", age);
    jboolean stay = env->GetBooleanField(user, stayFieldID);
    LOGD("user stay->: %s", stay ? "true" : "false");
    // 释放string引用
    env->ReleaseStringUTFChars(name, n_name);
    // 回收
    env->DeleteLocalRef(userCls);
    // 回收
    env->DeleteLocalRef(user);
}