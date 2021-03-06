#pragma once
#include <android/binder_interface_utils.h>

#include <android/binder_parcel_utils.h>
namespace aidl {
namespace com {
namespace myiface {
namespace nullservice {
class Option {
public:
  static const char* descriptor;

  std::string name;
  int32_t count;
  double accuracy;

  binder_status_t readFromParcel(const AParcel* parcel);
  binder_status_t writeToParcel(AParcel* parcel) const;
};
}  // namespace nullservice
}  // namespace myiface
}  // namespace com
}  // namespace aidl
