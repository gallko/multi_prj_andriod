#pragma once

#include <android/binder_interface_utils.h>

#include <android/binder_parcel_utils.h>
#include <aidl/com/myiface/nullservice/IRemoteServiceListener.h>
#include <aidl/com/myiface/nullservice/Option.h>

namespace aidl {
namespace com {
namespace myiface {
namespace nullservice {
class IRemoteService : public ::ndk::ICInterface {
public:
  static const char* descriptor;
  IRemoteService();
  virtual ~IRemoteService();



  static std::shared_ptr<IRemoteService> fromBinder(const ::ndk::SpAIBinder& binder);
  static binder_status_t writeToParcel(AParcel* parcel, const std::shared_ptr<IRemoteService>& instance);
  static binder_status_t readFromParcel(const AParcel* parcel, std::shared_ptr<IRemoteService>* instance);
  static bool setDefaultImpl(std::shared_ptr<IRemoteService> impl);
  static const std::shared_ptr<IRemoteService>& getDefaultImpl();
  virtual ::ndk::ScopedAStatus getNameService(std::string* _aidl_return) = 0;
  virtual ::ndk::ScopedAStatus getBigData(const ::aidl::com::myiface::nullservice::Option& in_option, const std::shared_ptr<::aidl::com::myiface::nullservice::IRemoteServiceListener>& in_listener) = 0;
private:
  static std::shared_ptr<IRemoteService> default_impl;
};
class IRemoteServiceDefault : public IRemoteService {
public:
  ::ndk::ScopedAStatus getNameService(std::string* _aidl_return) override;
  ::ndk::ScopedAStatus getBigData(const ::aidl::com::myiface::nullservice::Option& in_option, const std::shared_ptr<::aidl::com::myiface::nullservice::IRemoteServiceListener>& in_listener) override;
  ::ndk::SpAIBinder asBinder() override;
  bool isRemote() override;
};
}  // namespace nullservice
}  // namespace myiface
}  // namespace com
}  // namespace aidl
