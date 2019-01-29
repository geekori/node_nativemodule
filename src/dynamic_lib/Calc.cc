//  本地模块

#include <node.h>
#include <dlfcn.h>
namespace demo {

using v8::Exception;
using v8::FunctionCallbackInfo;
using v8::Isolate;
using v8::Local;
using v8::Number;
using v8::Object;
using v8::String;
using v8::Value;


void* handle;
    //  定义函数指针变量
double (*add)(double, double);
double (*sub)(double, double);
double (*mul)(double, double);
double (*div)(double, double);

void Add(const FunctionCallbackInfo<Value>& args) {
  Isolate* isolate = args.GetIsolate();
  double result = add(args[0]->NumberValue(),args[1]->NumberValue());
  Local<Number> num = Number::New(isolate, result);
  args.GetReturnValue().Set(num);
}
void Sub(const FunctionCallbackInfo<Value>& args) {
  Isolate* isolate = args.GetIsolate();
  double result = sub(args[0]->NumberValue(),args[1]->NumberValue());
  Local<Number> num = Number::New(isolate, result);
  args.GetReturnValue().Set(num);
}
void Mul(const FunctionCallbackInfo<Value>& args) {
  Isolate* isolate = args.GetIsolate();
  double result = mul(args[0]->NumberValue(),args[1]->NumberValue());
  Local<Number> num = Number::New(isolate, result);
  args.GetReturnValue().Set(num);
}
void Div(const FunctionCallbackInfo<Value>& args) {
  Isolate* isolate = args.GetIsolate();
  double result = div(args[0]->NumberValue(),args[1]->NumberValue());
  Local<Number> num = Number::New(isolate, result);
  args.GetReturnValue().Set(num);
}
void init(Local<Object> exports) {
    //  装载动态链接库
    handle = dlopen("Calc.so",RTLD_LAZY);

    //  开始装载动态链接库中的函数
    add = (double (*)(double, double))dlsym(handle,"add");
    sub = (double (*)(double, double))dlsym(handle,"sub");
    mul = (double (*)(double, double))dlsym(handle,"mul");
    div = (double (*)(double, double))dlsym(handle,"div");
   NODE_SET_METHOD(exports, "add", Add);
   NODE_SET_METHOD(exports, "sub", Sub);
   NODE_SET_METHOD(exports, "mul", Mul);
   NODE_SET_METHOD(exports, "div", Div);
}

NODE_MODULE(addon, init)

}
