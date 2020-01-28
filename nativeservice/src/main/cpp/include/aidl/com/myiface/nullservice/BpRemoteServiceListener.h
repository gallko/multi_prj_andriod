#pragma once

#include "aidl/com/myiface/nullservice/IRemoteServiceListener.h"

#include <android/binder_ibinder.h>

namespace aidl {
namespace com {
namespace myiface {
namespace nullservice {
class BpRemoteServiceListener : public ::ndk::BpCInterface<IRemoteServiceListener> {
public:
  BpRemoteServiceListener(const ::ndk::SpAIBinder& binder);
  virtual ~BpRemoteServiceListener();

  ::ndk::ScopedAStatus success(const std::vector<::aidl::com::myiface::nullservice::Location>& in_points) override;
  ::ndk::ScopedAStatus faild(const std::string& in_why) override;
};
}  // namespace nullservice
}  // namespace myiface
}  // namespace com
}  // namespace aidl
