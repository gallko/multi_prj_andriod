#pragma once

#include <android/binder_interface_utils.h>

#include <android/binder_parcel_utils.h>
#include <aidl/com/myiface/nullservice/Location.h>

namespace aidl {
namespace com {
namespace myiface {
namespace nullservice {
class IRemoteServiceListener : public ::ndk::ICInterface {
public:
  static const char* descriptor;
  IRemoteServiceListener();
  virtual ~IRemoteServiceListener();



  static std::shared_ptr<IRemoteServiceListener> fromBinder(const ::ndk::SpAIBinder& binder);
  static binder_status_t writeToParcel(AParcel* parcel, const std::shared_ptr<IRemoteServiceListener>& instance);
  static binder_status_t readFromParcel(const AParcel* parcel, std::shared_ptr<IRemoteServiceListener>* instance);
  static bool setDefaultImpl(std::shared_ptr<IRemoteServiceListener> impl);
  static const std::shared_ptr<IRemoteServiceListener>& getDefaultImpl();
  virtual ::ndk::ScopedAStatus success(const std::vector<::aidl::com::myiface::nullservice::Location>& in_points) = 0;
  virtual ::ndk::ScopedAStatus faild(const std::string& in_why) = 0;
private:
  static std::shared_ptr<IRemoteServiceListener> default_impl;
};
class IRemoteServiceListenerDefault : public IRemoteServiceListener {
public:
  ::ndk::ScopedAStatus success(const std::vector<::aidl::com::myiface::nullservice::Location>& in_points) override;
  ::ndk::ScopedAStatus faild(const std::string& in_why) override;
  ::ndk::SpAIBinder asBinder() override;
  bool isRemote() override;
};
}  // namespace nullservice
}  // namespace myiface
}  // namespace com
}  // namespace aidl
