package com.zqf.jniseries.gif;

import android.annotation.SuppressLint;
import android.graphics.Bitmap;
import android.os.Bundle;
import android.os.Environment;
import android.os.Handler;
import android.os.Message;
import android.util.Log;
import android.widget.ImageView;

import androidx.annotation.Nullable;
import androidx.appcompat.app.AppCompatActivity;

import com.hjq.permissions.OnPermissionCallback;
import com.hjq.permissions.Permission;
import com.hjq.permissions.XXPermissions;
import com.zqf.jniseries.R;

import java.io.File;
import java.util.List;

/**
 * Author: zqf
 * Date: 2022/06/27
 * Gif图 ndk 加载页
 */
public class GifActivity extends AppCompatActivity {

    static {
        System.loadLibrary("native-lib");
    }

    private ImageView gifImg;
    private GifHandler gifHandler;
    private Bitmap bitmap;

    @SuppressLint("HandlerLeak")
    Handler mHandler = new Handler() {
        public void handleMessage(Message msg) {
            int delay = gifHandler.updateFrame(bitmap);
            mHandler.sendEmptyMessageDelayed(1, delay);
            gifImg.setImageBitmap(bitmap);
        }
    };

    @Override
    protected void onCreate(@Nullable Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        gifImg = findViewById(R.id.gif_iv);
        setContentView(R.layout.gif_layout);
        permissionHandle();
    }

    private void permissionHandle() {
        XXPermissions.with(this)
                .permission(Permission.WRITE_EXTERNAL_STORAGE
                        , Permission.READ_EXTERNAL_STORAGE)
                .request(new OnPermissionCallback() {
                    @Override
                    public void onGranted(List<String> permissions, boolean all) {
                        if (all) gifLoad();
                    }

                    @Override
                    public void onDenied(List<String> permissions, boolean never) {
                        if (never) {
                            // 永久拒绝就跳转到应用权限系统设置页面
                            XXPermissions.startPermissionActivity(GifActivity.this, permissions);
                        }
                    }
                });
    }

    private void gifLoad() {
        File file = new File(Environment.getExternalStorageDirectory(), "demo.gif");
        gifHandler = GifHandler.load(file.getAbsolutePath());
        int width = gifHandler.getWidth();
        int height = gifHandler.getHeight();
        Log.e("Gif-->", "宽   " + width + "   高  " + height);
        bitmap = Bitmap.createBitmap(width, height, Bitmap.Config.ARGB_8888);
        //通知C渲染完成
        int delay = gifHandler.updateFrame(bitmap);
        gifImg.setImageBitmap(bitmap);
        mHandler.sendEmptyMessageDelayed(1, delay);
    }
}
