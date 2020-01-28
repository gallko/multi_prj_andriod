#include "RemoteService.h"
#include <aidl/com/myiface/nullservice/EResultQuery.h>
#include <aidl/com/myiface/nullservice/BnEResultQuery.h>
#include <aidl/com/myiface/nullservice/BpEResultQuery.h>
#include <aidl/com/myiface/nullservice/BpRemoteServiceListener.h>
#include <aidl/com/myiface/nullservice/BnRemoteServiceListener.h>

#include <thread>
#include <chrono>


ndk::ScopedAStatus RemoteService::getNameService(std::string *_aidl_return) {
    *_aidl_return = std::string("Hello native service");

    return ndk::ScopedAStatus(AStatus_newOk());
}

ndk::ScopedAStatus
RemoteService::getBigData(const ::aidl::com::myiface::nullservice::Option &in_option,
                          const std::shared_ptr<::aidl::com::myiface::nullservice::IRemoteServiceListener> &in_listener) {
    using namespace ::aidl::com::myiface::nullservice;
    __android_log_print(ANDROID_LOG_DEBUG, "RUSLAN", "Native getBigData(%s, %d, %f)", in_option.name.data(), in_option.count, in_option.accuracy);

    std::thread thread([in_listener]() {
        std::this_thread::sleep_for(std::chrono::seconds(2));
        in_listener->faild(std::string{"Opps... "} + std::to_string(in_listener.use_count()));
    });

    thread.detach();

    ::ndk::ScopedAStatus _aidl_status;
    _aidl_status.set(AStatus_fromStatus(STATUS_OK));
    return _aidl_status;
}
