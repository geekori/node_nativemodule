#include <node.h>

namespace demo {
using v8::FunctionCallbackInfo;
using v8::Isolate;
using v8::Local;
using v8::Object;
using v8::String;
using v8::Value;

void getValue(const FunctionCallbackInfo<Value>& args) {
    Isolate* isolate = args.GetIsolate();
    args.GetReturnValue().Set(String::NewFromUtf8(isolate,"<这是我的第一个Node.js扩展>"));
}

void init(Local<Object> exports) {
    NODE_SET_METHOD(exports,"getValue",getValue);
    // require
}

NODE_MODULE(addon,init)


}