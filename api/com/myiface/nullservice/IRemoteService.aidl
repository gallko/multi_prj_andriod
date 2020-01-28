// IRemoteService.aidl
package com.myiface.nullservice;

import com.myiface.nullservice.IRemoteServiceListener;
import com.myiface.nullservice.Option;

/** Example service interface */
interface IRemoteService {
    /** Request the name of this service. */
    String getNameService();

    /**
    * Long time request
    * @param option
    *           Option for calculated.
    * @param listener
    *           The listener for result.
    * @type Request
    */
    oneway void getBigData(in Option option, IRemoteServiceListener listener);
}
