// Location.aidl
package com.myiface.nullservice;

// Declare any non-default types here with import statements

parcelable Location {

    /**
     * Longitude in Wgs84 represented by mapping decimal degree to max uint32.
     * <p>
     * Value Range: int
     */
    int longitude;

    /**
     * Latitude in Wgs84 represented by mapping decimal degree to max uint32.
     * <p>
     * Value Range: int
     */
    int latitude;
}
