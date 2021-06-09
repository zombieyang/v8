#include "src/objects/objects-inl.h"

namespace v8 {
namespace internal {


// enum JsValueType
// {
//     NullOrUndefined = 1,
//     BigInt = 2,
//     Number = 4,
//     String = 8,
//     Boolean = 16,
//     NativeObject = 32,
//     JsObject = 64,
//     Array = 128,
//     Function = 256,
//     Date = 512,
//     ArrayBuffer = 1024,
//     Unknow = 2048,
//     Any = NullOrUndefined | BigInt | Number | String | Boolean | NativeObject | Array | Function | Date | ArrayBuffer,
// };

// #pragma pack(8)
// union ValueUnion
// {
//     double Number;
//     bool Boolean;
//     int64_t BigInt;
//     void* Pointer;
// };

// struct CSharpToJsValue
// {
//     JsValueType Type;
//     int classIDOrValueLength;
//     ValueUnion Data;
// };
#pragma pack()

typedef int(*PuertsCSharpFunction)(v8::Local<Value>* value, int32_t ParamLen, int64_t UserData);

// class Puerts {
// public:
//     static JSValueType getJSValueType(Handle<Object> Value) {
//         if (Value.is_null()) return JSValueType::NullOrUndefined;

//         if (Value->IsNullOrUndefined())
//         {
//             return JSValueType::NullOrUndefined;
//         }
//         else if (Value->IsBigInt())
//         {
//             return JSValueType::BigInt;
//         }
//         else if (Value->IsNumber())
//         {
//             return JSValueType::Number;
//         }
//         else if (Value->IsString() || Value->IsRegExp())
//         {
//             return JSValueType::String;
//         }
//         else if (Value->IsBoolean())
//         {
//             return JSValueType::Boolean;
//         }
//         else if (Value->IsFunction())
//         {
//             return JSValueType::Function;
//         }
//         else if (Value->IsDate())
//         {
//             return JSValueType::Date;
//         }
//         else if (Value->IsArrayBufferView() || Value->IsArrayBuffer())
//         {
//             return JSValueType::ArrayBuffer;
//         }
//         else if (Value->IsObject())
//         {
//             // auto Object = Value->ToObject(Context).ToLocalChecked();
//             // if (Object->InternalFieldCount() == 3 && (intptr_t)Object->GetAlignedPointerFromInternalField(2) == OBJECT_MAGIC)
//             // {
//             //     return JSValueType::NativeObject;
//             // }
//             // else
//             // { 
//             //     return JSValueType::JsObject;
//             // }
//         }
//         else
//         {
//             return JSValueType::Unknow;
//         }
        
//     }
//     static CSharpToJsValue handleArg(Handle<Object> arg) {
//         CSharpToJsValue value;
//         value.Type = getJSValueType(arg);
//         switch(value.Type) {
//             case JSValueType::BigInt:
//             case JSValueType::Number:
//                 value.Data.Number = arg->Number();
//                 break;
//             case JSValueType::String:
//             case JSValueType::Boolean:
//                 value.Data.Boolean = arg->Boolean();
//                 break;
//             case JSValueType::Function:
//             case JSValueType::Date:
//             case JSValueType::ArrayBuffer:
//         }
//     }
// }

}
}
