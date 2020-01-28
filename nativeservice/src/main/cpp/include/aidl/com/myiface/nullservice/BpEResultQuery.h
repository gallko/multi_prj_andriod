#pragma once

#include "aidl/com/myiface/nullservice/EResultQuery.h"

#include <android/binder_ibinder.h>

namespace aidl {
namespace com {
namespace myiface {
namespace nullservice {
class BpEResultQuery : public ::ndk::BpCInterface<IEResultQuery> {
public:
  BpEResultQuery(const ::ndk::SpAIBinder& binder);
  virtual ~BpEResultQuery();

};
}  // namespace nullservice
}  // namespace myiface
}  // namespace com
}  // namespace aidl
