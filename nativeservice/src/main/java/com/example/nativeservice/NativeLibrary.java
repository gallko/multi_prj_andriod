package com.example.nativeservice;
import android.os.IBinder;

public final class NativeLibrary {
    public static native IBinder getNativeBinderJNI(String action);
    public static native void releaseNativeBinderJNI(IBinder binder);

    public static void loadLibrary(){
        System.loadLibrary("native-lib");
    }
}
