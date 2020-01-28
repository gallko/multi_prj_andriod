#pragma once

#include <android/binder_interface_utils.h>

#include <android/binder_parcel_utils.h>

namespace aidl {
namespace com {
namespace myiface {
namespace nullservice {
class IEResultQuery : public ::ndk::ICInterface {
public:
  static const char* descriptor;
  IEResultQuery();
  virtual ~IEResultQuery();


  enum : int32_t {
    OK = 0,
    ERROR = -1,
  };

  static std::shared_ptr<IEResultQuery> fromBinder(const ::ndk::SpAIBinder& binder);
  static binder_status_t writeToParcel(AParcel* parcel, const std::shared_ptr<IEResultQuery>& instance);
  static binder_status_t readFromParcel(const AParcel* parcel, std::shared_ptr<IEResultQuery>* instance);
  static bool setDefaultImpl(std::shared_ptr<IEResultQuery> impl);
  static const std::shared_ptr<IEResultQuery>& getDefaultImpl();
private:
  static std::shared_ptr<IEResultQuery> default_impl;
};
class IEResultQueryDefault : public IEResultQuery {
public:
  ::ndk::SpAIBinder asBinder() override;
  bool isRemote() override;
};
}  // namespace nullservice
}  // namespace myiface
}  // namespace com
}  // namespace aidl
