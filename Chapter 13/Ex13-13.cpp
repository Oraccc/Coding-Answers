#include <iostream>
#include <vector>

using namespace std;

struct X
{
    X() {cout << "X() called" << endl;}
    X(const X&) {cout << "X(const X&) called" << endl;}
    X &operator=(const X &) {cout << "operator= called" << endl;}
    ~X() {cout << "~X() called" << endl;}
};

void f1(X x) {}
void f2(X &x) {}
X f3() {return X();}
X &f4(X &x) {return x;}
X f5() {X x; return x;}

int main() {
    cout << "\n----- X x1;\n";
    X x1;

    cout << "\n----- f1(x1);\n";
    f1(x1);

    cout << "\n----- f2(x1);\n";
    f2(x1);

    cout << "\n----- X x3 = f3();\n";
    X x3 = f3();

    cout << "\n----- f3();\n";
    f3();

    cout << "\n----- X x4 = f4(x1);\n";
    X x4 = f4(x1);

    cout << "\n----- f4(x1);\n";
    f4(x1);

    cout << "\n----- X x5 = f5();\n";
    X x5 = f5();

    cout << "\n----- f5();\n";
    f5();

    cout << "\n----- X *x2 = new X;\n";
    X *x2 = new X;

    cout << "\n----- vector<X> vx;\n";
    vector<X> vx;

    cout << "\n----- vx.push_back(x1);\n";
    vx.push_back(x1);

    cout << "\n----- vx.push_back(*x2);\n";
    vx.push_back(*x2);

    cout << "\n----- delete x2;\n";
    delete x2;

    return 0;
}