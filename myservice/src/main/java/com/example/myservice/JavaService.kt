package com.example.myservice

import android.app.Service
import android.content.Intent
import android.os.IBinder
import android.util.Log
import com.myiface.nullservice.IRemoteService

class JavaService : Service() {

    override fun onCreate() {
        Log.d("RUSLAN", "call JavaService.onCreate()")
        super.onCreate()
    }

    override fun onBind(intent: Intent): IBinder {
        Log.d("RUSLAN", "call JavaService.onBind()")
        return binder
    }

    private val binder = object : IRemoteService.Stub() {
        override fun getNameService(): String {
            Log.d("RUSLAN", "call JavaService.getNameService()")
            return "Hello JavaService"
        }
    }
}
