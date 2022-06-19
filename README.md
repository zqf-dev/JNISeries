# JNISeries
Android JNI系列学习Demo，入门最佳宝藏笔记

## JNI （Java Native Interface）

- 提供一种Java字节码调用C/C++的解决方案，JNI描述的是一种技术

### Java和Native之间基本数据类型转换

| Java类型 | JNI类型 |
| :--------: | :-------: |
|	byte |	jbyte	|
|	char |	jchar	|
|	short |	jshort	|
|	int |	jint	|
|	long |	jlong	|
|	float |	jfloat	|
|	double |	jdouble	|
|	boolean |	jboolean	|

### Java和Native之间引用数据类型转换

| Java类型 | JNI 类型 |
| :--------: | :--------: |
| All objects | jobject |
| java.lang.String | jstring |
| java.lang.Class | jclass |
| java.lang.Throwable | jthrowable |
| Object[ ] | jobjectArray[ ] |
| boolean[ ] | jbooleanArray[ ] |
| byte[ ] | jbyteArray[ ] |
| char[ ] | jcharArray[ ] |
| short[ ] | jshortArray[ ] |
| int[ ] | jintArray[ ] |
| long[ ] | jlongArray[ ] |
| float[ ] | jfloatArray[ ] |
| double[ ] | jdoubleArray[ ] |

