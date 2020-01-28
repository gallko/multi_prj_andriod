#include <aidl/com/myiface/nullservice/BpRemoteService.h>
#include <aidl/com/myiface/nullservice/BnRemoteService.h>
#include <aidl/com/myiface/nullservice/IRemoteService.h>
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
  std::shared_ptr<BnRemoteService> _aidl_impl = std::static_pointer_cast<BnRemoteService>(::ndk::ICInterface::asInterface(_aidl_binder));
  switch (_aidl_code) {
    case (FIRST_CALL_TRANSACTION + 0 /*getNameService*/): {
      std::string _aidl_return;

      ::ndk::ScopedAStatus _aidl_status = _aidl_impl->getNameService(&_aidl_return);
      _aidl_ret_status = AParcel_writeStatusHeader(_aidl_out, _aidl_status.get());
      if (_aidl_ret_status != STATUS_OK) break;

      if (!AStatus_isOk(_aidl_status.get())) break;

      _aidl_ret_status = ::ndk::AParcel_writeString(_aidl_out, _aidl_return);
      if (_aidl_ret_status != STATUS_OK) break;

      break;
    }
    case (FIRST_CALL_TRANSACTION + 1 /*getBigData*/): {
      ::aidl::com::myiface::nullservice::Option in_option;
      std::shared_ptr<::aidl::com::myiface::nullservice::IRemoteServiceListener> in_listener;

      _aidl_ret_status = (&in_option)->readFromParcel(_aidl_in);
      if (_aidl_ret_status != STATUS_OK) break;

      _aidl_ret_status = ::aidl::com::myiface::nullservice::IRemoteServiceListener::readFromParcel(_aidl_in, &in_listener);
      if (_aidl_ret_status != STATUS_OK) break;

      ::ndk::ScopedAStatus _aidl_status = _aidl_impl->getBigData(in_option, in_listener);
      _aidl_ret_status = STATUS_OK;
      break;
    }
  }
  return _aidl_ret_status;
};

static AIBinder_Class* _g_aidl_clazz = ::ndk::ICInterface::defineClass(IRemoteService::descriptor, _aidl_onTransact);

BpRemoteService::BpRemoteService(const ::ndk::SpAIBinder& binder) : BpCInterface(binder) {}
BpRemoteService::~BpRemoteService() {}

::ndk::ScopedAStatus BpRemoteService::getNameService(std::string* _aidl_return) {
  binder_status_t _aidl_ret_status = STATUS_OK;
  ::ndk::ScopedAStatus _aidl_status;
  ::ndk::ScopedAParcel _aidl_in;
  ::ndk::ScopedAParcel _aidl_out;

  _aidl_ret_status = AIBinder_prepareTransaction(asBinder().get(), _aidl_in.getR());
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = AIBinder_transact(
    asBinder().get(),
    (FIRST_CALL_TRANSACTION + 0 /*getNameService*/),
    _aidl_in.getR(),
    _aidl_out.getR(),
    0);
  if (_aidl_ret_status == STATUS_UNKNOWN_TRANSACTION && IRemoteService::getDefaultImpl()) {
    return IRemoteService::getDefaultImpl()->getNameService(_aidl_return);
  }
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = AParcel_readStatusHeader(_aidl_out.get(), _aidl_status.getR());
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  if (!AStatus_isOk(_aidl_status.get())) return _aidl_status;

  _aidl_ret_status = ::ndk::AParcel_readString(_aidl_out.get(), _aidl_return);
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_error:
  _aidl_status.set(AStatus_fromStatus(_aidl_ret_status));
  return _aidl_status;
}
::ndk::ScopedAStatus BpRemoteService::getBigData(const ::aidl::com::myiface::nullservice::Option& in_option, const std::shared_ptr<::aidl::com::myiface::nullservice::IRemoteServiceListener>& in_listener) {
  binder_status_t _aidl_ret_status = STATUS_OK;
  ::ndk::ScopedAStatus _aidl_status;
  ::ndk::ScopedAParcel _aidl_in;
  ::ndk::ScopedAParcel _aidl_out;

  _aidl_ret_status = AIBinder_prepareTransaction(asBinder().get(), _aidl_in.getR());
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = (in_option).writeToParcel(_aidl_in.get());
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = ::aidl::com::myiface::nullservice::IRemoteServiceListener::writeToParcel(_aidl_in.get(), in_listener);
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = AIBinder_transact(
    asBinder().get(),
    (FIRST_CALL_TRANSACTION + 1 /*getBigData*/),
    _aidl_in.getR(),
    _aidl_out.getR(),
    FLAG_ONEWAY);
  if (_aidl_ret_status == STATUS_UNKNOWN_TRANSACTION && IRemoteService::getDefaultImpl()) {
    return IRemoteService::getDefaultImpl()->getBigData(in_option, in_listener);
  }
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_error:
  _aidl_status.set(AStatus_fromStatus(_aidl_ret_status));
  return _aidl_status;
}
// Source for BnRemoteService
BnRemoteService::BnRemoteService() {
  __android_log_print(ANDROID_LOG_DEBUG, "RUSLAN", "BnRemoteService()");
}
BnRemoteService::~BnRemoteService() {
  __android_log_print(ANDROID_LOG_DEBUG, "RUSLAN", "~BnRemoteService()");
}
::ndk::SpAIBinder BnRemoteService::createBinder() {
  AIBinder* binder = AIBinder_new(_g_aidl_clazz, static_cast<void*>(this));
  return ::ndk::SpAIBinder(binder);
}
// Source for IRemoteService
const char* IRemoteService::descriptor = "com.myiface.nullservice.IRemoteService";
IRemoteService::IRemoteService() {}
IRemoteService::~IRemoteService() {}


