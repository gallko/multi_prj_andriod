#pragma once

#include "aidl/com/myiface/nullservice/IRemoteService.h"

#include <android/binder_ibinder.h>

namespace aidl {
namespace com {
namespace myiface {
namespace nullservice {
class BpRemoteService : public ::ndk::BpCInterface<IRemoteService> {
public:
  BpRemoteService(const ::ndk::SpAIBinder& binder);
  virtual ~BpRemoteService();

  ::ndk::ScopedAStatus getNameService(std::string* _aidl_return) override;
  ::ndk::ScopedAStatus getBigData(const ::aidl::com::myiface::nullservice::Option& in_option, const std::shared_ptr<::aidl::com::myiface::nullservice::IRemoteServiceListener>& in_listener) override;
};
}  // namespace nullservice
}  // namespace myiface
}  // namespace com
}  // namespace aidl
