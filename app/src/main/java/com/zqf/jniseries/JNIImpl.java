package com.zqf.jniseries;

public class JNIImpl {

    static {
        System.load("D:\\opensource_workspace\\JNISeries\\app\\src\\main\\java\\demo.dll");
    }

    public static native int add(int x, int y);

    public static void main(String[] args) {
        JNIImpl jniImpl = new JNIImpl();
        System.out.printf("%d\n", jniImpl.add(10, 2));
    }
}
