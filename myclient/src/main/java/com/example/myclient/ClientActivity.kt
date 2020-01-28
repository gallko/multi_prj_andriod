package com.example.myclient

import android.content.ComponentName
import android.content.Context
import android.content.Intent
import android.content.ServiceConnection
import android.os.Bundle
import android.os.IBinder
import android.util.Log
import android.widget.Button
import androidx.appcompat.app.AppCompatActivity
import com.myiface.nullservice.IRemoteService
import com.myiface.nullservice.IRemoteServiceListener
import com.myiface.nullservice.Location
import com.myiface.nullservice.Option


class ClientActivity : AppCompatActivity() {
    private var start_button: Button? = null
    private var stop_button: Button? = null
    private val intentNative = Intent()
    private var iRemoteService: IRemoteService? = null
    private var mConnection: ServiceConnection? = null

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_main)

        intentNative.action = IRemoteService::class.java.name
        intentNative.component = ComponentName(
            "com.example.nativeservice",
            "com.example.nativeservice.NativeService"
        )


        start_button = findViewById(R.id.button_start)
        start_button!!.setOnClickListener {
            if (iRemoteService == null) {

                mConnection = object : ServiceConnection {
                    override fun onServiceDisconnected(name: ComponentName?) {
                        Log.e("RUSLAN", "Service has unexpectedly disconnected")
                        iRemoteService = null
                    }

                    override fun onServiceConnected(name: ComponentName?, service: IBinder?) {
                        iRemoteService = IRemoteService.Stub.asInterface(service)
                        Log.e(
                            "RUSLAN",
                            "Service connected ${name!!.packageName}.${name.className}, ${iRemoteService?.nameService}"
                        )

                        val opt = Option()
                        opt.accuracy = 0.6
                        opt.count = 20
                        opt.name = "Hello"

                        Log.e(
                            "RUSLAN",
                            "call getBigData"
                        )
                        iRemoteService?.getBigData(opt, object : IRemoteServiceListener.Stub() {
                            override fun faild(why: String?) {
                                Log.e(
                                    "RUSLAN",
                                    "getBigData.faild($why)"
                                )
                            }

                            override fun success(points: Array<out Location>?) {
                                Log.e(
                                    "RUSLAN",
                                    "getBigData.success()"
                                )
                            }
                        })


                    }
                }


                bindService(intentNative, mConnection!!, BIND_AUTO_CREATE or BIND_DEBUG_UNBIND)
            }
        }
        stop_button = findViewById(R.id.button_stop)
        stop_button!!.setOnClickListener {
            if (iRemoteService != null) {
                unbindService(mConnection!!)
                iRemoteService = null
                mConnection = null
                Log.e("RUSLAN", "Service unbind")
            }
        }
    }

//        override fun onServiceDisconnected(name: ComponentName?) {
//            Log.e("RUSLAN", "Service has unexpectedly disconnected")
//            iRemoteService = null
//        }
//
//        override fun onServiceConnected(name: ComponentName?, service: IBinder?) {
//            iRemoteService = IRemoteService.Stub.asInterface(service)
//            Log.e(
//                "RUSLAN",
//                "Service connected ${name!!.packageName}.${name.className}, ${iRemoteService?.nameService}"
//            )
//
//            val opt = Option()
//            opt.accuracy = 0.6
//            opt.count = 20
//            opt.name = "Hello"
//
//            Log.e(
//                "RUSLAN",
//                "call getBigData"
//            )
//            iRemoteService?.getBigData(opt, object : IRemoteServiceListener.Stub() {
//                override fun faild(why: String?) {
//                    Log.e(
//                        "RUSLAN",
//                        "getBigData.faild($why)"
//                    )
//                }
//
//                override fun success(points: Array<out Location>?) {
//                    Log.e(
//                        "RUSLAN",
//                        "getBigData.success()"
//                    )
//                }
//            })
//
//
//        }
//    }
}