std::shared_ptr<IRemoteService> IRemoteService::fromBinder(const ::ndk::SpAIBinder& binder) {
  if (!AIBinder_associateClass(binder.get(), _g_aidl_clazz)) { return nullptr; }
  std::shared_ptr<::ndk::ICInterface> interface = ::ndk::ICInterface::asInterface(binder.get());
  if (interface) {
    return std::static_pointer_cast<IRemoteService>(interface);
  }
  return (new BpRemoteService(binder))->ref<IRemoteService>();
}

binder_status_t IRemoteService::writeToParcel(AParcel* parcel, const std::shared_ptr<IRemoteService>& instance) {
  return AParcel_writeStrongBinder(parcel, instance ? instance->asBinder().get() : nullptr);
}
binder_status_t IRemoteService::readFromParcel(const AParcel* parcel, std::shared_ptr<IRemoteService>* instance) {
  ::ndk::SpAIBinder binder;
  binder_status_t status = AParcel_readStrongBinder(parcel, binder.getR());
  if (status != STATUS_OK) return status;
  *instance = IRemoteService::fromBinder(binder);
  return STATUS_OK;
}
bool IRemoteService::setDefaultImpl(std::shared_ptr<IRemoteService> impl) {
  if (!IRemoteService::default_impl && impl) {
    IRemoteService::default_impl = impl;
    return true;
  }
  return false;
}
const std::shared_ptr<IRemoteService>& IRemoteService::getDefaultImpl() {
  return IRemoteService::default_impl;
}
std::shared_ptr<IRemoteService> IRemoteService::default_impl = nullptr;
::ndk::ScopedAStatus IRemoteServiceDefault::getNameService(std::string* /*_aidl_return*/) {
  ::ndk::ScopedAStatus _aidl_status;
  _aidl_status.set(AStatus_fromStatus(STATUS_UNKNOWN_TRANSACTION));
  return _aidl_status;
}
::ndk::ScopedAStatus IRemoteServiceDefault::getBigData(const ::aidl::com::myiface::nullservice::Option& /*in_option*/, const std::shared_ptr<::aidl::com::myiface::nullservice::IRemoteServiceListener>& /*in_listener*/) {
  ::ndk::ScopedAStatus _aidl_status;
  _aidl_status.set(AStatus_fromStatus(STATUS_UNKNOWN_TRANSACTION));
  return _aidl_status;
}
::ndk::SpAIBinder IRemoteServiceDefault::asBinder() {
  return ::ndk::SpAIBinder();
}
bool IRemoteServiceDefault::isRemote() {
  return false;
}
}  // namespace nullservice
}  // namespace myiface
}  // namespace com
}  // namespace aidl
