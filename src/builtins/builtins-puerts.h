#include "src/objects/objects-inl.h"

namespace v8 {
namespace internal {
  typedef int (*PuertsCallbackFunction)(Local<Value>* value, int ParamLen, void* callbackInfo);
  
  typedef int (*V8GenericCallbackFunction)(Local<Value>* value, int ParamLen, int callbackID);
}
}
