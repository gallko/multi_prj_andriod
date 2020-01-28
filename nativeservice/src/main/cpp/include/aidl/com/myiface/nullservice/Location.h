#pragma once
#include <android/binder_interface_utils.h>

#include <android/binder_parcel_utils.h>
namespace aidl {
namespace com {
namespace myiface {
namespace nullservice {
class Location {
public:
  static const char* descriptor;

  int32_t longitude;
  int32_t latitude;

  binder_status_t readFromParcel(const AParcel* parcel);
  binder_status_t writeToParcel(AParcel* parcel) const;
};
}  // namespace nullservice
}  // namespace myiface
}  // namespace com
}  // namespace aidl
