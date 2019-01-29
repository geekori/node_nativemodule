#include <dlfcn.h>
#include <iostream>

using namespace std;

int main(int argc, char* argv[])
{
    double a = 12;
    double b = 43;

    //  装载动态链接库
    void* handle = dlopen("Calc.so",RTLD_LAZY);

    //  定义函数指针变量
    double (*add)(double, double);
    double (*sub)(double, double);
    double (*mul)(double, double);
    double (*div)(double, double);

    //  开始装载动态链接库中的函数
    add = (double (*)(double, double))dlsym(handle,"add");
    sub = (double (*)(double, double))dlsym(handle,"sub");
    mul = (double (*)(double, double))dlsym(handle,"mul");
    div = (double (*)(double, double))dlsym(handle,"div");

    //  调用动态链接库中的函数
    cout << "a + b = " << add(a,b) << endl;
    cout << "a - b = " << sub(a,b) << endl;
    cout << "a * b = " << mul(a,b) << endl;
    cout << "a / b = " << div(a,b) << endl;

    return 0;
}