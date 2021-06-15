#include "src/objects/objects-inl.h"

namespace v8 {
namespace internal {
  typedef int (*PuertsCallbackFunction)(const FunctionCallbackInfo<Value> &info, void* callbackInfo);
  
  struct PuertsCallbackHandler {
    PuertsCallbackFunction callback;
    void* callbackInfo;
  };
}
}
