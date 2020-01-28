// IRemoteServiceListener.aidl
package com.myiface.nullservice;

import com.myiface.nullservice.Location;

// Declare any non-default types here with import statements

interface IRemoteServiceListener {
    /**
     * Demonstrates some basic types that you can use as parameters
     * and return values in AIDL.
     */
    void success(in Location[] points);
    void faild(in String why);
}
