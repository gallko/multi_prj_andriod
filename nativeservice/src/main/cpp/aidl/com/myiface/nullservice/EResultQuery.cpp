#include <aidl/com/myiface/nullservice/BpEResultQuery.h>
#include <aidl/com/myiface/nullservice/BnEResultQuery.h>
#include <aidl/com/myiface/nullservice/EResultQuery.h>

namespace aidl {
namespace com {
namespace myiface {
namespace nullservice {
static binder_status_t _aidl_onTransact(AIBinder* _aidl_binder, transaction_code_t _aidl_code, const AParcel* _aidl_in, AParcel* _aidl_out) {
  (void)_aidl_in;
  (void)_aidl_out;
  binder_status_t _aidl_ret_status = STATUS_UNKNOWN_TRANSACTION;
  (void)_aidl_binder;
  (void)_aidl_code;
  return _aidl_ret_status;
};

static AIBinder_Class* _g_aidl_clazz = ::ndk::ICInterface::defineClass(IEResultQuery::descriptor, _aidl_onTransact);

BpEResultQuery::BpEResultQuery(const ::ndk::SpAIBinder& binder) : BpCInterface(binder) {}
BpEResultQuery::~BpEResultQuery() {}

// Source for BnEResultQuery
BnEResultQuery::BnEResultQuery() {}
BnEResultQuery::~BnEResultQuery() {}
::ndk::SpAIBinder BnEResultQuery::createBinder() {
  AIBinder* binder = AIBinder_new(_g_aidl_clazz, static_cast<void*>(this));
  return ::ndk::SpAIBinder(binder);
}
// Source for IEResultQuery
const char* IEResultQuery::descriptor = "com.myiface.nullservice.EResultQuery";
IEResultQuery::IEResultQuery() {}
IEResultQuery::~IEResultQuery() {}


std::shared_ptr<IEResultQuery> IEResultQuery::fromBinder(const ::ndk::SpAIBinder& binder) {
  if (!AIBinder_associateClass(binder.get(), _g_aidl_clazz)) { return nullptr; }
  std::shared_ptr<::ndk::ICInterface> interface = ::ndk::ICInterface::asInterface(binder.get());
  if (interface) {
    return std::static_pointer_cast<IEResultQuery>(interface);
  }
  return (new BpEResultQuery(binder))->ref<IEResultQuery>();
}

binder_status_t IEResultQuery::writeToParcel(AParcel* parcel, const std::shared_ptr<IEResultQuery>& instance) {
  return AParcel_writeStrongBinder(parcel, instance ? instance->asBinder().get() : nullptr);
}
binder_status_t IEResultQuery::readFromParcel(const AParcel* parcel, std::shared_ptr<IEResultQuery>* instance) {
  ::ndk::SpAIBinder binder;
  binder_status_t status = AParcel_readStrongBinder(parcel, binder.getR());
  if (status != STATUS_OK) return status;
  *instance = IEResultQuery::fromBinder(binder);
  return STATUS_OK;
}
bool IEResultQuery::setDefaultImpl(std::shared_ptr<IEResultQuery> impl) {
  if (!IEResultQuery::default_impl && impl) {
    IEResultQuery::default_impl = impl;
    return true;
  }
  return false;
}
const std::shared_ptr<IEResultQuery>& IEResultQuery::getDefaultImpl() {
  return IEResultQuery::default_impl;
}
std::shared_ptr<IEResultQuery> IEResultQuery::default_impl = nullptr;
::ndk::SpAIBinder IEResultQueryDefault::asBinder() {
  return ::ndk::SpAIBinder();
}
bool IEResultQueryDefault::isRemote() {
  return false;
}
}  // namespace nullservice
}  // namespace myiface
}  // namespace com
}  // namespace aidl
