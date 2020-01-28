#include "aidl/com/myiface/nullservice/Location.h"


namespace aidl {
namespace com {
namespace myiface {
namespace nullservice {
const char* Location::descriptor = "com.myiface.nullservice.Location";

binder_status_t Location::readFromParcel(const AParcel* parcel) {
  std::string _aidl_descriptor;
  binder_status_t _aidl_ret_status;
  int32_t _aidl_null;
  int32_t _aidl_parcelable_size;
  int32_t _aidl_start_pos;
  _aidl_ret_status = AParcel_readInt32(parcel, &_aidl_null);
  if (_aidl_ret_status != STATUS_OK) return _aidl_ret_status;

  _aidl_start_pos = AParcel_getDataPosition(parcel);
  _aidl_ret_status = AParcel_readInt32(parcel, &_aidl_parcelable_size);
  if (_aidl_parcelable_size < 0) return STATUS_BAD_VALUE;
  if (_aidl_ret_status != STATUS_OK) return _aidl_ret_status;

  if (_aidl_null == 0) return STATUS_UNEXPECTED_NULL;

  _aidl_ret_status = AParcel_readInt32(parcel, &longitude);
  if (_aidl_ret_status != STATUS_OK) return _aidl_ret_status;

  if (AParcel_getDataPosition(parcel) - _aidl_start_pos >= _aidl_parcelable_size) {
    AParcel_setDataPosition(parcel, _aidl_start_pos + _aidl_parcelable_size);
    return _aidl_ret_status;
  }
  _aidl_ret_status = AParcel_readInt32(parcel, &latitude);
  if (_aidl_ret_status != STATUS_OK) return _aidl_ret_status;

  if (AParcel_getDataPosition(parcel) - _aidl_start_pos >= _aidl_parcelable_size) {
    AParcel_setDataPosition(parcel, _aidl_start_pos + _aidl_parcelable_size);
    return _aidl_ret_status;
  }
  AParcel_setDataPosition(parcel, _aidl_start_pos + _aidl_parcelable_size);
  return _aidl_ret_status;
}
binder_status_t Location::writeToParcel(AParcel* parcel) const {
  binder_status_t _aidl_ret_status;
  _aidl_ret_status = AParcel_writeInt32(parcel, 1);
  if (_aidl_ret_status != STATUS_OK) return _aidl_ret_status;

  size_t _aidl_start_pos = AParcel_getDataPosition(parcel);
  _aidl_ret_status = AParcel_writeInt32(parcel, 0);
  if (_aidl_ret_status != STATUS_OK) return _aidl_ret_status;

  _aidl_ret_status = AParcel_writeInt32(parcel, longitude);
  if (_aidl_ret_status != STATUS_OK) return _aidl_ret_status;

  _aidl_ret_status = AParcel_writeInt32(parcel, latitude);
  if (_aidl_ret_status != STATUS_OK) return _aidl_ret_status;

  size_t _aidl_end_pos = AParcel_getDataPosition(parcel);
  AParcel_setDataPosition(parcel, _aidl_start_pos);
  AParcel_writeInt32(parcel, _aidl_end_pos - _aidl_start_pos);
  AParcel_setDataPosition(parcel, _aidl_end_pos);
  return _aidl_ret_status;
}

}  // namespace nullservice
}  // namespace myiface
}  // namespace com
}  // namespace aidl
