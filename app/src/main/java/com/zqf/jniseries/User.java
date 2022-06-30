package com.zqf.jniseries;

/**
 * Author: zqf
 * Date: 2022/06/30
 */
public class User {

    private long id;
    private String name;
    private int age;
    private boolean stay;

    public User(long id, String name, int age, boolean stay) {
        this.id = id;
        this.name = name;
        this.age = age;
        this.stay = stay;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public int getAge() {
        return age;
    }

    public void setAge(int age) {
        this.age = age;
    }

}
