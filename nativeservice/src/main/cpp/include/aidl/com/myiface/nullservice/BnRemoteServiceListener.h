#pragma once

#include "aidl/com/myiface/nullservice/IRemoteServiceListener.h"

#include <android/binder_ibinder.h>

namespace aidl {
namespace com {
namespace myiface {
namespace nullservice {
class BnRemoteServiceListener : public ::ndk::BnCInterface<IRemoteServiceListener> {
public:
  BnRemoteServiceListener();
  virtual ~BnRemoteServiceListener();
protected:
  ::ndk::SpAIBinder createBinder() override;
private:
};
}  // namespace nullservice
}  // namespace myiface
}  // namespace com
}  // namespace aidl
