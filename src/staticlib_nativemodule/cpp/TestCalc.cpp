#include "Calc.h"
#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {
    double a = 22;
    double b = 6;

    cout << "a + b = " << Calc::add(a,b) << endl;
    cout << "a - b = " << Calc::sub(a,b) << endl;
    cout << "a * b = " << Calc::mul(a,b) << endl;
    cout << "a / b = " << Calc::div(a,b) << endl;
    return 0;
}