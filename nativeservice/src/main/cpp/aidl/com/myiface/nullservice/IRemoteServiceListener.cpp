#include <aidl/com/myiface/nullservice/BpRemoteServiceListener.h>
#include <aidl/com/myiface/nullservice/BnRemoteServiceListener.h>
#include <aidl/com/myiface/nullservice/IRemoteServiceListener.h>
#include <android/log.h>

namespace aidl {
namespace com {
namespace myiface {
namespace nullservice {
static binder_status_t _aidl_onTransact(AIBinder* _aidl_binder, transaction_code_t _aidl_code, const AParcel* _aidl_in, AParcel* _aidl_out) {
  (void)_aidl_in;
  (void)_aidl_out;
  binder_status_t _aidl_ret_status = STATUS_UNKNOWN_TRANSACTION;
  std::shared_ptr<BnRemoteServiceListener> _aidl_impl = std::static_pointer_cast<BnRemoteServiceListener>(::ndk::ICInterface::asInterface(_aidl_binder));
  switch (_aidl_code) {
    case (FIRST_CALL_TRANSACTION + 0 /*success*/): {
      std::vector<::aidl::com::myiface::nullservice::Location> in_points;

      _aidl_ret_status = ::ndk::AParcel_readVector(_aidl_in, &in_points);
      if (_aidl_ret_status != STATUS_OK) break;

      ::ndk::ScopedAStatus _aidl_status = _aidl_impl->success(in_points);
      _aidl_ret_status = AParcel_writeStatusHeader(_aidl_out, _aidl_status.get());
      if (_aidl_ret_status != STATUS_OK) break;

      if (!AStatus_isOk(_aidl_status.get())) break;

      break;
    }
    case (FIRST_CALL_TRANSACTION + 1 /*faild*/): {
      std::string in_why;

      _aidl_ret_status = ::ndk::AParcel_readString(_aidl_in, &in_why);
      if (_aidl_ret_status != STATUS_OK) break;

      ::ndk::ScopedAStatus _aidl_status = _aidl_impl->faild(in_why);
      _aidl_ret_status = AParcel_writeStatusHeader(_aidl_out, _aidl_status.get());
      if (_aidl_ret_status != STATUS_OK) break;

      if (!AStatus_isOk(_aidl_status.get())) break;

      break;
    }
  }
  return _aidl_ret_status;
};

static AIBinder_Class* _g_aidl_clazz = ::ndk::ICInterface::defineClass(IRemoteServiceListener::descriptor, _aidl_onTransact);

BpRemoteServiceListener::BpRemoteServiceListener(const ::ndk::SpAIBinder& binder) : BpCInterface(binder) {}
BpRemoteServiceListener::~BpRemoteServiceListener() {}

::ndk::ScopedAStatus BpRemoteServiceListener::success(const std::vector<::aidl::com::myiface::nullservice::Location>& in_points) {
  binder_status_t _aidl_ret_status = STATUS_OK;
  ::ndk::ScopedAStatus _aidl_status;
  ::ndk::ScopedAParcel _aidl_in;
  ::ndk::ScopedAParcel _aidl_out;

  _aidl_ret_status = AIBinder_prepareTransaction(asBinder().get(), _aidl_in.getR());
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = ::ndk::AParcel_writeVector(_aidl_in.get(), in_points);
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = AIBinder_transact(
    asBinder().get(),
    (FIRST_CALL_TRANSACTION + 0 /*success*/),
    _aidl_in.getR(),
    _aidl_out.getR(),
    0);
  if (_aidl_ret_status == STATUS_UNKNOWN_TRANSACTION && IRemoteServiceListener::getDefaultImpl()) {
    return IRemoteServiceListener::getDefaultImpl()->success(in_points);
  }
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = AParcel_readStatusHeader(_aidl_out.get(), _aidl_status.getR());
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  if (!AStatus_isOk(_aidl_status.get())) return _aidl_status;

  _aidl_error:
  _aidl_status.set(AStatus_fromStatus(_aidl_ret_status));
  return _aidl_status;
}
::ndk::ScopedAStatus BpRemoteServiceListener::faild(const std::string& in_why) {
  binder_status_t _aidl_ret_status = STATUS_OK;
  ::ndk::ScopedAStatus _aidl_status;
  ::ndk::ScopedAParcel _aidl_in;
  ::ndk::ScopedAParcel _aidl_out;

  _aidl_ret_status = AIBinder_prepareTransaction(asBinder().get(), _aidl_in.getR());
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = ::ndk::AParcel_writeString(_aidl_in.get(), in_why);
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = AIBinder_transact(
    asBinder().get(),
    (FIRST_CALL_TRANSACTION + 1 /*faild*/),
    _aidl_in.getR(),
    _aidl_out.getR(),
    0);
  if (_aidl_ret_status == STATUS_UNKNOWN_TRANSACTION && IRemoteServiceListener::getDefaultImpl()) {
    return IRemoteServiceListener::getDefaultImpl()->faild(in_why);
  }
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = AParcel_readStatusHeader(_aidl_out.get(), _aidl_status.getR());
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  if (!AStatus_isOk(_aidl_status.get())) return _aidl_status;

  _aidl_error:
  _aidl_status.set(AStatus_fromStatus(_aidl_ret_status));
  return _aidl_status;
}
// Source for BnRemoteServiceListener
BnRemoteServiceListener::BnRemoteServiceListener() {}
BnRemoteServiceListener::~BnRemoteServiceListener() {}
::ndk::SpAIBinder BnRemoteServiceListener::createBinder() {
  AIBinder* binder = AIBinder_new(_g_aidl_clazz, static_cast<void*>(this));
  return ::ndk::SpAIBinder(binder);
}
// Source for IRemoteServiceListener
const char* IRemoteServiceListener::descriptor = "com.myiface.nullservice.IRemoteServiceListener";
IRemoteServiceListener::IRemoteServiceListener() {}
IRemoteServiceListener::~IRemoteServiceListener() {}


std::shared_ptr<IRemoteServiceListener> IRemoteServiceListener::fromBinder(const ::ndk::SpAIBinder& binder) {
  if (!AIBinder_associateClass(binder.get(), _g_aidl_clazz)) { return nullptr; }
  std::shared_ptr<::ndk::ICInterface> interface = ::ndk::ICInterface::asInterface(binder.get());
  if (interface) {
    return std::static_pointer_cast<IRemoteServiceListener>(interface);
  }
  return (new BpRemoteServiceListener(binder))->ref<IRemoteServiceListener>();
}

binder_status_t IRemoteServiceListener::writeToParcel(AParcel* parcel, const std::shared_ptr<IRemoteServiceListener>& instance) {
  return AParcel_writeStrongBinder(parcel, instance ? instance->asBinder().get() : nullptr);
}
binder_status_t IRemoteServiceListener::readFromParcel(const AParcel* parcel, std::shared_ptr<IRemoteServiceListener>* instance) {
  ::ndk::SpAIBinder binder;
  binder_status_t status = AParcel_readStrongBinder(parcel, binder.getR());
  if (status != STATUS_OK) return status;
  *instance = IRemoteServiceListener::fromBinder(binder);
  return STATUS_OK;
}
bool IRemoteServiceListener::setDefaultImpl(std::shared_ptr<IRemoteServiceListener> impl) {
  if (!IRemoteServiceListener::default_impl && impl) {
    IRemoteServiceListener::default_impl = impl;
    return true;
  }
  return false;
}
const std::shared_ptr<IRemoteServiceListener>& IRemoteServiceListener::getDefaultImpl() {
  return IRemoteServiceListener::default_impl;
}
std::shared_ptr<IRemoteServiceListener> IRemoteServiceListener::default_impl = nullptr;
::ndk::ScopedAStatus IRemoteServiceListenerDefault::success(const std::vector<::aidl::com::myiface::nullservice::Location>& /*in_points*/) {
  ::ndk::ScopedAStatus _aidl_status;
  _aidl_status.set(AStatus_fromStatus(STATUS_UNKNOWN_TRANSACTION));
  return _aidl_status;
}
::ndk::ScopedAStatus IRemoteServiceListenerDefault::faild(const std::string& /*in_why*/) {
  ::ndk::ScopedAStatus _aidl_status;
  _aidl_status.set(AStatus_fromStatus(STATUS_UNKNOWN_TRANSACTION));
  return _aidl_status;
}
::ndk::SpAIBinder IRemoteServiceListenerDefault::asBinder() {
  return ::ndk::SpAIBinder();
}
bool IRemoteServiceListenerDefault::isRemote() {
  return false;
}
}  // namespace nullservice
}  // namespace myiface
}  // namespace com
}  // namespace aidl
