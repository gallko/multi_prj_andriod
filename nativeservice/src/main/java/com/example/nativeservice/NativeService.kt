package com.example.nativeservice

import android.app.Service
import android.content.Intent
import android.os.IBinder
import android.util.Log
import com.example.nativeservice.NativeLibrary.releaseNativeBinderJNI

class NativeService : Service() {
    init {
        NativeLibrary.loadLibrary()
    }

    override fun onBind(intent: Intent): IBinder? {
        return NativeLibrary.getNativeBinderJNI(intent.action)
    }

    override fun onUnbind(intent: Intent?): Boolean {
        Log.e("RUSLAN", "NativeService onUnbind")
        return super.onUnbind(intent)
    }

    override fun onDestroy() {
        super.onDestroy()
        Log.e("RUSLAN", "NativeService onDestroy")
    }
}
