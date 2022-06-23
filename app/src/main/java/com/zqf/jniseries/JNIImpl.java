package com.zqf.jniseries;

public class JNIImpl {

    static {
        System.loadLibrary("bridge");
    }

    public native int add(int x, int y);

    public static void main(String[] args) {
        JNIImpl jniImpl = new JNIImpl();
        System.out.println("native C++: >> " + jniImpl.add(1, 2));
    }
}
