package com.zqf.jniseries

import android.content.Intent
import android.os.Bundle
import android.util.Log
import android.view.View
import android.widget.Toast
import androidx.appcompat.app.AppCompatActivity
import com.zqf.jniseries.databinding.ActivityMainBinding
import com.zqf.jniseries.gif.GifActivity

class MainActivity : AppCompatActivity() {

    //静态方法 类似java 的 static{}
    companion object {
        init {
            // System.loadLibrary("Test")
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

    fun fun4click(view: View) {
        dataTypeToNative(
            true,
            1,
            2.toChar(),
            3.toShort(),
            3,
            4L,
            5.0f,
            6.60,
            "Hello",
            intArrayOf(1, 2, 3),
            arrayOf<String>("哈哈", "走你", "测试"),
            booleanArrayOf(true, false),
            User(20220720, "张三", 28, true)
        )
    }

    private var count: Int = 0
    fun fun5click(view: View) {
        for (i in 1..10) {
            Thread {
                countNum()
                threadHandle()
            }.start()
        }
    }

    private fun countNum() {
        synchronized(this) {
            count++
            Log.e("Java", "count:>> $count")
        }
    }

    fun fun6click(view: View) {
        startActivity(Intent(this, GifActivity::class.java))
    }

    //java 调 native 函数
    external fun stringFromJNI(): String

    //native 调java 变量并修改
    external fun stringFromJNI2()

    //native 调java 函数
    external fun stringFromJNI3()

    //java 传递各种数据类型到native
    external fun dataTypeToNative(
        bl: Boolean,
        bt: Byte,
        c: Char,
        s: Short,
        i: Int,
        l: Long,
        f: Float,
        d: Double,
        str: String,
        intArray: IntArray,
        strArray: Array<String>,
        booleanArray: BooleanArray,
        user: User,
    )

    //JNI线程操作
    external fun threadHandle()

    external fun testCmake()
}