package com.zqf.jniseries

import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import android.view.View
import android.widget.TextView
import android.widget.Toast
import com.zqf.jniseries.databinding.ActivityMainBinding

class MainActivity : AppCompatActivity() {

    //静态方法 类似java 的 static{}
    companion object {
        init {
            System.loadLibrary("native-lib")
        }
    }

    private lateinit var binding: ActivityMainBinding

    private var textStr = "java层初始化的值"

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        binding = ActivityMainBinding.inflate(layoutInflater)
        setContentView(binding.root)
    }

    fun fun1click(view: View) {
        binding.sampleText.text = stringFromJNI()
    }

    fun fun2click(view: View) {
        stringFromJNI2()
        binding.sampleText.text = textStr
    }

    fun fun3click(view: View) {
        stringFromJNI3()
    }

    fun fun3NativeToJava() {
        Toast.makeText(this, "Native调Java的函数了", Toast.LENGTH_SHORT).show()
    }

    //java 调 native 函数
    external fun stringFromJNI(): String

    //native 调java 变量并修改
    external fun stringFromJNI2()

    //native 调java 函数
    external fun stringFromJNI3()
}