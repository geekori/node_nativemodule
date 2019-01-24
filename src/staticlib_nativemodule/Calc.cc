//  本地模块

#include <node.h>
#include "./cpp/Calc.h"
namespace demo {

using v8::Exception;
using v8::FunctionCallbackInfo;
using v8::Isolate;
using v8::Local;
using v8::Number;
using v8::Object;
using v8::String;
using v8::Value;


void Add(const FunctionCallbackInfo<Value>& args) {
  Isolate* isolate = args.GetIsolate();
  double result = Calc::add(args[0]->NumberValue(),args[1]->NumberValue());
  Local<Number> num = Number::New(isolate, result);
  args.GetReturnValue().Set(num);
}
void Sub(const FunctionCallbackInfo<Value>& args) {
  Isolate* isolate = args.GetIsolate();
  double result = Calc::sub(args[0]->NumberValue(),args[1]->NumberValue());
  Local<Number> num = Number::New(isolate, result);
  args.GetReturnValue().Set(num);
}
void Mul(const FunctionCallbackInfo<Value>& args) {
  Isolate* isolate = args.GetIsolate();
  double result = Calc::mul(args[0]->NumberValue(),args[1]->NumberValue());
  Local<Number> num = Number::New(isolate, result);
  args.GetReturnValue().Set(num);
}
void Div(const FunctionCallbackInfo<Value>& args) {
  Isolate* isolate = args.GetIsolate();
  double result = Calc::div(args[0]->NumberValue(),args[1]->NumberValue());
  Local<Number> num = Number::New(isolate, result);
  args.GetReturnValue().Set(num);
}
void init(Local<Object> exports) {

   NODE_SET_METHOD(exports, "add", Add);
   NODE_SET_METHOD(exports, "sub", Sub);
   NODE_SET_METHOD(exports, "mul", Mul);
   NODE_SET_METHOD(exports, "div", Div);
}

NODE_MODULE(addon, init)

}
