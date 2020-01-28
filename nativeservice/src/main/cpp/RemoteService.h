//
// Created by RYunusov on 22.01.2020.
//

#ifndef MULTI_PROJECT_REMOTESERVICE_H
#define MULTI_PROJECT_REMOTESERVICE_H

#include <android/log.h>
#include <aidl/com/myiface/nullservice/BnRemoteService.h>

class RemoteService : public aidl::com::myiface::nullservice::BnRemoteService {
public:
    RemoteService() = default;
    virtual ~RemoteService() = default;

    ndk::ScopedAStatus getNameService(std::string *_aidl_return) override;

    ndk::ScopedAStatus getBigData(const ::aidl::com::myiface::nullservice::Option &in_option,
                                  const std::shared_ptr<::aidl::com::myiface::nullservice::IRemoteServiceListener> &in_listener) override;
};

#endif //MULTI_PROJECT_REMOTESERVICE_H
