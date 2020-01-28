#pragma once

#include "aidl/com/myiface/nullservice/IRemoteService.h"

#include <android/binder_ibinder.h>

namespace aidl {
namespace com {
namespace myiface {
namespace nullservice {
class BnRemoteService : public ::ndk::BnCInterface<IRemoteService> {
public:
  BnRemoteService();
  virtual ~BnRemoteService();
protected:
  ::ndk::SpAIBinder createBinder() override;
private:
};
}  // namespace nullservice
}  // namespace myiface
}  // namespace com
}  // namespace aidl
