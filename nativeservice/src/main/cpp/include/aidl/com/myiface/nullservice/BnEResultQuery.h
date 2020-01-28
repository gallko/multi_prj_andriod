#pragma once

#include "aidl/com/myiface/nullservice/EResultQuery.h"

#include <android/binder_ibinder.h>

namespace aidl {
namespace com {
namespace myiface {
namespace nullservice {
class BnEResultQuery : public ::ndk::BnCInterface<IEResultQuery> {
public:
  BnEResultQuery();
  virtual ~BnEResultQuery();
protected:
  ::ndk::SpAIBinder createBinder() override;
private:
};
}  // namespace nullservice
}  // namespace myiface
}  // namespace com
}  // namespace aidl
