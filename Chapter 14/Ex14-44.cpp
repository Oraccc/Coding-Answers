#include <functional>
#include <iostream>
#include <map>
#include <string>

using namespace std;

int add(int a, int b) {
  return a + b;
}

struct multiple {
  int operator()(int a, int b) { return a * b; }
};

auto divide = [](int a, int b) { return a / b; };

int main() {
    map<string, function<int (int, int)>> ops = {
        { "+", add },
        { "-", minus<int>() },
        { "*", multiple() },
        { "/", divide },
        { "%", [](int a, int b) { return a % b; } }
    };

    int a, b;
    string op;
    do {
        cout << "Enter expression: ";
        cin >> a >> op >> b;
        auto it = ops.find(op);
        if (it != ops.end())
        cout << it->second(a, b) << endl;
        else
        cout << "Unrecognized operator: " << op << endl;
    } while (cin);

    return 0;
}